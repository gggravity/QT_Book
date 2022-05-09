//
// Created by martin on 08-05-22.
//

#include "Bar.h"
#include "Power_bar.h"

Bar::Bar (QWidget *parent) : QWidget(parent)
  {
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    qWarning() << "steps must be a list or int";
  }

Bar::Bar (const QList<QString> &steps, QWidget *parent) : QWidget(parent)
  {
    qDebug() << "List mode";
    n_steps = int(steps.size());
    m_steps = steps;
  }

Bar::Bar (int steps, QWidget *parent)
  {
    qDebug() << "single mode";
    n_steps = steps;
    m_steps.push_back("#FF0000");
  }

void Bar::paintEvent (QPaintEvent *event)
  {
    auto painter = new QPainter(this);

    auto brush = QBrush();
    brush.setColor(background_color);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    auto rect = QRect(0, 0, painter->device()->width(), painter->device()->height());
    painter->fillRect(rect, brush);

    // Get current state.
    auto power_bar = qobject_cast<Power_bar *>(parent());
    auto dial = power_bar->dial;
    auto v_min = dial->minimum();
    auto v_max = dial->maximum();
    auto value = dial->value();

    /*
    auto pc = ( value - v_min ) / double(v_max - v_min);
    auto n_steps_to_draw = int(pc * 5);

    padding = 5;
     */

    // Define our canvas.
    auto d_height = painter->device()->height() - ( padding * 2 );
    auto d_width = painter->device()->width() - ( padding * 2 );

    // Draw the bars.
    auto step_size = d_height / double(n_steps);
    auto bar_height = step_size * bar_solid_percent;

    // Calculate the y-stop position, from the value in range.
    auto pc = ( value - v_min ) / double(v_max - v_min);
    auto n_steps_to_draw = int(pc * n_steps);

    for (int i { 0 } ; i < n_steps_to_draw ; ++i)
      {
        auto color = i < m_steps.size() - 1 ? i : m_steps.size() - 1; // cap color at m_size max size.
        brush.setColor(QColor(m_steps.at(color)));
        auto y_pos = ( 1 + i ) * step_size;
        auto rect_bar = QRect(
            padding,
            padding + d_height - int(y_pos),
            d_width,
            int(bar_height)
        );
        painter->fillRect(rect_bar, brush);
      }


    /*
    // layout
    auto step_size = d_height / 5;
    auto bar_height = step_size * 0.6;

    // draw
    auto pen = painter->pen();
    pen.setColor(QColor("red"));
    painter->setPen(pen);

    auto font = painter->font();
    font.setFamily("Times");
    font.setPointSize(18);
    painter->setFont(font);

//    painter->drawText(25, 25, QString("%1-->%2<--%3").arg(v_min).arg(value).arg(v_max));

    painter->drawText(25, 25, QString("%1").arg(n_steps_to_draw));

    brush.setColor(QColor("red"));
    for (int i { 0 } ; i < n_steps_to_draw ; ++i)
      {
        auto y_pos = ( 1 + i ) * step_size;
        auto rect_bar = QRect(
            padding,
            padding + d_height - int(y_pos),
            d_width,
            int(bar_height)
        );
        painter->fillRect(rect_bar, brush);
      }
*/

    painter->end();

    QWidget::paintEvent(event);
  }

void Bar::trigger_refresh ()
  {
    update();
  }

QSize Bar::sizeHint () const
  {
    return { 40, 120 };
  }
