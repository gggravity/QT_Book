#include <QVBoxLayout>
#include <QLineEdit>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QPlainTextEdit>
#include <QCheckBox>
#include <QComboBox>
#include "Window.h"

Window::Window (QWidget *parent) :
    QWidget(parent)
  {
    setWindowTitle("Todo list");

    todoView = new QListView(); // The list of current todos
    todoEdit = new QLineEdit(); //The text input for creating a new to-do item
    addButton = new QPushButton("Add Todo"); // Create the new to-do, adding it to the todos list
    deleteButton = new QPushButton("Delete"); //Delete the current selected to-do,removing it from the todos list
    completeButton = new QPushButton("Change status"); // Mark the current selected to-do as done
    model = new Todo_model();

    auto *layout = new QVBoxLayout();
    layout->addWidget(todoView);

    auto *inner_layout = new QHBoxLayout();
    inner_layout->addWidget(deleteButton);
    inner_layout->addWidget(completeButton);

    layout->addLayout(inner_layout);
    layout->addWidget(todoEdit);
    layout->addWidget(addButton);

    setLayout(layout);

    todoView->setModel(model);

    connect(addButton, &QPushButton::clicked, this, &Window::addButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this, &Window::deleteButtonClicked);
    connect(completeButton, &QPushButton::clicked, this, &Window::completeButtonClicked);
//    connect(ui->MySecondBtn, &QPushButton::clicked, this, &MyWidget::MySecondBtnClicked);

//    connect(addButton, &QPushButton::pressed, [this] ()
//      {
//          model->add_todo();
//      });
//
//    connect(deleteButton, &QPushButton::pressed, [this] ()
//      {
//          model->delete_todo();
//      });
//
//    connect(completeButton, &QPushButton::pressed, [this] ()
//      {
//          model->complete_todo();
//      });
  }

void Window::addButtonClicked ()
  {
    // Add an item to our to-do list, getting the text from the QLineEdit.

    auto text = todoEdit->text();

    text = text.simplified(); // Remove whitespace.

    if (!text.isEmpty()) // Don't add empty strings.
      {
        model->add_todo({ false, text });
      }

    // Trigger refresh.
    model->layoutChanged();

    // Empty the input
    todoEdit->setText("");
  }

void Window::deleteButtonClicked ()
  {
    QModelIndex index = todoView->currentIndex();
    model->delete_todo(index);
  }

void Window::completeButtonClicked ()
  {
    QModelIndex index = todoView->currentIndex();
    model->complete_todo(index);

    // dataChanged takes top-left and bottom right, which are equal for a single selection.
    model->dataChanged(index, index);

    // Clear the selection (as it is no longer valid).
    todoView->clearSelection();
  }

Window::~Window ()
= default;
