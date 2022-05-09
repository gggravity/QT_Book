#pragma once

#include <QMainWindow>
#include <QObject>
#include <QList>
#include <QLabel>
#include <QTimer>
#include <QRunnable>
#include <QThreadPool>
#include <QPushButton>
#include <QVBoxLayout>

class Worker : public QRunnable
      {
      public:
            void run () override
              {
                qInfo() << "Thread start";
                sleep(5);
                qInfo() << "Thread complete";
              }

            ~Worker () override
              = default;
      };

class Q_runner_1 : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Q_runner_1 (QWidget *parent = nullptr)
              {
                thread_pool = new QThreadPool();
                qInfo() << "Multithreading with maximum" << thread_pool->maxThreadCount() << "threads";

                auto layout = new QVBoxLayout();

                l = new QLabel("Start", this);
                auto b = new QPushButton("DANGER!", this);
                connect(b,&QPushButton::pressed,this, &Q_runner_1::oh_no);

                layout->addWidget(l);
                layout->addWidget(b);

                auto w = new QWidget(this);
                w->setLayout(layout);

                setCentralWidget(w);

                show();

                auto timer = new QTimer(this);
                timer->setInterval(1000);
                connect(timer,&QTimer::timeout,this, &Q_runner_1::recurring_timer);
                timer->start();
              };

            ~Q_runner_1 () override
            = default;;

            void oh_no ()
              {
                auto worker = new Worker();
                thread_pool->start(worker);
              }

            void recurring_timer()
              {
                counter++;
                l->setText(QString("Counter: %1").arg(counter));
              }
      private:
            int counter { 0 };
            QLabel *l;
            QThreadPool *thread_pool;
      };