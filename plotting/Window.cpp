//
// Created by martin on 14-05-22.
//

#include <QLineSeries>
#include <QLegendMarker>
#include <QScatterSeries>
#include <QComboBox>
#include "Window.h"

Window::Window (QWidget *parent)
  {
    setMinimumSize(600, 400);

    auto layout = new QVBoxLayout();

    auto combo_box = new QComboBox(this);
    combo_box->insertItem(0, "The light theme, which is the default theme.");
    combo_box->insertItem(1, "The cerulean blue theme.");
    combo_box->insertItem(2, "The dark theme.");
    combo_box->insertItem(3, "The sand brown theme.");
    combo_box->insertItem(4, "The natural color system (NCS) blue theme.");
    combo_box->insertItem(5, "The high contrast theme.");
    combo_box->insertItem(6, "The icy blue theme.");
    combo_box->insertItem(7, "The Qt theme.");

    connect(combo_box, &QComboBox::currentTextChanged, this, &Window::currentTextChanged);
    connect(combo_box, &QComboBox::currentIndexChanged, this, &Window::currentIndexChanged);

    chart = new QChart();
    chart->setTitle("Line chart");
//    chart->setTitle("<span style=\"color:blue;font-size:30pt\">Your Title Here</span>");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    /** Setting the chart theme */
//    chart->setTheme(QChart::ChartThemeDark);

    auto chart_view = new QChartView(chart);
    chart_view->setRenderHint(QPainter::Antialiasing);

    auto series0 = new QLineSeries();
    auto series1 = new QScatterSeries();

    vector<Data> data { { 1,  30 },
                        { 2,  32 },
                        { 3,  34 },
                        { 4,  32 },
                        { 5,  33 },
                        { 6,  31 },
                        { 7,  29 },
                        { 8,  32 },
                        { 9,  35 },
                        { 10, 45 },
    };

    for (auto d : data)
      {
        series0->append(d.hour, d.temperature);
        series1->append(d.hour, d.temperature);
      }

    chart->addSeries(series0);
    chart->addSeries(series1);

    /** Name the series */
    series0->setName("Line serie");
    series1->setName("Scatter serie");

    /** legends */

    auto markers_list = chart->legend()->markers();

    for (auto marker : markers_list)
      {
        if (marker->series()->name() == "Scatter serie")
          {
            marker->setVisible(false);
          }
      }

    //    chart->legend()->hide();
    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->createDefaultAxes(); // need to be after the serie have been added.

    /** get a pointer to the axis */
    auto x_axis = chart->axes(Qt::Horizontal).back();
    auto y_axis = chart->axes(Qt::Vertical).back();

    /** set the range of the axis */
    x_axis->setRange(0, 11);
    y_axis->setRange(0, 50);

    /** set the axis titles */
    x_axis->setTitleText("Hour");
    y_axis->setTitleText("Temperature (°C)");

    /** set the charts background brush */
//    auto brush = QBrush(Qt::lightGray);
//    chart->setBackgroundBrush(brush);

    /** set the charts background pen */
//    auto pen = QPen(Qt::darkBlue);
//    chart->setBackgroundPen(pen);

    /** set a custom pen for the lineserie */
//    auto series_pen = QPen(Qt::darkBlue);
//    series_pen.setStyle(Qt::DashDotLine);
//    series_pen.setWidth(10);
//    series0->setPen(series_pen);

//    series->setPointLabelsVisible(true);    // is false by default
//    series->setPointLabelsColor(Qt::black);
//    series->setPointLabelsFormat("@yPoint");
//    auto font = QFont("Arial", 20);
//    series->setPointLabelsFont(font);

    /** set the marker types for the scatter serie. */
    series1->setMarkerShape(QScatterSeries::MarkerShapeStar);
    series1->setMarkerSize(20.0);

    layout->addWidget(combo_box);
    layout->addWidget(chart_view);

    auto widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);

  }

void Window::currentTextChanged (const QString &text)
  {
    qInfo() << text;
  }

void Window::currentIndexChanged (int index)
  {
    switch (index)
      {
        case 0:
          chart->setTheme(QChart::ChartThemeLight);
          break;
        case 1:
          chart->setTheme(QChart::ChartThemeBlueCerulean);
          break;
        case 2:
          chart->setTheme(QChart::ChartThemeDark);
          break;
        case 3:
          chart->setTheme(QChart::ChartThemeBrownSand);
          break;
        case 4:
          chart->setTheme(QChart::ChartThemeBlueNcs);
          break;
        case 5:
          chart->setTheme(QChart::ChartThemeHighContrast);
          break;
        case 6:
          chart->setTheme(QChart::ChartThemeBlueIcy);
          break;
        case 7:
          chart->setTheme(QChart::ChartThemeQt);
          break;
        default:
          break;
      }
  }
