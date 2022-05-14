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

class Sub_process_worker : public QObject, public QRunnable
      {
      Q_OBJECT

      public:
            explicit Sub_process_worker (QString command);

            void run () override;

      signals:

            void result (QString value);

            void finished ();

      private:
            QString m_command;
      };