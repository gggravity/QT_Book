//
// Created by martin on 12-05-22.
//
#include <QUuid>
#include <QRandomGenerator>
#include "Worker_4.h"

Worker_4::Worker_4 ()
  {
    worker_id = QUuid::createUuid().toString();
  }

Worker_4::~Worker_4 ()
  {

  }

void Worker_4::run ()
  {
    auto total_n = 100;
    auto y2 = QRandomGenerator::global()->bounded(0, 10);
    auto delay = QRandomGenerator::global()->bounded(100000);
    auto value = 0;

    for (int n = 0 ; n < total_n ; n++)
      {
        // Dummy calculation, each worker will produce different values,
        // because of the random y & y2 values.
        auto y = QRandomGenerator::global()->bounded(0, 10);
        value += n * y2 - n * y;
        emit data(worker_id, n, value);
        usleep(delay);
      }
  }

