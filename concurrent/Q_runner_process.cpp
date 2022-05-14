//
// Created by martin on 14-05-22.
//

#include <QProcess>
#include "Q_runner_process.h"

Q_runner_process::Q_runner_process (QWidget *parent)
  {
    // Some buttons
    auto layout = new QVBoxLayout();
    text = new QPlainTextEdit(this);
    layout->addWidget(text);

    auto btn_run = new QPushButton("Execute", this);
    connect(btn_run, &QPushButton::clicked, this, &Q_runner_process::start);

    layout->addWidget(btn_run);
    auto w = new QWidget(this);

    w->setLayout(layout);
    setCentralWidget(w);

    // Thread runner
    thread_pool = new QThreadPool(this);
    show();
  }

void Q_runner_process::start ()
  {
    // Create a runner
    auto sub_process = new QProcess(this);
//    sub_process->start("ls");
    sub_process->execute("ls");
//    auto runner = SubProcessWorker("python dummy_script.py");
    connect(sub_process, &QProcess::readyReadStandardOutput, this, &Q_runner_process::result);
//    self.runner.signals.result.connect(self.result)
    thread_pool->start(sub_process);
  }

void Q_runner_process::result (const QString& value)
  {
    text->appendPlainText(value);
  }
