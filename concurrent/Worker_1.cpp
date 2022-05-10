//
// Created by martin on 10-05-22.
//

#include "Worker_1.h"

Worker::Worker (int iterations) : iterations(iterations)
  {
//    qInfo() << this << "Worker started, i =" << iterations;
  }

Worker::~Worker ()
  {
//    qInfo() << this << "Worker destroyed";
  }

void Worker::run ()
  {
    int n, v;
    bool exception_caught = true;
    try
      {
        for (int i = 0 ; i < iterations ; ++i)
          {
            if (i == 40)
              {
                throw runtime_error("Math error: Attempted to divide by Zero");
              }
            usleep(10000);
            v = 5 / ( 40 - i );
            n = i;
          }
          exception_caught = false;
      }
    catch (exception &e)
      {
        emit error(e.what());
      }
    if (!exception_caught)
      {
        emit finished();
        emit result(QMap<QString, int> { { "n",     n },
                                         { "value", v } });
      }
  }

