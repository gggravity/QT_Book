#pragma once

#include <QtCore>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>


using namespace std;

class Model : public QSqlRelationalTableModel
      {
      Q_OBJECT
      public:
            explicit Model (QObject *parent = nullptr);

            ~Model () override;

      private:

      };

