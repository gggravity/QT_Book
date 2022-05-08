#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLineEdit>

using namespace std;

class Signals_forward : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Signals_forward (QWidget *parent = nullptr)
              {

                connect(this, &Signals_forward::message, this, &Signals_forward::my_custom_fn);

                auto le = new QLineEdit("Enter some text", this);
                connect(le, &QLineEdit::textChanged, this, &Signals_forward::message);

                setCentralWidget(le);
              };

            ~Signals_forward ()
            override = default;

      signals:

            void message (const QString &message);

      private slots:

            static void my_custom_fn (const QString &message)
              {
                qInfo() << message;
              }

      private:

      };