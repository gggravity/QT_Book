//
// Created by martin on 08-05-22.
//

#include "Power_bar.h"
#include "Bar.h"

Power_bar::Power_bar (int steps, QWidget *parent)
  {
    auto layout = new QVBoxLayout(this);
    auto bar = new Bar(steps,this);
    layout->addWidget(bar);
    dial = new QDial(this);

    connect(dial, &QDial::valueChanged, bar, &Bar::trigger_refresh);

    layout->addWidget(dial);
    setLayout(layout);
  }

Power_bar::Power_bar (const QList<QString>& steps, QWidget *parent)
  {
    auto layout = new QVBoxLayout(this);
    auto bar = new Bar(steps,this);
    layout->addWidget(bar);
    dial = new QDial(this);

    connect(dial, &QDial::valueChanged, bar, &Bar::trigger_refresh);

    layout->addWidget(dial);
    setLayout(layout);
  }

