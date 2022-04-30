#pragma once

#include <QMainWindow>
#include <QPushButton>

using namespace std;

class Window : public QMainWindow
      {
      Q_OBJECT

      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window () override;

            bool button_is_checked;
      private slots:

            void the_button_was_clicked (bool checked = false);

            void the_button_was_toggled ();

            void the_button_was_released ();

            static void the_window_title_changed (const QString &title);


      private:
            int n_times_clicked {0};
            QPushButton *button;
            vector<QString> window_titles;
      };
