
#include "Bad_example_1.h"
#include <QString>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>

Bad_example_1::Bad_example_1 (QWidget *parent)
    : QMainWindow(parent)
  {
    auto layout = new QVBoxLayout();
    l = new QLabel("Start", this);
    auto b = new QPushButton("DANGER!", this);

    connect(b, &QPushButton::pressed, this, &Bad_example_1::oh_no);

    layout->addWidget(l);
    layout->addWidget(b);
    auto w = new QWidget(this);
    w->setLayout(layout);
    setCentralWidget(w);
//    show();

    auto timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &Bad_example_1::recurring_timer);
    timer->start();

  }

void Bad_example_1::oh_no ()
  {
    sleep(5);
  }

void Bad_example_1::recurring_timer ()
  {
    counter += 1;
    l->setText(QString("Counter: %1").arg(counter));
  }

Bad_example_1::~Bad_example_1 ()
= default;

