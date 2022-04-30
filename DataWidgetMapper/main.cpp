#include <bits/stdc++.h>
#include <QApplication>
#include "connection.h"
#include "Window.h"

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication a(argc, argv);

    if (!createConnection())
      return EXIT_FAILURE;

    Window window;
//    window.resize(1200, 800);
    window.show();

    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


