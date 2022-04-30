#include <bits/stdc++.h>
#include <QApplication>
#include "Window9.h"

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication app(argc, argv);
    Window window;
    window.resize(800,600);
    window.show();
    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


