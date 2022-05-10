#include <bits/stdc++.h>
#include <QApplication>
#include "Q_runner_base.h"

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication a(argc, argv);
    Q_runner_base window;
    window.resize(800, 600);
    window.show();

    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


