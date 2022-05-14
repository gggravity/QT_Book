//
// Created by martin on 14-05-22.
//

#include <iostream>
#include "Q_runner_generic.h"
#include "Worker_generic.h"

Q_runner_generic::Q_runner_generic (QWidget *parent)
  {
    auto layout = new QVBoxLayout();
    l = new QLabel("Start");
    auto b = new QPushButton("DANGER!");
    connect(b, &QPushButton::pressed, this, &Q_runner_generic::oh_no);

    layout->addWidget(l);
    layout->addWidget(b);
    auto w = new QWidget();
    w->setLayout(layout);

    setCentralWidget(w);
    show();

    thread_pool = new QThreadPool();
    qInfo() << "Multithreading with maximum" << thread_pool->maxThreadCount() << "threads";

    auto timer = new QTimer();
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &Q_runner_generic::recurring_timer);
    timer->start();
  }

void Q_runner_generic::print_output (const QString &string)
  {
    qInfo() << string;
  }

void Q_runner_generic::thread_complete ()
  {
    qInfo() << "THREAD COMPLETE!";
  }

void Q_runner_generic::oh_no ()
  {
    /// Pass the function to execute
    auto random1 = QRandomGenerator::global()->bounded(10, 50);
    auto random2 = QRandomGenerator::global()->bounded(10, 50);
    auto worker = new Worker_generic(&execute_this_fn, random1, random2);
//    qInfo() << "Worker created.";

    connect(worker, &Worker_generic::result, this, &Q_runner_generic::print_output);
    connect(worker, &Worker_generic::finished, this, &Q_runner_generic::thread_complete);
    connect(worker, &Worker_generic::error, this, &Q_runner_generic::error);

    // Execute
    thread_pool->start(worker);
//    qInfo() << "Worker startet";
  }

void Q_runner_generic::recurring_timer ()
  {
    counter += 1;
    l->setText(QString("Counter: %1").arg(counter));
  }

void Q_runner_generic::error (boost::stacktrace::stacktrace stacktrace)
  {
    cerr << to_string(stacktrace);
  }

QString execute_this_fn (int x, int y)
  {
    for (int i { 0 } ; i < 5 ; ++i)
      {
        usleep(100);
      }
    return QString("Done. (%1)").arg(x + y);
  }
