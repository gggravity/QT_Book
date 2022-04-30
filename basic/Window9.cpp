#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QPlainTextEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include "Window9.h"

Window::Window (QWidget *parent) :
    QMainWindow(parent)
  {
    setWindowTitle("QSS Tester");
    auto *editor = new QPlainTextEdit();
    connect(editor,&QPlainTextEdit::textChanged, [editor, this](){
          auto qss = editor->toPlainText();
          setStyleSheet(qss);
    });
    auto *layout = new QVBoxLayout();
    layout->addWidget(editor);

    // Define a set of simple widgets.
    auto *cb = new QCheckBox("Checkbox");
    layout->addWidget(cb);

    auto *combo = new QComboBox();
    combo->setObjectName("thecombo");
    combo->addItems({ "First", "Second", "Third", "Fourth" });
    layout->addWidget(combo);

    auto sb = new QSpinBox();
    sb->setRange(0, 99999);
    layout->addWidget(sb);

    auto *l = new QLabel("This is a label");
    layout->addWidget(l);

    auto *le = new QLineEdit();
    le->setObjectName("mylineedit");
    layout->addWidget(le);

    auto *pb = new QPushButton("Push me!");
    layout->addWidget(pb);

    auto *container = new QWidget();
    container->setLayout(layout);
    setCentralWidget(container);

  }


Window::~Window ()
= default;
