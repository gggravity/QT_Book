#include <bits/stdc++.h>
#include <QApplication>
#include "Window5.h"

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication a(argc, argv);
    Window window;
    window.resize(800,600);
    window.show();
    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


