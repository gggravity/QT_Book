#include <bits/stdc++.h>
#include <QPushButton>
#include "Window2.h"
#include <QObject>

Window2::Window2 (QWidget *parent)
  {
    setWindowTitle("My App");
    auto *button = new QPushButton("Press Me!");
    button->setCheckable(true);
//    connect(button, &QPushButton::clicked, [=] ()
//      {
//          cout << "test" << endl;
//      });

    connect(button, &QPushButton::clicked, this, the_button_was_clicked);

//    connect(button, SIGNAL(clicked()), this, SLOT(the_button_was_clicked()));

    setFixedSize(QSize(400, 300));

    // Set the central widget of the Window.
    setCentralWidget(button);
  }

void Window2::the_button_was_clicked ()
  {
    cout << "The button was clicked" << endl;
  }

Window2::~Window2 ()
= default;
