#pragma once
#include <QWidget>
#include <QTableView>

class Window : public QWidget
      {

      Q_OBJECT
      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window () override;

      private slots:

      private:
            QTableView *table;

      };

