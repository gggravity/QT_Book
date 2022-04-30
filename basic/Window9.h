#pragma once

#include <QMainWindow>
#include <QLabel>

class Window : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window () override;

      private:

      };

