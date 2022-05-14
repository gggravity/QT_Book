//
// Created by martin on 13-05-22.
//

#include <QTimer>
#include "Worker_manager.h"

using namespace std;

Worker_manager::Worker_manager (QObject *parent) : QAbstractListModel(parent)
  {
    // Create a thread pool for our workers.
    thread_pool = new QThreadPool();
    // thread_pool.setMaxThreadCount(1);
    max_threads = thread_pool->maxThreadCount();
    qInfo() << "Multithreading with maximum" << max_threads << "threads";

    auto status_timer = new QTimer();
    status_timer->setInterval(100);
    connect(status_timer, &QTimer::timeout, this, &Worker_manager::notify_status);
    status_timer->start();
  }

void Worker_manager::notify_status ()
  {
    auto n_workers = int(workers.size());
    auto running = min(n_workers, max_threads);
    auto waiting = max(0, n_workers - max_threads);
    emit status(QString("%1 running, %2 waiting, %3 threads")
                    .arg(running).arg(waiting).arg(max_threads));
  }

void Worker_manager::enqueue (Worker *worker)
  {
    /**
    Enqueue a worker to run (at some point) by passing it to the
    QThreadPool.
    */

    connect(worker, &Worker::error, this, &Worker_manager::receive_error);
    connect(worker, &Worker::status, this, &Worker_manager::receive_status);
    connect(worker, &Worker::progress, this, &Worker_manager::receive_progress);
    connect(worker, &Worker::finished, this, &Worker_manager::done);
    thread_pool->start(worker);
    workers[worker.job_id] = worker;
    //Set default status to waiting, 0 progress.
//    self._state[worker.job_id] = DEFAULT_STATE.copy()
    emit layoutChanged();

  }

void Worker_manager::receive_status (const QString &job_id, const QString& status)
  {
//    _state[job_id]["status"] = status;
    emit layoutChanged();
  }

void Worker_manager::receive_progress (const QString &job_id, int progress)
  {
//    self._state[job_id]["progress"] = progress
    emit layoutChanged();
  }

void Worker_manager::receive_error (const QString &job_id, const QString& message)
  {
    qWarning() << job_id << message;
  }

void Worker_manager::done (const QString &job_id)
  {
    /**
    Task/worker complete. Remove it from the active workers
    dictionary. We leave it in worker_state, as this is used to
    to display past/complete workers too.
    */
//    del self._workers[job_id]
    emit layoutChanged()
  }

void Worker_manager::cleanup ()
  {
    /*
    Remove any complete/failed workers from worker_state.
    */
    for (job_id, s in list(self._state.items()))
      {
        if (s["status"] in(STATUS_COMPLETE, STATUS_ERROR))
        {
          del self._state[job_id];
        }
      }
    emit layoutChanged();
  }

QVariant Worker_manager::data (const QModelIndex &index, int role) const
  {
    if (role == Qt::ItemDataRole::DisplayRole)
      {
        // See below for the data structure.
        job_ids = list(self._state.keys());
        job_id = job_ids[index.row()];
        return job_id, self._state[job_id];
      }
  }

int Worker_manager::rowCount (const QModelIndex &parent) const
  {
    return state.size()
  }