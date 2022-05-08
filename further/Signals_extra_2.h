#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

using namespace std;

class Signals_extra : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Signals_extra (QWidget *parent = nullptr)
              {
                auto v = new QVBoxLayout(this);
                auto h = new QHBoxLayout(this);

                for (int i { 0 } ; i < 10 ; i++)
                  {
                    auto button = new QPushButton(QString::number(i), this);
                    connect(button, &QPushButton::clicked, [=] ()
                      {
                          button_clicked(QString::number(i));
                      });
                    h->addWidget(button);
                  }

                v->addLayout(h);
                label = new QLabel("Placeholder text ...", this);
                v->addWidget(label);

                auto w = new QWidget(this);
                w->setLayout(v);

                setCentralWidget(w);
              };

            ~Signals_extra ()
            override = default;

      signals:

      private slots:

            void button_clicked (const QString& text)
              {
                label->setText(text);
              };

      private:
            QLabel *label;
      };