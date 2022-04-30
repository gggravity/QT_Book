#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QListWidgetItem>
#include <QStackedLayout>

class Window : public QMainWindow
      {
      Q_OBJECT

      public:
            explicit Window (QMainWindow *parent = nullptr);

            ~Window () override;

      private:

            void button_clicked();

      };

