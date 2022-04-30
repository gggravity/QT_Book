#pragma once

#include <QMainWindow>
#include <QTableView>
#include <QLineEdit>
#include "Model.h"

class Window : public QMainWindow
      {

      Q_OBJECT
      public:
            explicit Window (QMainWindow *parent = nullptr);

            ~Window () override;

      private slots:

      private:

      };

