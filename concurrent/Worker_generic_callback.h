//
// Created by martin on 14-05-22.
//

#pragma once

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QList>
#include <QString>
#include <QThreadPool>
#include <boost/stacktrace.hpp>
#include "Q_runner_generic_callback.h"

using namespace std;

typedef QString (*func_t) (int, int, Q_runner_generic_callback *);

class Worker_generic_callback : public QObject, public QRunnable
      {
      Q_OBJECT

      public:
            explicit Worker_generic_callback (func_t func, Q_runner_generic_callback *self, int x = 10, int y = 20);

            void run () override;

      signals:

            void finished ();

            void error (const boost::stacktrace::stacktrace &stacktrace);

            void result (const QString &string);


      private:
            func_t m_func;
            int m_x;
            int m_y;
            Q_runner_generic_callback *m_self;

      };