#include <QLabel>
#include <QToolBar>
#include <QStatusBar>
#include <QCheckBox>
#include <QMenuBar>
#include "Window5.h"

Window::Window (QMainWindow *parent)
  {
    setWindowTitle("My App");

    auto *label = new QLabel("Hello!");
    label->setAlignment(Qt::AlignmentFlag::AlignCenter);

    setCentralWidget(label);

    auto * toolbar = new QToolBar("My main toolbar");
    toolbar->setIconSize(QSize(16, 16));
    addToolBar(toolbar);

    auto *button_action = new QAction(QIcon("../bug.png"), "Your button");
    button_action->setStatusTip("This is your button");
    connect(button_action, &QAction::triggered, this, onMyToolBarButtonClick);
    button_action->setCheckable(true);

    // You can enter keyboard shortcuts using key names (e.g. Ctrl+p)
    // Qt.namespace identifiers (e.g. Qt.CTRL + Qt.Key_P)
    // or system agnostic identifiers (e.g. QKeySequence.Print)
    button_action->setShortcut(QKeySequence("Ctrl+p"));

    toolbar->addAction(button_action);

    toolbar->addSeparator();

    auto *button_action2 = new QAction(QIcon("../bug.png"), "Your button2");
    button_action2->setStatusTip("This is your button2");
    connect(button_action2, &QAction::triggered, this, onMyToolBarButtonClick);
    button_action2->setCheckable(true);
    toolbar->addAction(button_action2);

    toolbar->addWidget(new QLabel("Hello"));
    toolbar->addWidget(new QCheckBox());

    setStatusBar(new QStatusBar());

    auto menu = menuBar();

    auto file_menu = menu->addMenu("&File");

    file_menu->addAction(button_action);
    file_menu->addSeparator();

    auto file_submenu = file_menu->addMenu("Submenu");
    file_submenu->addAction(button_action2);

    //    file_menu->addAction(button_action2);

  }

void Window::onMyToolBarButtonClick ()
  {
    qDebug() << "Clicked!";
  }

Window::~Window ()
= default;
