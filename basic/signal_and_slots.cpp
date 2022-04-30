#include <bits/stdc++.h>
#include <QApplication>
#include <QPushButton>
#include "Window2.h"

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication a(argc, argv);
    Window2 window;
    window.show();

    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
