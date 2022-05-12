//
// Created by martin on 10-05-22.
//
#include <QUuid>
#include <QRandomGenerator>

#include "Worker_3.h"

Worker_3::Worker_3 ()
  {

  }

Worker_3::~Worker_3 ()
  {

  }

void Worker_3::run ()
  {
    auto job_id = QUuid::createUuid().toString();
    int total_n = 1000;
    auto delay = QRandomGenerator::global()->bounded(10000);
    for (int n = 0 ; n < total_n; n++ )
      {
        auto progress_pc = int(100 * double(n + 1) / total_n);
        emit progress(job_id, progress_pc);
        usleep(delay);
      }
      emit finished(job_id);
  }

