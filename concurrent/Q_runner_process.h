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
#include <QPlainTextEdit>

using namespace std;

class Q_runner_process : public QMainWindow
      {
      Q_OBJECT

      public:
            explicit Q_runner_process (QWidget *parent = nullptr);

            void start ();

            void result (const QString &value);

      private:
            QPlainTextEdit *text;
            QThreadPool *thread_pool;
      };
