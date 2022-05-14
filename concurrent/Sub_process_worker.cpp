//
// Created by martin on 14-05-22.
//

#include "Sub_process_worker.h"

#include <utility>

Sub_process_worker::Sub_process_worker (QString command)
    : m_command { std::move(command) }
  {

  }

void Sub_process_worker::run ()
  {
    /**
    Execute the command, returning the result.
    */
//    output = subprocess.getoutput(self.command);
    emit result(output);
    emit finished();
  }
