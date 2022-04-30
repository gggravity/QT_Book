#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include "Window7.h"

Window::Window (QWidget *parent) :
    QMainWindow(parent),
    w { new AnotherWindow() }
  {
    auto *button = new QPushButton("Push for Window");

//    connect(button, &QPushButton::clicked, [this] ()
//      {
//          show_new_window();
//      });

    connect(button, &QPushButton::clicked, [this] ()
      {
          toggle_window();
      });

    auto *input = new QLineEdit();
    connect(input, &QLineEdit::textChanged, w, [this](const QString &text){
          qDebug() << "Text changed.";
          w->label->setText(text);
    });
//    self.input.textChanged.connect(self.w.label.setText)
    auto *layout = new QVBoxLayout();
    layout->addWidget(button);
    layout->addWidget(input);
    auto *container = new QWidget();
    container->setLayout(layout);

    setCentralWidget(container);
  }

Window::~Window ()
  = default;

void Window::show_new_window ()
  {
    w->show();
  }

void Window::toggle_window ()
  {
    if (w->isVisible())
      {
        w->hide();
      }
    else
      {
        w->show();
      }
  }
