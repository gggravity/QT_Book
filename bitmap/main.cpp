#include <bits/stdc++.h>
#include <QApplication>
#include "Power_bar.h"

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication a(argc, argv);

    //    Power_bar window {30};

//    Power_bar window {
//        QList<QString> {
//            "#5e4fa2", "#3288bd", "#66c2a5",
//            "#abdda4", "#e6f598", "#ffffbf",
//            "#fee08b", "#fdae61", "#f46d43",
//            "#d53e4f", "#9e0142"
//        }
//    };

    Power_bar window(QList<QString> { "#a63603", "#e6550d", "#fd8d3c", "#fdae6b", "#fdd0a2", "#feedde" });

    window.resize(800, 600);
    window.show();

    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


