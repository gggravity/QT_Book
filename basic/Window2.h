#pragma once

#include <QMainWindow>

using namespace std;

class Window2 : public QMainWindow
      {
      Q_OBJECT

      public:
            explicit Window2 (QWidget *parent = nullptr);

            ~Window2 () override;

      public slots:

            static void the_button_was_clicked ();
      };

