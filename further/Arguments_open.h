#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QStatusBar>
#include <QTextEdit>
#include <QFile>

using namespace std;

class Arguments : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Arguments (int argc, char *argv[], QWidget *parent = nullptr)
              {
                editor = new QTextEdit(this);

                if (argc > 1)
                  {
                    auto filename = argv[1];
                    open_file(filename);
                  }

                setCentralWidget(editor);
                setWindowTitle("Text viewer");
              };

            ~Arguments ()
            override = default;

      private:

            void open_file (const QString &filename)
              {
                QFile file { filename };
                QString text;

                if (file.open(QIODevice::ReadOnly))
                  {
                    while (!file.atEnd())
                      {
                        text = file.readAll();
                      }
                    file.close();
                  }
                else
                  {
                    qInfo() << file.errorString();
                  }

                editor->setPlainText(text);
              }

            QTextEdit *editor;
      };