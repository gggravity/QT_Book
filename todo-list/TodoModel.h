#pragma once

#include <QtCore>
#include <QAbstractListModel>
#include <QLabel>
#include <QList>
#include <QString>
#include <QImage>

struct Todo
    {
        bool done;
        QString name;

        [[nodiscard]] QJsonObject toJson () const
          {
            return { { "done", done },
                     { "name", name } };
          }
    };

class Todo_model : public QAbstractListModel
      {
      Q_OBJECT
      public:
            explicit Todo_model (QWidget *parent = nullptr);

            ~Todo_model () override;

            void add_todo (const Todo &todo) const;

            void delete_todo (QModelIndex index);

            void complete_todo (QModelIndex index) const;

            [[nodiscard]] int rowCount (const QModelIndex &parent) const override;

            [[nodiscard]] QVariant data (const QModelIndex &index, int role) const override;

            bool insertRows (int row, int count, const QModelIndex &parent) override;

            bool removeColumns (int column, int count, const QModelIndex &parent) override;

      private:
            [[nodiscard]] QJsonArray toJson () const;

            void save () const;

            void load () const;

            QImage *tick;
            QImage *cross;
            QList<Todo> *todos;
      };

