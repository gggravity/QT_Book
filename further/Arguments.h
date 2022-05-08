#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QStatusBar>

using namespace std;

class Arguments : public QWidget
      {
      Q_OBJECT
      public:
            explicit Arguments (int argc, char *argv[], QWidget *parent = nullptr)
              {
                auto layout = new QVBoxLayout(this);
                for (int i = 0 ; i < argc ; i++)
                  {
                    auto l = new QLabel(argv[i], this);
                    layout->addWidget(l);
                  }
                setLayout(layout);
                setWindowTitle("Arguments");
              };

            ~Arguments ()
            override = default;

      protected:

      signals:

      private slots:

      private:

      };