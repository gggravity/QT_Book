#pragma once

#include <QtCore>
#include <QAbstractListModel>
#include <QLabel>
#include <QList>
#include <QString>
#include <QImage>
#include <vector>

using namespace std;

class Model : public QAbstractTableModel
      {
      Q_OBJECT
      public:
            explicit Model (QObject *parent = nullptr);

            ~Model () override;

            [[nodiscard]] int rowCount (const QModelIndex &parent) const override;

            [[nodiscard]] int columnCount (const QModelIndex &parent) const override;

            [[nodiscard]] QVariant data (const QModelIndex &index, int role) const override;

            [[nodiscard]] QVariant headerData (int section, Qt::Orientation orientation, int role) const override;

      private:
            vector<vector<QVariant>> table;
            vector<QString> colors;
      };

