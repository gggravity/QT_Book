//
// Created by martin on 13-05-22.
//

#include "Worker_io.h"
#include <QNetworkReply>
#include <utility>
#include <QEventLoop>

Worker_io::Worker_io (int id, QString url) : id(id),
                                             url(std::move(url))
  {
  }

void Worker_io::run ()
  {
    manager = new QNetworkAccessManager();
    request = new QNetworkRequest();

    request->setUrl(QUrl(url));
    reply = manager->get(*request);

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, this, &Worker_io::finished);
    connect(reply, &QNetworkReply::requestSent, this, &Worker_io::requestSent);
    connect(reply, &QNetworkReply::downloadProgress, this, &Worker_io::downloadProgress);
    connect(reply, &QNetworkReply::uploadProgress, this, &Worker_io::uploadProgress);
    connect(reply, &QNetworkReply::readyRead, this, &Worker_io::readyRead);
    connect(reply, &QNetworkReply::errorOccurred, this, &Worker_io::errorOccurred);
    loop.exec();
  }

void Worker_io::finished ()
  {
    if (reply->error())
      {
        qDebug() << reply->errorString();
        return;
      }

    QString answer = reply->readAll();

    for (const auto& line: answer.split("\n",Qt::SkipEmptyParts ))
      {
        auto length = to_string(line.length());
        emit data(id, length);
      }
  }

void Worker_io::downloadProgress (qint64 bytesReceived, qint64 bytesTotal)
  {
    qInfo() << "downloadProgress:" << bytesReceived << bytesTotal;
  }

void Worker_io::uploadProgress (qint64 bytesSent, qint64 bytesTotal)
  {
    qInfo() << "uploadProgress:" << bytesSent << bytesTotal;
  }

void Worker_io::readyRead ()
  {
    qInfo() << "Ready to read...";
  }

void Worker_io::errorOccurred (QNetworkReply::NetworkError error)
  {
    qInfo() << "Network error ..." << error;
  }

void Worker_io::requestSent ()
  {
    qInfo() << "request sent ...";
  }
