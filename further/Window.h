#pragma once

#include <QMainWindow>
#include <QObject>
#include <QList>
#include <QVariant>

class Window : public QMainWindow
      {
      Q_OBJECT
      public:
            explicit Window (QWidget *parent = nullptr);

            ~Window () override;

      signals:

            void message (QString message);

            void value (QStringList list);

            void another (QList<int> list);

            void one_more (QMap<QString, int> map);

            void anything (QVariant variant);

      private slots:

            static void message_slot (const QString& message);

            static void value_slot (const QStringList& list);

            static void another_slot (const QList<int>& list);

            static void one_more_slot (const QMap<QString, int>& map);

            static void anything_slot (const QVariant& variant);

      private:

      };

