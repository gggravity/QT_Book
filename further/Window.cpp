
#include "Window.h"
#include <QString>
#include <QMap>
#include <QVariant>

Window::Window (QWidget *parent)
    : QMainWindow(parent)
  {
    setWindowTitle("signals custom");

    connect(this, &Window::message, this, &Window::message_slot);
    connect(this, &Window::value, this, &Window::value_slot);
    connect(this, &Window::another, this, &Window::another_slot);
    connect(this, &Window::one_more, this, &Window::one_more_slot);
    connect(this, &Window::anything, this, &Window::anything_slot);

    emit message("my message");

    QStringList string_list;
    string_list << "Test" << "another" << "one";
    emit value(string_list);

    QList<int> int_list;
    int_list << 1 << 2 << 3 << 4 << 5;
    emit another(int_list);

    QMap<QString, int> map {
        { "test",    1 },
        { "another", 2 }
    };
    emit one_more(map);

    emit anything(QVariant { 1223 });

  }

void Window::message_slot (const QString &message)
  {
    qInfo() << "message:" << message;
  }

void Window::value_slot (const QStringList &list)
  {
    qInfo() << "value:" << list;
  }

void Window::another_slot (const QList<int> &list)
  {
    qInfo() << "another:" << list;
  }

void Window::one_more_slot (const QMap<QString, int> &map)
  {
    qInfo() << "one_more:" << map;
  }

void Window::anything_slot (const QVariant &variant)
  {
    qInfo() << "anything:" << variant;
  }

Window::~Window ()
= default;

