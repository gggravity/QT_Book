//
// Created by martin on 14-05-22.
//

#include <iostream>
#include "Worker_generic.h"

Worker_generic::Worker_generic (func_t func, int x, int y)
  {
    // Store constructor arguments (re-used for processing)
    m_func = func;
    m_x = x;
    m_y = y;
  }

void Worker_generic::run ()
  {
    qInfo() << "Thread running.";

    QString output;

    bool exception_caught = true;
    try
      {

        output = m_func(m_x, m_y);
//        throw runtime_error("Something went wrong.");
        exception_caught = false;
      }
    catch (exception &e)
      {
        qWarning() << e.what();
        auto stacktrace = boost::stacktrace::stacktrace();
        emit error(stacktrace);
      }
    if (!exception_caught)
      {
        emit result(output);  // Return the result of the processing
      }
    // finally:
    emit finished(); // Done
  }
