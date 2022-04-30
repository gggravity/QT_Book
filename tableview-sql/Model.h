#pragma once

#include <QtCore>
#include <QSqlTableModel>
#include <QSqlDatabase>


using namespace std;

class Model : public QSqlTableModel
      {
      Q_OBJECT
      public:
            explicit Model (QObject *parent = nullptr);

            ~Model () override;

      private:

      };

