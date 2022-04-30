#pragma once

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui
  {
    class AnotherWindow;
  }
QT_END_NAMESPACE

class AnotherWindow : public QWidget
      {
      Q_OBJECT

      public:
            explicit AnotherWindow (QWidget *parent = nullptr);

            ~AnotherWindow () override;

            QLabel *label;
      };
