#pragma once

//#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QRandomGenerator>
#include <QRect>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QDial>
#include "Canvas.h"

using namespace std;

class Power_bar : public QWidget
      {
      Q_OBJECT
      public:
            explicit Power_bar (int steps = 5, QWidget *parent = nullptr);

            explicit Power_bar (const QList<QString>& steps, QWidget *parent = nullptr);


            ~Power_bar ()
            override = default;

            QDial *dial;
      private:

      };