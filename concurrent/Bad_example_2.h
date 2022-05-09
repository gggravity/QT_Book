#pragma once

#include <QMainWindow>
#include <QObject>
#include <QList>
#include <QLabel>
#include <QVariant>

class Bad_example_2 : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Bad_example_2 (QWidget *parent = nullptr);

            ~Bad_example_2 () override;

//      public slots:

            void oh_no ();

            void recurring_timer ();

            void change_message ();

      private:
            int counter = 0;
            QLabel *l;
            QString message;

      };

