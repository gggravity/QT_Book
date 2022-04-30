#include <bits/stdc++.h>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include "Window3.h"
#include "Window5.h"

Window::Window (QWidget *parent) :
    button_is_checked { false }
  {
    setWindowTitle("My App");
    button = new QPushButton("Press Me!");
    button->setCheckable(true);

    srand(time(NULL));

    window_titles.emplace_back("My App");
    window_titles.emplace_back("Still My App");
    window_titles.emplace_back("What on earth");
    window_titles.emplace_back("This is surprising");
    window_titles.emplace_back("Something went wrong");


//    connect(button, &QPushButton::toggled, this, the_button_was_toggled);
//    connect(button, &QPushButton::clicked, this, the_button_was_clicked);
//    connect(button, &QPushButton::released, this, the_button_was_released);

//    connect(button, SIGNAL(clicked()), this, SLOT(the_button_was_clicked()));
//    connect(this, SIGNAL(&QMainWindow::windowTitleChanged()), this, SLOT(the_window_title_changed));
//    connect(button, SIGNAL(toggled()), this, SLOT(the_button_was_toggled()));
//    connect(button, SIGNAL(released()), this, SLOT(the_button_was_released()));

    connect(button, SIGNAL(clicked()), this, SLOT(the_button_was_clicked()));

    connect(this, &QMainWindow::windowTitleChanged, this, the_window_title_changed);

    setFixedSize(QSize(400, 300));

    auto *input = new QLineEdit();
    auto *label = new QLabel();


    connect(input, &QLineEdit::textChanged, label, &QLabel::setText);

    auto *layout = new QVBoxLayout();
    layout->addWidget(input);
    layout->addWidget(label);

    auto *container = new QWidget();

    container->setLayout(layout);

    // Set the central widget of the Window.
    setCentralWidget(container);
  }

void Window::the_button_was_clicked (bool checked)
  {
    button->setText("You already clicked me.");
//    button->setEnabled(false); // Also change the window title.
    auto r = rand() % window_titles.size();
    qDebug() << r;
    setWindowTitle(window_titles.at(r));
  }

void Window::the_button_was_toggled ()
  {
    button_is_checked = !button_is_checked;
    qDebug() << "button_is_checked:" << button_is_checked;
  }

void Window::the_button_was_released ()
  {
    qDebug() << "button_is_checked:" << button->isChecked();
  }

void Window::the_window_title_changed (const QString &title)
  {
//    title = windowTitle();
    qDebug() << "title changed" << title;
  }

Window::~Window ()
= default;
