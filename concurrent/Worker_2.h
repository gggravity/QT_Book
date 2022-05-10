#pragma once

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QMap>
#include <QString>

using namespace std;

class Worker_2 : public QObject, public QRunnable
      {
      Q_OBJECT
      public:
            explicit Worker_2 ();

            void run () override;

            ~Worker_2 () override;

      signals:
            void progress(int progress);
      };