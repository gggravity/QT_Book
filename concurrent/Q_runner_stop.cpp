//
// Created by martin on 13-05-22.
//

#include "Q_runner_stop.h"
#include "Job_runner_1.h"
#include <QStatusBar>

Q_runner_stop::Q_runner_stop (QWidget *parent)
  {
    // Some buttons
    auto w = new QWidget();
    auto l = new QHBoxLayout();
    w->setLayout(l);

    auto btn_stop = new QPushButton("Stop");
    auto btn_pause = new QPushButton("Pause");
    auto btn_resume = new QPushButton("Resume");

    l->addWidget(btn_stop);
    l->addWidget(btn_pause);
    l->addWidget(btn_resume);
    setCentralWidget(w);

    // Create a statusbar.
    auto status = statusBar();
    progress = new QProgressBar();
    status->addPermanentWidget(progress);

    // Thread runner
    auto thread_pool = new QThreadPool();

    // Create a runner
    auto runner = new Job_runner_1();
    connect(runner, &Job_runner_1::update_progress, this, &Q_runner_stop::update_progress);
    thread_pool->start(runner);

    connect(btn_stop, &QPushButton::pressed, runner, &Job_runner_1::kill);
    connect(btn_pause, &QPushButton::pressed, runner, &Job_runner_1::pause);
    connect(btn_resume, &QPushButton::pressed, runner, &Job_runner_1::resume);

    show();
  }

void Q_runner_stop::update_progress (int n)
  {
    progress->setValue(n);
  }
