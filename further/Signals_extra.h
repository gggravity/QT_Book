#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

using namespace std;

class Signals_extra : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Signals_extra (QWidget *parent = nullptr)
              {

                auto button = new QPushButton("Press me", this);
                button->setCheckable(true);
                connect(button, &QPushButton::clicked, [=] ()
                  {
                      button_clicked(true, button);
                  });

                setCentralWidget(button);
              };

            ~Signals_extra ()
            override = default;

      signals:

      private slots:

            static void button_clicked (bool checked, QPushButton *button)
              {
                qInfo() << button << checked;
                button->hide();
              };

      private:

      };