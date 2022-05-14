//
// Created by martin on 14-05-22.
//

#pragma once

#include <QStyledItemDelegate>

class Progress_bar_delegate : public QStyledItemDelegate
      {
      public:
            void
            paint (QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
      };


