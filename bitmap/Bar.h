#pragma once

//#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QRandomGenerator>
#include <QRect>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QList>
#include "Canvas.h"

using namespace std;

class Bar : public QWidget
      {
      Q_OBJECT
      public:
            explicit Bar (QWidget *parent = nullptr);

            explicit Bar (const QList<QString> &steps, QWidget *parent = nullptr);

            explicit Bar (int steps, QWidget *parent = nullptr);

            ~Bar ()
            override = default;

            void trigger_refresh ();

      protected:
            void paintEvent (QPaintEvent *event) override;

            [[nodiscard]] QSize sizeHint () const override;

      private:
            int n_steps { 5 };
            QList<QString> m_steps;
            double bar_solid_percent { 0.8 };
            QColor background_color = QColor("black");
            int padding { 4 }; // n - pixel gap around edge.

      };