#pragma once

#include <QMainWindow>
#include <QObject>
#include <QList>
#include <QMap>
#include <QLabel>
#include <QTimer>
#include <QRunnable>
#include <QThreadPool>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QRandomGenerator>
#include <QChartView>
#include <QLineSeries>
#include <QScatterSeries>

using namespace std;

class Q_runner_stop : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Q_runner_stop (QWidget *parent = nullptr);

            ~Q_runner_stop () override
            = default;;

            void update_progress(int n);

      private slots:

      private:
            QProgressBar *progress;

      };