#pragma once

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QList>
#include <QString>

using namespace std;

class Worker_4 : public QObject, public QRunnable
      {
      Q_OBJECT
      public:
            explicit Worker_4 ();

            void run () override;

            ~Worker_4 () override;

      signals:

            void data (const QString &worker_id, int x, int y);

      private:
            QString worker_id;
      };