//
// Created by martin on 13-05-22.
//

#include "Q_runner_io.h"
#include "Worker_io.h"

Q_runner_io::Q_runner_io (QWidget *parent)
  {
    urls = QList<QString>
        { "https://www.pythonguis.com/",
          "https://www.mfitzp.com/",
          "https://www.google.com/",
          "https://www.udemy.com/create-simple-gui-applications-with-python-and-qt/" };

    auto layout = new QVBoxLayout();
    text = new QPlainTextEdit(this);
    text->setReadOnly(true);

    auto button = new QPushButton("GO GET EM!", this);
    connect(button, &QPushButton::pressed, this, &Q_runner_io::execute);

    layout->addWidget(text);
    layout->addWidget(button);
    auto w = new QWidget(this);
    w->setLayout(layout);

    setCentralWidget(w);

    thread_pool = new QThreadPool(this);
    qInfo() << QString("Multithreading with maximum %1 threads").arg(thread_pool->maxThreadCount());
  }

void Q_runner_io::execute ()
  {
//    qDebug() << "Calling execute...";
    for (int n = 0; n < urls.size(); ++n)
      {
//        qDebug() << "url:" << urls.at(n);
        auto worker = new Worker_io(n, urls.at(n));
        connect(worker, &Worker_io::data, this, &Q_runner_io::display_output);
        // Execute
        thread_pool->start(worker);
      }
  }

void Q_runner_io::display_output (int id, const string &line)
  {
//    text->appendPlainText(QString("WORKER %1: %2").arg(id).arg(line));

    text->appendPlainText(QString("WORKER %1: %2").arg(id).arg(QString::fromStdString(line)));
  }
