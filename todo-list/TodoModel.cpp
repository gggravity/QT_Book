#include "TodoModel.h"

Todo_model::Todo_model (QWidget *parent) :
    QAbstractListModel(parent)
  {
    todos = new QList<Todo>;

    load();

    tick = new QImage("../tick.png");
    cross = new QImage("../cross.png");
  }

void Todo_model::add_todo (const Todo &todo) const
  {
    // Access the list via the model and push_back the new text.
    todos->push_back(todo);

    save();
  }

void Todo_model::delete_todo (QModelIndex index)
  {
    beginRemoveRows(QModelIndex(), index.row(), index.row());

    todos->removeAt(index.row());

    endRemoveRows();

    save();
  }

void Todo_model::complete_todo (QModelIndex index) const
  {
    auto i = index.row();

    todos[0][i].done = !todos[0][i].done;

    save();
  }

int Todo_model::rowCount (const QModelIndex &parent) const
  {
    return int(todos->size());
  }

QVariant Todo_model::data (const QModelIndex &index, int role) const
  {
    if (role == Qt::ItemDataRole::DisplayRole)
      {
        return todos->at(index.row()).name;
      }

    if (role == Qt::ItemDataRole::DecorationRole)
      {

        if (todos->at(index.row()).done)
          {
            return *tick;
          }
        else
          {
            return *cross;
          }
      }
    return { };
  }

bool Todo_model::insertRows (int row, int count, const QModelIndex &parent)
  {
    return QAbstractItemModel::insertRows(row, count, parent);
  }

bool Todo_model::removeColumns (int column, int count, const QModelIndex &parent)
  {
    return QAbstractItemModel::removeColumns(column, count, parent);
  }

QJsonArray Todo_model::toJson () const
  {
    QJsonArray array;
    for (auto &todo : *todos)
      {
        array.append(todo.toJson());
      }
    return array;
  }

void Todo_model::save () const
  {
    QFile file("data.json");

    if (file.open(QIODevice::WriteOnly))
      {
        auto data = QJsonDocument(toJson());
        QTextStream stream(&file);
        stream << data.toJson().constData();
      }
  }

void Todo_model::load () const
  {
    QFile file("data.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();

    QJsonArray array = document.array();
        foreach (const QJsonValue &record, array)
        {
          QJsonObject obj = record.toObject();

          QJsonValue done = obj.value("done");
          QJsonValue name = obj.value("name");

          todos->push_back({ done.toBool(), name.toString() });
        }
  }

Todo_model::~Todo_model ()
= default;
