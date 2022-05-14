#include <bits/stdc++.h>
#include <QApplication>
#include "Q_runner_generic_callback.h"

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication a(argc, argv);
    Q_runner_generic_callback window;
//    window.resize(800, 600);
    window.show();

    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


