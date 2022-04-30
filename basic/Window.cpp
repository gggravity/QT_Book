#include <QPushButton>
#include "Window.h"

Window::Window (QWidget *parent)
  {
    setWindowTitle("My App");
    auto *button = new QPushButton("Press Me!");
    setFixedSize(QSize(400, 300));

    // Set the central widget of the Window.
    setCentralWidget(button);
  }

Window::~Window ()
  = default;
