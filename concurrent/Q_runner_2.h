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
#include <QRandomGenerator>

using namespace std;


class Q_runner_2 : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Q_runner_2 (QWidget *parent = nullptr);


            ~Q_runner_2 () override
            = default;;

            void oh_no ();

      public slots:
            static void worker_output (const QMap<QString, int>& s);

            static void worker_complete ();

            static void worker_error (const QString& t);

            void recurring_timer ();

      private:
            int counter { 0 };
            QLabel *l;
            QThreadPool *thread_pool;
      };