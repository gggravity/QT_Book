#include <bits/stdc++.h>
#include <QApplication>
#include "Signals_forward.h"

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication a(argc, argv);

    Signals_forward window;
    window.resize(800, 600);
    window.show();

    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


