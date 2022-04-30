#pragma once

#include <QWidget>
#include <QColor>

class Color : public QWidget
      {
      public:
            explicit Color (QColor color, QWidget *parent = nullptr);

            ~Color () override;

      };


