#pragma once

#include <QMainWindow>
#include <QObject>
#include <QList>
#include <QLabel>
#include <QTimer>
#include <QRunnable>
#include <QThreadPool>
#include <QPushButton>
#include <QVBoxLayout>
#include <QRandomGenerator>

using namespace std;

class Worker : public QObject, public QRunnable
{
  Q_OBJECT
      public:
            void run () override
              {

              }
      };

class Q_runner_base : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Q_runner_base (QWidget *parent = nullptr)
            {

            };


            ~Q_runner_base() override
            = default;;


      public slots:


      };