#pragma once

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QMap>
#include <QString>

using namespace std;

class Worker : public QObject, public QRunnable
      {
      Q_OBJECT
      public:
            explicit Worker (int iterations = 5);

            void run () override;

            ~Worker () override;

      signals:

            void finished ();

            void error (QString);

            void result (QMap<QString, int>);

      private:
            int iterations;
      };