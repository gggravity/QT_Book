#pragma once

#include <QWidget>
#include <QTableView>
#include "Model_relational.h"

class Window : public QWidget
      {

      Q_OBJECT
      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window () override;

      private slots:

      private:
            QTableView *table;
            Model *model;

            void update_filter (const QString &text);
      };

