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

struct Axis_range {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
};

class Q_runner_calculator : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Q_runner_calculator (QWidget *parent = nullptr);

            ~Q_runner_calculator () override
            = default;;

      private slots:

            void execute ();

            void receive_data (const QString &worker_id, int x, int y);

            void update_axis_range(int x, int y);

      private:
            QThreadPool *thread_pool;
            QMap<QString, QLineSeries *> lines;
            QChartView *chart_view;
            Axis_range axis_range { 0, 0, 0, 0};
      };