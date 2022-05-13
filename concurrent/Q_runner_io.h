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
#include <QPlainTextEdit>

using namespace std;

class Q_runner_io : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Q_runner_io (QWidget *parent = nullptr);

            ~Q_runner_io () override
            = default;;

      private slots:

            void execute ();

            void display_output (int id, const string &line);

      private:
            QThreadPool *thread_pool;
            QPlainTextEdit *text;
            QList<QString> urls;
      };