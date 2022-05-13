//
// Created by martin on 13-05-22.
//

#include "Job_runner_1.h"

using namespace std;

Job_runner_1::Job_runner_1 ()
  = default;

Job_runner_1::~Job_runner_1 ()
= default;

void Job_runner_1::run ()
  {
    try
      {
        for (int n = 0 ; n < 100 ; ++n)
          {
            emit update_progress(n + 1);
            usleep(100000);
            if (is_killed)
              {
                throw Worker_killed_exception();
              }
          }
      }
    catch (exception &e)
      {
        qDebug() << "Error:" << e.what();
      }
  }

void Job_runner_1::kill ()
  {
    is_killed = true;
  }
