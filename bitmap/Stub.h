#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QRandomGenerator>
#include <QRect>
#include <QMouseEvent>

using namespace std;

class Stub : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Stub (QWidget *parent = nullptr)
              {
                label = new QLabel(this);
                canvas = QPixmap(400, 300);
                canvas.fill(Qt::GlobalColor::white);
                label->setPixmap(canvas);

                setCentralWidget(label);

//                draw_something();

              };

            ~Stub ()
            override = default;

      protected:
            void mouseMoveEvent (QMouseEvent *event) override
              {
//                qInfo() << "mouseMoveEvent";

//                auto pos = event->position();
//                auto painter = new QPainter(&canvas);
//                painter->drawPoint(int(pos.x()), int(pos.y()));
//                painter->end();
//                label->setPixmap(canvas);

                auto pos = event->position();

                if (last_x == -99) // First event.
                  {
                    last_x = int(pos.x());
                    last_y = int(pos.y());
                    return; // Ignore the first time.
                  }

                auto painter = new QPainter(&canvas);
                auto pen = QPen();
                pen.setWidth(20);
                pen.setColor(Qt::blue);
                painter->setPen(pen);
                painter->drawLine(last_x, last_y, int(pos.x()), int(pos.y()));
                painter->end();

                label->setPixmap(canvas);

                // Update the origin for next time.
                last_x = int(pos.x());
                last_y = int(pos.y());

                QWidget::mouseMoveEvent(event);
              }

            virtual void mouseReleaseEvent (QMouseEvent *event) override
              {
                last_x = -99;
                last_y = -99;

                QWidget::mouseReleaseEvent(event);
              }

      private:

            void draw_something ()
              {
                qInfo() << "Running draw_something";

                vector<QString> colors = { "#FFD141", "#376F9F", "#0D1F2D", "#E9EBEF", "#EB5160" };

                auto painter = new QPainter(&canvas);
//                painter->drawLine(10, 10, 300, 200);

                auto pen = QPen();
//                pen.setWidth(40);
//                pen.setColor(Qt::red);
//                painter->setPen(pen);
//                painter->drawPoint(200,150);

//                pen.setWidth(3);
//                painter->setPen(pen);
//
//                for (int i = 0 ; i < 10000 ; i++)
//                  {
//                    auto random_color = QRandomGenerator::global()->bounded(int(colors.size()));
//                    pen.setColor(QColor(colors.at(random_color)));
//                    painter->setPen(pen);
//
//                    auto random1 = QRandomGenerator::global()->bounded(-100, 100);
//                    auto random2 = QRandomGenerator::global()->bounded(-100, 100);
//                    painter->drawPoint(200 + random1, 150 + random2);
//                  }

//                pen.setWidth(15);
//                pen.setColor(Qt::blue);
//                painter->setPen(pen);
//                painter->drawLine(QPoint(100, 100), QPoint(300, 200));

                pen.setWidth(3);
//                pen.setColor(QColor("#EB5160"));
//                painter->setPen(pen);
//                painter->drawRect(50, 50, 100, 100);
//                painter->drawRect(60, 60, 150, 100);
//                painter->drawRect(70, 70, 100, 150);
//                painter->drawRect(80, 80, 150, 100);
//                painter->drawRect(90, 90, 100, 150);

//                auto brush = QBrush();
//                brush.setColor(QColor("#FFD141"));
//                brush.setStyle(Qt::BrushStyle::Dense1Pattern);
//                painter->setBrush(brush);

//                painter->drawRects(QList<QRect> {
//                    { 50, 50, 100, 100 },
//                    { 60, 60, 150, 100 },
//                    { 70, 70, 100, 150 },
//                    { 80, 80, 150, 100 },
//                    { 90, 90, 100, 150 },
//                });

//                pen.setColor(QColor("#376F9F"));
//                painter->setPen(pen);
//
//                painter->drawRoundedRect(40, 40, 100, 100, 10, 10);
//                painter->drawRoundedRect(80, 80, 100, 100, 10, 50);
//                painter->drawRoundedRect(120, 120, 100, 100, 50, 10);
//                painter->drawRoundedRect(160, 160, 100, 100, 50, 50);

                pen.setColor(QColor(204, 0, 0));
                painter->setPen(pen); // r, g, b
//                painter->drawEllipse(10, 10, 100, 100);
//                painter->drawEllipse(10, 10, 150, 200);
//                painter->drawEllipse(10, 10, 200, 300);

//                painter->drawEllipse({ 100, 100 }, 10, 10);
//                painter->drawEllipse({ 100, 100 }, 15, 20);
//                painter->drawEllipse({ 100, 100 }, 20, 30);
//                painter->drawEllipse({ 100, 100 }, 25, 40);
//                painter->drawEllipse({ 100, 100 }, 30, 50);
//                painter->drawEllipse({ 100, 100 }, 35, 60);

//                auto font = QFont();
//                font.setFamily("Times");
//                font.setBold(true);
//                font.setPointSize(40);
//                painter->setFont(font);
//                painter->drawText(100, 100, "Hello, world!");

//                painter->drawText(100, 100, 100, 100, Qt::AlignmentFlag::AlignHCenter, "Hello, world!");

                label->setPixmap(canvas);
              }

            QPixmap canvas;
            QLabel *label;
            int last_x { -99 };
            int last_y { -99 };
      };