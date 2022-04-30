#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QListWidgetItem>
#include <QStackedLayout>

class Window : public QMainWindow
      {
      Q_OBJECT

      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window () override;

      private:
            static void show_state (int state);

            static void index_changed (int index);

            static void text_changed (const QString &text);

            static void item_changed (QListWidgetItem *current, QListWidgetItem *previous);

            void return_pressed ();

            void selection_changed ();

            static void value_changed (int value);

            static void value_changed_str (const QString &text_value);

            static void slider_position (int position);

            static void slider_pressed ();

            static void slider_released ();

            void activate_tab_1();

            void activate_tab_2();

            void activate_tab_3();

            QLineEdit *widget;

            QStackedLayout *stacklayout;

      };

