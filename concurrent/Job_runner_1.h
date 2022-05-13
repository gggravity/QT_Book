//
// Created by martin on 13-05-22.
//

#pragma once

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QList>
#include <QString>

struct Worker_killed_exception : public std::exception
    {
        [[nodiscard]] const char *what () const noexcept override
          {
            return "Worker_killed_exception";
          }
    };

class Job_runner_1 : public QObject, public QRunnable
      {
      Q_OBJECT
      public:
            explicit Job_runner_1 ();

            ~Job_runner_1 () override;

            void run () override;

      signals:

            void update_progress (int value);

      public slots:

            void kill ();

      private:
            bool is_killed { false };
      };

