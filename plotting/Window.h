//
// Created by martin on 14-05-22.
//

#pragma once

#include <QMainWindow>
#include <QObject>
#include <QList>
#include <QLabel>
#include <QTimer>
#include <QRunnable>
#include <QThreadPool>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QString>
#include <QRandomGenerator>
#include <QChartView>
#include <QChart>
#include <boost/stacktrace.hpp>

using namespace std;

struct Data
    {
        int hour;
        int temperature;
    };

class Window : public QMainWindow
      {
      Q_OBJECT

      public:
            explicit Window (QWidget *parent = nullptr);

      public slots:

            void currentTextChanged (const QString &text);

            void currentIndexChanged (int index);

            void hoverd(const QPointF &point, bool state);

      private:
            QChart *chart;

      };