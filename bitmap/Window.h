//#include <bits/stdc++.h>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QRandomGenerator>
#include <QRect>
#include <QMouseEvent>
#include <QHBoxLayout>
#include "Canvas.h"

using namespace std;

class Window : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window ()
            override = default;

            void add_palette_buttons (QHBoxLayout *layout);

      private:

            Canvas *canvas;

            // 17 undertones https://lospec.com/palette-list/17undertones
            QList<QString> COLORS = { "#000000",
                                      "#141923",
                                      "#414168",
                                      "#3a7fa7",
                                      "#35e3e3",
                                      "#8fd970",
                                      "#5ebb49",
                                      "#458352",
                                      "#dcd37b",
                                      "#fffee5",
                                      "#ffd035",
                                      "#cc9245",
                                      "#a15c3e",
                                      "#a42f3b",
                                      "#f45b7a",
                                      "#c24998",
                                      "#81588d",
                                      "#bcb0c2",
                                      "#ffffff",
            };
      };