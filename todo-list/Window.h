#pragma once

#include <QWidget>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include "TodoModel.h"

class Window : public QWidget
      {
      Q_OBJECT
      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window () override;

      private slots:
            void addButtonClicked();

            void deleteButtonClicked ();

            void completeButtonClicked ();

      private:
            QListView *todoView;
            QLineEdit *todoEdit;
            QPushButton *addButton;
            QPushButton *deleteButton;
            QPushButton *completeButton;
            Todo_model *model;

      };

