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
#include <boost/stacktrace.hpp>

using namespace std;

QString execute_this_fn (int x, int y);

class Q_runner_generic : public QMainWindow
      {
      Q_OBJECT

      public:
            explicit Q_runner_generic (QWidget *parent = nullptr);

      private slots:

            void print_output (const QString &string);

            void thread_complete ();

            void oh_no ();

            void recurring_timer ();

            void error (boost::stacktrace::stacktrace stacktrace);

      private:
            int counter { 0 };
            QLabel *l;
            QThreadPool *thread_pool;
      };