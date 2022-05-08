#include <QVBoxLayout>
#include "Window.h"
#include "Palette_button.h"

Window::Window (QWidget *parent)
  {
    canvas = new Canvas();
    auto w = new QWidget();
    auto l = new QVBoxLayout();
    w->setLayout(l);
    l->addWidget(canvas);

    auto palette = new QHBoxLayout();
    add_palette_buttons(palette);
    l->addLayout(palette);

    setCentralWidget(w);
  }

void Window::add_palette_buttons (QHBoxLayout *layout)
  {
    for (const auto& color : COLORS)
      {
        auto button = new Palette_button(color, this);
        connect(button, &Palette_button::pressed, [=](){
              canvas->set_pen_color(color);
        });
        layout->addWidget(button);
      }
  }
