#include <QLabel>
#include <QToolBar>
#include <QStatusBar>
#include <QCheckBox>
#include <QMenuBar>
#include <QDialog>
#include <QMessageBox>
#include "Window6.h"
#include "CustomDialog.h"

Window::Window (QMainWindow *parent)
  {
    setWindowTitle("My App");

    auto *button = new QPushButton("Press me for a dialog!");
    connect(button, &QPushButton::clicked, [=] ()
      {
          button_clicked();
      });

    setCentralWidget(button);

  }

void Window::button_clicked ()
  {
//    qDebug() << "Button Clicked!!!";

//    auto *dlg = new CustomDialog(this);
//
//    if (dlg->exec())
//      {
//        qDebug() << "Success!";
//      }
//    else
//      {
//        qDebug() << "Cancel!";
//      }
//      delete dlg;

//    auto *dlg = new QMessageBox(this);
//    dlg->setWindowTitle("I have a question!");
//    dlg->setText("This is a simple dialog");

//    dlg->setStandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);
//    dlg->setIcon(QMessageBox::Icon::Question);
//    auto click = dlg->exec();

    // Look up the button enum entry for the result.
//    auto button = QMessageBox::StandardButton(click);

//    auto button = QMessageBox::question(this, "Question dialog", "The longer message");
//
//    if (button == QMessageBox::StandardButton::Yes)
//      {
//        qDebug() << "Yes!";
//      }
//    else
//      {
//        qDebug() << "No!";
//      }

    auto buttons = QMessageBox::StandardButton::Discard |
                   QMessageBox::StandardButton::NoToAll |
                   QMessageBox::StandardButton::Ignore;

    auto defaultButton = QMessageBox::StandardButton::Discard;

    auto button = QMessageBox::critical(
        this,
        "Oh dear!",
        "Something went very wrong.", buttons, defaultButton
    );

    if (button == QMessageBox::StandardButton::Discard)
      {
        qDebug() << "Discard!";
      }
    else if (button == QMessageBox::StandardButton::NoToAll)
      {
        qDebug() << "No to all!";
      }
    else
      {
        qDebug() << "Ignore!";
      }
  }

Window::~Window ()
= default;
