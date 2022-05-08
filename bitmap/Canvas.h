#pragma once
//#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QRandomGenerator>
#include <QRect>
#include <QMouseEvent>

using namespace std;

class Canvas : public QLabel
      {
      Q_OBJECT
      public:
            explicit Canvas (QWidget *parent = nullptr);

            ~Canvas()
            override = default;

            void set_pen_color(QColor color);

            [[nodiscard]] QSize sizeHint () const override;

      protected:
            void mouseMoveEvent (QMouseEvent *event) override;

            void mouseReleaseEvent (QMouseEvent *event) override;

      private:
            QPixmap *pixmap;
            QColor *pen_color;
            int last_x = -99;
            int last_y = -99;

      };