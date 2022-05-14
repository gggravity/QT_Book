//
// Created by martin on 13-05-22.
//

#include <bits/stdc++.h>
#include <QUuid>
#include <QRandomGenerator>
#include "Worker.h"

using namespace std;

Worker::Worker ()
  {
    //Give this job a unique ID.
    job_id = QUuid::createUuid().toString();
    // The arguments for the worker
    emit status(job_id, "STATUS_WAITING");
  }

void Worker::run ()
  {
    /*
    Initialize the runner function with passed args, kwargs.
    */
    emit status(job_id, "STATUS_RUNNING");

    //    x, y = self.args;
    int x, y;
    bool exception_caught = true;
    try
      {
        auto value = QRandomGenerator::global()->bounded(0, 100) * x;
        auto delay = QRandomGenerator::global()->bounded(0, 10000);

        for (int n { 0 } ; n < 100 ; ++n)
          {
            // Generate some numbers.
            value = value / y;
            y -= 1;

            // The following will sometimes throw a division by zero error.
            results.append(value);

            // Pass out the current progress.
            emit progress(job_id, n + 1);
            usleep(delay);
          }
      }
    catch (exception &e)
      {
        cerr << "Error: " << e.what() << endl;
        // We swallow the error and continue.
        emit error(job_id, e.what());
        emit status(job_id, "STATUS_ERROR");
      }
    if (!exception_caught)
      {
        emit result(job_id, results);
        emit status(job_id, "STATUS_COMPLETE");
        emit finished(job_id);
      }

  }
