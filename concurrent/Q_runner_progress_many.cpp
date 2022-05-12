//
// Created by martin on 10-05-22.
//

#include <iostream>
#include "Q_runner_progress_many.h"
#include "Worker_3.h"

Q_runner_progress::Q_runner_progress (QWidget *parent)
  {
    auto layout = new QVBoxLayout();
    progress_bar = new QProgressBar();

    auto button = new QPushButton("START IT UP");
    connect(button, &QPushButton::pressed, this, &Q_runner_progress::execute);

    status = new QLabel("0 workers");

    layout->addWidget(status);
    layout->addWidget(progress_bar);
    layout->addWidget(button);

    auto w = new QWidget();
    w->setLayout(layout);

    setCentralWidget(w);
    show();

    thread_pool = new QThreadPool();
    qInfo() << "Multithreading with maximum" << thread_pool->maxThreadCount() << "threads";

    auto timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &Q_runner_progress::refresh_progress);
    timer->start();
  }

void Q_runner_progress::execute ()
  {
    auto worker = new Worker_3();
    connect(worker, &Worker_3::progress, this, &Q_runner_progress::update_progress);
    connect(worker, &Worker_3::finished, this, &Q_runner_progress::cleanup);

    thread_pool->start(worker);
  }

void Q_runner_progress::cleanup (const QString &job_id)
  {
    int total_progress { 0 };

    for (const auto &item : worker_progress)
      {
        total_progress += item.second;
      }

    total_progress /= int(worker_progress.size());

    if (total_progress == 100)
      {
        worker_progress.clear();
      }


//    if (worker_progress.contains(job_id))
//      {
//        worker_progress.erase(job_id);
//        //Update the progress bar if we've removed a value.
//        refresh_progress();
//      }
  }

void Q_runner_progress::update_progress (const QString &job_id, int progress)
  {
    worker_progress[job_id] = progress;
  }

int Q_runner_progress::calculate_progress ()
  {
    if (worker_progress.empty())
      {
        return 0;
      }
    int sum { 0 };
    for (const auto &item : worker_progress)
      {
        sum += item.second;
      }
    auto return_value = sum / int(worker_progress.size());
    return return_value;
  }

void Q_runner_progress::refresh_progress ()
  {
    // Calculate total progress.
    auto progress = calculate_progress();
    progress_bar->setValue(progress);
    status->setText(QString("%1 workers").arg(worker_progress.size()));
  }