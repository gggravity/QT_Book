#pragma once
//#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QRandomGenerator>
#include <QRect>
#include <QMouseEvent>
#include <QPushButton>

using namespace std;

class Palette_button : public QPushButton
      {
      Q_OBJECT
      public:
            explicit Palette_button (const QString& color, QObject *parent = nullptr)
                : m_color { color }
              {
                setFixedSize(QSize(24, 24));
                setStyleSheet(QString("background-color: %1;").arg(color));
              };

            ~Palette_button ()
            override = default;

      private:
            QColor m_color;


      };