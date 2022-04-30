#include <bits/stdc++.h>
#include <QTableView>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QSqlRelationalDelegate>
#include "Window.h"

using namespace std;

Window::Window (QWidget *parent) :
    QWidget(parent)
  {
    setWindowTitle("TableView SQL Demo");

    table = new QTableView();

    model = new Model_relational();
    table->setModel(model);

    auto *layout = new QVBoxLayout();
    auto *search = new QLineEdit();

    connect(search, &QLineEdit::textChanged, this, &Window::update_filter);
//    self.search.textChanged.connect(self.update_filter)

    layout->addWidget(search);
    layout->addWidget(table);
    setLayout(layout);

//    model->setEditStrategy(QSqlTableModel::OnRowChange);
//    model->setSort(2, Qt::SortOrder::DescendingOrder);
//    model->select();

//    auto idx = model->fieldIndex("Milliseconds");
//    model->setSort(idx, Qt::SortOrder::DescendingOrder);
//    model->select();

    model->setTable("Track");
    model->setRelation(2, QSqlRelation("Album", "AlbumId", "Title"));
    model->setRelation(3, QSqlRelation("MediaType", "MediaTypeId", "Name"));
    model->setRelation(4, QSqlRelation("Genre", "GenreId", "Name"));

    auto *delegate = new QSqlRelationalDelegate(table);
    table->setItemDelegate(delegate);

    model->select();


    // Setting headers
    model->setHeaderData(2, Qt::Orientation::Horizontal, "Media Type");
    model->setHeaderData(3, Qt::Orientation::Horizontal, "Genre");
    model->select();

    QStringList headers_before;
    for (int i = 0 ; i < model->columnCount() ; i++)
      {
        headers_before.append(model->headerData(i, Qt::Horizontal).toString());
      }
    qDebug() << headers_before;

    model->removeColumns(5, 4);
    model->removeColumns(0, 1);
    model->select();

    QStringList headers;
    for (int i = 0 ; i < model->columnCount() ; i++)
      {
        headers.append(model->headerData(i, Qt::Horizontal).toString());
      }
    qDebug() << headers;

//    model->select();

  }

void Window::update_filter (const QString &text)
  {
    auto filter_str = "Track.Name LIKE '%" + text + "%'";
    model->setFilter(filter_str);
  }

Window::~Window ()
= default;
