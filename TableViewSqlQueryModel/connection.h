#pragma once

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

static bool createConnection ()
  {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../chinook.sqlite");
    if (db.open())
      {
        qDebug() << "Connected to database.";
        return true;
      }
    else
      {
        qDebug() << "Can't open database.";
        return false;
      }
  }