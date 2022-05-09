
#include "Bad_example_2.h"
#include <QString>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>
#include <QThread>
#include <unistd.h>
#include <QApplication>

Bad_example_2::Bad_example_2 (QWidget *parent)
    : QMainWindow(parent)
  {
    auto layout = new QVBoxLayout();
    l = new QLabel("Start", this);
    auto b = new QPushButton("DANGER!", this);
    connect(b, &QPushButton::pressed, this, &Bad_example_2::oh_no);

    auto c = new QPushButton("?");
    connect(c, &QPushButton::pressed, this, &Bad_example_2::change_message);

    layout->addWidget(l);
    layout->addWidget(b);
    layout->addWidget(c);

    auto w = new QWidget(this);
    w->setLayout(layout);

    setCentralWidget(w);
//    show();

    auto timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &Bad_example_2::recurring_timer);
    timer->start();

  }

void Bad_example_2::oh_no ()
  {
    message = "Presse";
    for (int i = 0; i < 1000; ++i)
      {
        usleep(10000);
//        QThread::sleep(100);
        l->setText(message);
        QApplication::processEvents();
      }

  }

void Bad_example_2::recurring_timer ()
  {
    counter += 1;
    l->setText(QString("Counter: %1").arg(counter));
  }

void Bad_example_2::change_message ()
  {
    message = "OH NO";
  }

Bad_example_2::~Bad_example_2 ()
= default;

