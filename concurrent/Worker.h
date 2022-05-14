//
// Created by martin on 13-05-22.
//

#pragma once

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QString>

class Worker : public QObject, public QRunnable
      {
      Q_OBJECT
      public:
            explicit Worker ();

            void run () override;

      signals:

            void error (QString job_id, QString error);

            void result (QString job_id, QList<int> result);

            void finished (QString job_id);

            void progress (QString job_id, int progress);

            void status (QString job_id, QString status);

      private:
            QString job_id;
            QList<int> results;

      };
