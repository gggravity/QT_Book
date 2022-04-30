#pragma once

#include <QMainWindow>
#include "anotherwindow.h"

class Window : public QMainWindow
      {
      Q_OBJECT

      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window () override;

      private:

            void show_new_window();
            void toggle_window();
            AnotherWindow *w;
      };
