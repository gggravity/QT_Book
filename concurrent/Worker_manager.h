//
// Created by martin on 13-05-22.
//

#pragma once

#include <QAbstractListModel>
#include <QString>
#include <QMap>
#include <QThreadPool>
#include "Worker.h"

class Worker_manager : public QAbstractListModel
      {
      Q_OBJECT
      public:
            explicit Worker_manager (QObject *parent);

            [[nodiscard]] QVariant data (const QModelIndex &index, int role) const override;

            [[nodiscard]] int rowCount (const QModelIndex &parent) const override;

      signals:

            void status (QString status);

      public slots:

            void notify_status ();

            void enqueue (Worker *worker);

            void receive_status (const QString& job_id, const QString& status);

            void receive_progress (const QString& job_id, int progress);

            void receive_error (const QString& job_id, const QString& message);

            void done (const QString& job_id);

            void cleanup ();

      private:
            int max_threads;
            QThreadPool *thread_pool;
            QMap<QString, Worker> workers;
//            _state = {}
      };

