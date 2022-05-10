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

            ~Q_runner_progress() override
            = default;;

      private slots:
            void execute();
            void update_progress(int progress);



      private:
            QProgressBar *progress_bar;
            QThreadPool *thread_pool;
      };