#include <QDialogButtonBox>
#include <QLabel>
#include <QVBoxLayout>
#include "CustomDialog.h"

CustomDialog::CustomDialog (QWidget *parent)
  {
    setWindowTitle("HELLO!");
    auto buttons = QDialogButtonBox::StandardButton::Ok | QDialogButtonBox::StandardButton::Cancel;
    auto *buttonBox = new QDialogButtonBox(buttons);

    connect(buttonBox, &QDialogButtonBox::accepted, [this] ()
      {
          accept();
      });
    connect(buttonBox, &QDialogButtonBox::rejected, [this] ()
      {
          reject();
      });
//    self.buttonBox.accepted.connect(self.accept)
//    self.buttonBox.rejected.connect(self.reject)

    auto *layout = new QVBoxLayout();
    auto *message = new QLabel("Something happened, is that OK?");

    layout->addWidget(message);
    layout->addWidget(buttonBox);
    setLayout(layout);
  }

CustomDialog::~CustomDialog ()
  {
    qDebug() << "Dialog deleted...";
  }

//void CustomDialog::accept ()
//  {
//    qDebug() << "Accepted!";
//  }
//
//void CustomDialog::reject ()
//  {
//    qDebug() << "Rejected!";
//  }
