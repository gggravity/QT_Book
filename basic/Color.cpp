#include "Color.h"
#include <QColor>
#include <QPalette>

Color::Color (QColor color, QWidget *parent)
  {
    setAutoFillBackground(true);
    auto palette = this->palette();
    palette.setColor(QPalette::ColorRole::Window, QColor(color));
    setPalette(palette);
  }

Color::~Color ()
  = default;
