#include <bits/stdc++.h>
#include <QApplication>
#include "basic/Window8.h"

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication a(argc, argv);
    QApplication::setStyle("Fusion");
    Window window;
    window.resize(800,600);
    window.show();
    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


