#include <QVBoxLayout>
#include <QLabel>
#include "anotherwindow.h"

AnotherWindow::AnotherWindow (QWidget *parent) :
    QWidget(parent)
  {

    auto *layout = new QVBoxLayout();

    label = new QLabel("Another window");

    layout->addWidget(label);
    setLayout(layout);
  }

AnotherWindow::~AnotherWindow ()
  = default;
