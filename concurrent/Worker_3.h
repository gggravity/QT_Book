#pragma once

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QMap>
#include <QString>

using namespace std;

class Worker_3 : public QObject, public QRunnable
      {
      Q_OBJECT
      public:
            explicit Worker_3 ();

            void run () override;

            ~Worker_3 () override;

      signals:

            void progress (const QString &job_id, int progress);

            void finished (const QString &job_id);
      };