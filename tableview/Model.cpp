#include "Model.h"
#include <QIcon>

Model::Model (QObject *parent) :
    QAbstractTableModel(parent)
  {
    table = {
        { 4.49354, 9,     2 },
        { 1,       -1,    -1 },
        { true,    5,     -5 },
        { 3,       false, QDate(2012, 7, 6) },
        { 7,       8,     "testing" },
    };

    colors = { "#053061", "#2166ac", "#4393c3", "#92c5de", "#d1e5f0", "#f7f7f7", "#fddbc7", "#f4a582", "#d6604d",
               "#b2182b", "#67001f" };
  }

int Model::rowCount (const QModelIndex &parent) const
  {
    // The length of the outer list.
    return int(table.size());
  }

int Model::columnCount (const QModelIndex &parent) const
  {
    // The following takes the first sub-list, and returns
    // the length (only works if all rows are an equal length)
    return int(table[0].size());
  }

QVariant Model::data (const QModelIndex &index, int role) const
  {
    // Get the raw value
    auto value = table[index.row()][index.column()];

    if (role == Qt::ItemDataRole::DisplayRole)
      {
        switch (value.userType())
          {
            case QMetaType::Float:
            case QMetaType::Double:
              return QString::number(value.toDouble(), 'g', 3);
            break;
            case QMetaType::QString:
              return '"' + value.toString() + '"';
            case QMetaType::QDate:
              return value.toDate().toString("dddd the d. MMMM yyyy");
            default:
              break;
          }
        return value;
      }

//    if (role == Qt::ItemDataRole::BackgroundRole && index.column() == 2)
//      {
//        // See below for the data structure.
//        return QColor(Qt::GlobalColor::blue);
//      }

    if (role == Qt::ItemDataRole::TextAlignmentRole)
      {
        switch (value.userType())
          {
            case QMetaType::Int:
            case QMetaType::Float:
            case QMetaType::Double:
              return QAbstractTableModel::flags(index) | Qt::AlignmentFlag::AlignVCenter
                     | Qt::AlignmentFlag::AlignRight;
            default:
              break;
          }
      }

    if (role == Qt::ItemDataRole::ForegroundRole)
      {
        if (value.toInt() < 0)
          {
            switch (value.userType())
              {
                case QMetaType::Int:
                case QMetaType::Float:
                case QMetaType::Double:
                  return QColor("red");
                default:
                  break;
              }
          }
      }

    if (role == Qt::ItemDataRole::BackgroundRole)
      {
//        switch (value.userType())
//          {
//            case QMetaType::Int:
//            case QMetaType::Float:
//            case QMetaType::Double:
//              {
//                // Limit to range -5 ... +5, then convert to 0..10
//                int color_index = int(index.data().toDouble());
//
//                if (color_index < -5)
//                  {
//                    color_index = -5;
//                  }
//                if (color_index > 5)
//                  {
//                    color_index = 5;
//                  }
//                color_index += 5;
//
//                return QColor(colors[color_index]);
//              }
//            break;
//            default:
//              break;
//          }
      }

    if (role == Qt::ItemDataRole::DecorationRole)
      {
        switch (value.userType())
          {
            case QMetaType::QDate:
              return QIcon("../calendar.png");
            break;

            case QMetaType::Bool:
              if (value.toBool())
                {
                  return QIcon("../tick.png");
                }
            return QIcon("../cross.png");
            break;
            case QMetaType::Int:
            case QMetaType::Float:
            case QMetaType::Double:
              {
                // Limit to range -5 ... +5, then convert to 0..10
                int color_index = int(index.data().toDouble());

                if (color_index < -5)
                  {
                    color_index = -5;
                  }
                if (color_index > 5)
                  {
                    color_index = 5;
                  }
                color_index += 5;

                return QColor(colors[color_index]);
              }
            break;
            default:
              break;
          }
      }

    return { };
  }

QVariant Model::headerData (int section, Qt::Orientation orientation, int role) const
  {
    if (role != Qt::DisplayRole)
      {
        return {};
      }
    if (role == Qt::ItemDataRole::DisplayRole)
      {
        if (orientation == Qt::Orientation::Horizontal)
          {
            vector<QString> headers {"one", "two", "three", "four", "five"};
            return headers.at(section);
          }
        if (orientation == Qt::Orientation::Vertical)
          {
            return QString("record no. %1").arg(section);
          }
      }

    return QAbstractItemModel::headerData(section, orientation, role);
  }

Model::~Model ()
= default;
