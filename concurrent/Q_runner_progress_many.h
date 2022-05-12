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
#include <QRandomGenerator>

using namespace std;

class Q_runner_progress : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Q_runner_progress (QWidget *parent = nullptr);

            ~Q_runner_progress () override
            = default;;

      private slots:

            void execute ();

            void cleanup (const QString &job_id);

            void update_progress (const QString &job_id, int progress);

            int calculate_progress ();

            void refresh_progress ();

      private:
            QProgressBar *progress_bar;
            QThreadPool *thread_pool;
            QLabel *status;
            unordered_map<QString, int> worker_progress;
      };