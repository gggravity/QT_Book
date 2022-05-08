#include "Canvas.h"

Canvas::Canvas (QWidget *parent)
  {
    pixmap = new QPixmap(600, 300);
    pixmap->fill(Qt::GlobalColor::white);
    setPixmap(*pixmap);
    pen_color = new QColor("#000000");

  }

void Canvas::set_pen_color (QColor color)
  {
    pen_color = new QColor(color);
  }

QSize Canvas::sizeHint () const
  {
    return QLabel::sizeHint();
  }

void Canvas::mouseMoveEvent (QMouseEvent *event)
  {
    auto position = event->position();

    if (last_x == -99) // First event.
    {
      last_x = int(position.x());
      last_y = int(position.y());
      return;
    }

    auto painter = QPainter(pixmap);

    auto pen = painter.pen();
    pen.setWidth(4);
    pen.setColor(*pen_color);

    painter.setPen(pen);
    painter.drawLine(last_x, last_y, int(position.x()), int(position.y()));
    painter.end();

    setPixmap(*pixmap);

    // Update the origin for next time.
    last_x = int(position.x());
    last_y = int(position.y());

    QLabel::mouseMoveEvent(event);
  }

void Canvas::mouseReleaseEvent (QMouseEvent *event)
  {
    last_x = -99;
    last_y = -99;

    QLabel::mouseReleaseEvent(event);
  }
