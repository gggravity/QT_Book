//
// Created by martin on 10-05-22.
//
#include "Q_runner_2.h"
#include "Worker_1.h"

Q_runner_2::Q_runner_2 (QWidget *parent)
  {
    thread_pool = new QThreadPool();
    qInfo() << "Multithreading with maximum" << thread_pool->maxThreadCount() << "threads";

    auto layout = new QVBoxLayout();

    l = new QLabel("Start", this);
    auto b = new QPushButton("DANGER!", this);
    connect(b, &QPushButton::pressed, this, &Q_runner_2::oh_no);

    layout->addWidget(l);
    layout->addWidget(b);

    auto w = new QWidget(this);
    w->setLayout(layout);

    setCentralWidget(w);

    show();

    auto timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &Q_runner_2::recurring_timer);
    timer->start();
  }

void Q_runner_2::oh_no ()
  {
//    auto worker = new Worker();
    auto worker = new Worker(QRandomGenerator::global()->bounded(10, 50));
    connect(worker, &Worker::result, this, &Q_runner_2::worker_output);
    connect(worker, &Worker::finished, this, &Q_runner_2::worker_complete);
    connect(worker, &Worker::error, this, &Q_runner_2::worker_error);

    thread_pool->start(worker);
  }

void Q_runner_2::worker_output (const QMap<QString, int>& s)
  {
    qInfo() << "RESULT" << s;
  }

void Q_runner_2::worker_complete ()
  {
    qInfo() << "THREAD COMPLETE!";
  }

void Q_runner_2::worker_error (const QString& t)
  {
    qInfo() << "ERROR:" << t;
  }

void Q_runner_2::recurring_timer ()
  {
    counter++;
    l->setText(QString("Counter: %1").arg(counter));
  }