#pragma once

#include <QDialog>

class CustomDialog : public QDialog
      {
      Q_OBJECT
      public:
            explicit CustomDialog (QWidget *parent = nullptr);

            ~CustomDialog () override;

      private:
//            void accept () override;
//
//            void reject () override;
      };


