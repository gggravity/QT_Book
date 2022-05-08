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

class Routing : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Routing (QWidget *parent = nullptr)
              {
                label = new QLabel("Click in this window", this);
                status = statusBar();
                setFixedSize(QSize(200, 100));
                setCentralWidget(label);
              };

            ~Routing ()
            override = default;

      protected:
            /*
            void mousePressEvent (QMouseEvent *event) override
              {
                auto button = event->button();
                auto pos = event->position();

                if (button == Qt::MouseButton::LeftButton)
                  {
                    label->setText("mousePressEvent LEFT");

                    if (pos.x() < 100)
                      {
                        status->showMessage("Left click on left");
                        move(x() - 10, y());
                      }
                    else
                      {
                        status->showMessage("Left click on right");
                        move(x() + 10, y());
                      }
                  }
                else if (button == Qt::MouseButton::MiddleButton)
                  {
                    label->setText("mousePressEvent MIDDLE");
                  }

                else if (button == Qt::MouseButton::RightButton)
                  {
                    label->setText("mousePressEvent RIGHT");
                    if (pos.x() < 100)
                      {
                        status->showMessage("Right click on left");
                        qInfo() << "Something else here.";
                        move(10, 10);
                      }
                    else
                      {
                        status->showMessage("Right click on right");
                        move(400, 400);
                      }
                  }
                QWidget::mousePressEvent(event);
              }
 */

            void mousePressEvent (QMouseEvent *event) override
              {
                auto button = event->button();
                auto pos = event->position();

                switch (button)
                  {
                    case Qt::LeftButton:
                      {
                        label->setText("mousePressEvent LEFT");
                        if (pos.x() < 100)
                          {
                            status->showMessage("Left click on left");
                            move(x() - 10, y());
                          }
                        else
                          {
                            status->showMessage("Left click on right");
                            move(x() + 10, y());
                          }
                      }
                    break;

                    case Qt::RightButton:
                      {
                        label->setText("mousePressEvent RIGHT");
                        if (pos.x() < 100)
                          {
                            status->showMessage("Right click on left");
                            qInfo() << "Something else here.";
                            move(10, 10);
                          }
                        else
                          {
                            status->showMessage("Right click on right");
                            move(400, 400);
                          }
                      }
                    break;

                    case Qt::MiddleButton:
                      {
                        label->setText("mousePressEvent MIDDLE");
                      }
                    break;

                    default:
                      break;
                  }

                QWidget::mousePressEvent(event);
              }

            void mouseMoveEvent (QMouseEvent *event) override
              {
                label->setText("mouseMoveEvent");
                QWidget::mouseMoveEvent(event);
              }

      signals:

      private slots:

      private:
            QLabel *label;
            QStatusBar *status;

      };