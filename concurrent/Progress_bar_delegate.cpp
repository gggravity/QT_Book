//
// Created by martin on 14-05-22.
//

#include "Progress_bar_delegate.h"
#include <QPainter>

void
Progress_bar_delegate::paint (QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
  {
    // data is our status dict, containing progress, id, status
    job_id, data = index.model()->data(index, Qt::ItemDataRole::DisplayRole);
    if (data["progress"] > 0)
    {
      auto color = new QColor(STATUS_COLORS[data["status"]]);

      auto brush = QBrush();
      brush.setColor(color);
      brush.setStyle(Qt::BrushStyle::SolidPattern);

      auto width = option.rect.width() * data["progress"] / 100;

      auto rect = QRect(option.rect);  //  Copy of the rect, so we can modify.
      rect.setWidth(width);

      painter->fillRect(rect, brush);
    }

    auto pen = QPen();
    pen.setColor(Qt::GlobalColor::black);
    painter->drawText(option.rect, Qt::AlignmentFlag::AlignLeft, job_id);


    QStyledItemDelegate::paint(painter, option, index);
  }
