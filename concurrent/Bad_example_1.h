#pragma once

#include <QMainWindow>
#include <QObject>
#include <QList>
#include <QLabel>
#include <QVariant>

class Bad_example_1 : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Bad_example_1 (QWidget *parent = nullptr);

            ~Bad_example_1 () override;

//      public slots:

            static void oh_no ();

            void recurring_timer ();

      private:
            int counter = 0;
            QLabel *l;

      };

