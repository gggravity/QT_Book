//
// Created by martin on 12-05-22.
//

#include <QChart>
#include <QChartView>
#include "Q_runner_calculator.h"
#include "Worker_4.h"

Q_runner_calculator::Q_runner_calculator (QWidget *parent)
  {
    thread_pool = new QThreadPool();

    auto layout = new QVBoxLayout();
    chart_view = new QChartView();
    chart_view->chart()->setTitle("Line chart");
    layout->addWidget(chart_view);

    auto button = new QPushButton("Create New Worker");
    connect(button, &QPushButton::pressed, this, &Q_runner_calculator::execute);

    layout->addWidget(button);
    auto w = new QWidget();
    w->setLayout(layout);
    setCentralWidget(w);
    show();
  }

void Q_runner_calculator::execute ()
  {
    auto worker = new Worker_4();
    connect(worker, &Worker_4::data, this, &Q_runner_calculator::receive_data);
    // Execute
    thread_pool->start(worker);
  }

void Q_runner_calculator::receive_data (const QString &worker_id, int x, int y)
  {
    if (!lines.contains(worker_id))
      {
        auto series = new QLineSeries();
        chart_view->chart()->addSeries(series);

        // Generate a random color.

        QPen pen { QColor {
            QRandomGenerator::global()->bounded(100, 255),
            QRandomGenerator::global()->bounded(100, 255),
            QRandomGenerator::global()->bounded(100, 255)
        }
        };
        pen.setWidth(2);
        series->setPen(pen);
        series->append(x, y);
        lines[worker_id] = series;

        // series need to be added before axis.
        chart_view->chart()->createDefaultAxes();

        return;
      }

    update_axis_range(x, y);

    // Update existing plot/data
    lines[worker_id]->append(x, y);

  }

void Q_runner_calculator::update_axis_range (int x, int y)
  {

    if (x < axis_range.min_x)
      {
        axis_range.min_x = x;
      }

    if (x > axis_range.max_x)
      {
        axis_range.max_x = x;
      }

    if (y < axis_range.min_y)
      {
        axis_range.min_y = y - 10;
      }

    if (y > axis_range.max_y)
      {
        axis_range.max_y = y + 10;
      }

    chart_view->chart()->axes(Qt::Horizontal).back()->setRange(axis_range.min_x, axis_range.max_x);
    chart_view->chart()->axes(Qt::Vertical).back()->setRange(axis_range.min_y, axis_range.max_y);

  }
