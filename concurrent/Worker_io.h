#pragma once

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QList>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>

using namespace std;

class Worker_io : public QObject, public QRunnable
      {
      Q_OBJECT
      public:
            explicit Worker_io (int id, QString url);

            ~Worker_io () override
            = default;;

            void run () override;

      signals:

            void data (int id, const string &line);

      public slots:

            void finished ();

            void downloadProgress (qint64 bytesReceived, qint64 bytesTotal);

            void uploadProgress (qint64 bytesSent, qint64 bytesTotal);

            void readyRead ();

            void requestSent();

            void errorOccurred (QNetworkReply::NetworkError error);

      private:
            int id;
            QString url;
            QNetworkReply *reply;
            QNetworkAccessManager *manager;
            QNetworkRequest *request;

      };