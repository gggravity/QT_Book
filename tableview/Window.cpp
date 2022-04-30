#include <bits/stdc++.h>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QPlainTextEdit>
#include <QCheckBox>
#include <QComboBox>
#include "Window.h"
#include "Model.h"

using namespace std;

Window::Window (QWidget *parent) :
    QWidget(parent)
  {
    setWindowTitle("TableView Demo");

    table = new QTableView();
    auto *model = new Model();
    table->setModel(model);

    auto *layout = new QVBoxLayout();
    layout->addWidget(table);
    setLayout(layout);
  }

Window::~Window ()
= default;
