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

using namespace std;

typedef QString (*func_t)(int, int);

class Worker_generic : public QObject, public QRunnable
      {
      Q_OBJECT
      public:
            explicit Worker_generic (func_t func, int x = 10, int y = 20);

            void run () override;

      signals:

            void finished ();

            void error (boost::stacktrace::stacktrace stacktrace);

            void result (const QString &string);

      private:
            func_t m_func;
            int m_x;
            int m_y;
      };