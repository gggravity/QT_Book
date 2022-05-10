//
// Created by martin on 10-05-22.
//

#include "Q_runner_progress.h"
#include "Worker_2.h"

Q_runner_progress::Q_runner_progress (QWidget *parent)
  {
    auto layout = new QVBoxLayout();
    progress_bar = new QProgressBar();

    auto button = new QPushButton("START IT UP");
    connect(button, &QPushButton::pressed, this, &Q_runner_progress::execute);

    layout->addWidget(progress_bar);
    layout->addWidget(button);

    auto w = new QWidget();
    w->setLayout(layout);

    setCentralWidget(w);
    show();

    thread_pool = new QThreadPool();
    qInfo() << "Multithreading with maximum" << thread_pool->maxThreadCount() << "threads";
  }

void Q_runner_progress::execute ()
  {
    auto worker = new Worker_2();
    connect(worker, &Worker_2::progress, this, &Q_runner_progress::update_progress);

    thread_pool->start(worker);
  }

void Q_runner_progress::update_progress (int progress)
  {
    progress_bar->setValue(progress);
  }