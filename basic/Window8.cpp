#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include "Window8.h"

Window::Window (QWidget *parent) :
    QMainWindow(parent)
  {
    label = new QLabel("Click in this window");
    setCentralWidget(label);
  }
Window::~Window ()
= default;

void Window::mousePressEvent (QMouseEvent *event)
  {
    label->setText("mousePressEvent");

    switch (event->button())
      {
        case Qt::LeftButton:
          label->setText("mousePressEvent LEFT");
        break;
        case Qt::RightButton:
          label->setText("mousePressEvent RIGHT");
        break;
        case Qt::MiddleButton:
          label->setText("mousePressEvent MIDDLE");
        break;
        default:
          break;
      }

//    if (event->button() == Qt::MouseButton::LeftButton)
//      {    // handle the left-button press in here
//        label->setText("mousePressEvent LEFT");
//      }
//    else if (event->button() == Qt::MouseButton::MiddleButton)
//      {    // handle the middle-button press in here.
//        label->setText("mousePressEvent MIDDLE");
//      }
//    else if (event->button() == Qt::MouseButton::RightButton)
//      {// handle the right-button press in here.
//        label->setText("mousePressEvent RIGHT");
//      }

    QWidget::mousePressEvent(event);
  }

void Window::mouseReleaseEvent (QMouseEvent *event)
  {
    label->setText("mouseReleaseEvent");

    switch (event->button())
      {
        case Qt::LeftButton:
          label->setText("mouseReleaseEvent LEFT");
        break;
        case Qt::RightButton:
          label->setText("mouseReleaseEvent RIGHT");
        break;
        case Qt::MiddleButton:
          label->setText("mouseReleaseEvent MIDDLE");
        break;
        default:
          break;
      }

    QWidget::mouseReleaseEvent(event);
  }

void Window::mouseDoubleClickEvent (QMouseEvent *event)
  {
    label->setText("mouseDoubleClickEvent");

    switch (event->button())
      {
        case Qt::LeftButton:
          label->setText("mouseDoubleClickEvent LEFT");
        break;
        case Qt::RightButton:
          label->setText("mouseDoubleClickEvent RIGHT");
        break;
        case Qt::MiddleButton:
          label->setText("mouseDoubleClickEvent MIDDLE");
        break;
        default:
          break;
      }
    QWidget::mouseDoubleClickEvent(event);
  }

void Window::mouseMoveEvent (QMouseEvent *event)
  {
    label->setText("mouseMoveEvent");
    QWidget::mouseMoveEvent(event);
  }

void Window::contextMenuEvent (QContextMenuEvent *event)
  {
    auto *context = new QMenu(this);
    context->addAction(new QAction("test 1", this));
    context->addAction(new QAction("test 2", this));
    context->addAction(new QAction("test 3", this));
    context->exec(event->globalPos());

    QMainWindow::contextMenuEvent(event);
  }
