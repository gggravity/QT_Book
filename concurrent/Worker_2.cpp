//
// Created by martin on 10-05-22.
//

#include "Worker_2.h"

Worker_2::Worker_2 ()
  {

  }

Worker_2::~Worker_2 ()
  {

  }

void Worker_2::run ()
  {
    int total_n = 1000;
    for (int n = 0 ; n < total_n; n++ )
    {
      auto progress_pc = int(100 * double(n + 1) / total_n); // Progress 0-100% as int
      emit progress(progress_pc);
//      self.signals.progress.emit(progress_pc);
      usleep(1000);
    }
  }


