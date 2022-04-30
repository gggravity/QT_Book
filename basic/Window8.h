#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QContextMenuEvent>

class Window : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window () override;

      protected:
            void mousePressEvent (QMouseEvent *event) override;

            void mouseReleaseEvent (QMouseEvent *event) override;

            void mouseDoubleClickEvent (QMouseEvent *event) override;

            void mouseMoveEvent (QMouseEvent *event) override;

            void contextMenuEvent (QContextMenuEvent *event) override;

      private:
            QLabel *label;

      };

