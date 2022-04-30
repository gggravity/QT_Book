#include <bits/stdc++.h>
#include <QTableView>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlRelationalDelegate>
#include "Window.h"

using namespace std;

Window::Window (QMainWindow *parent) :
    QMainWindow(parent)
  {
    model = new QSqlQueryModel(this);
    table = new QTableView(this);

    // needed for sorting
    auto proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(model);
    table->setModel(proxyModel);

//    table->setModel(model);

    table->setSortingEnabled(true);
    table->sortByColumn(0, Qt::AscendingOrder);

    table->resizeColumnsToContents();

    setWindowTitle("TableViewSqlQueryModel Demo");

    auto *container = new QWidget(this);
    auto *layout_search = new QHBoxLayout(this);

    track = new QLineEdit();
    track->setPlaceholderText("Track name...");
    connect(track, &QLineEdit::textChanged, [this] ()
      {
          update_query();
      });

    composer = new QLineEdit();
    composer->setPlaceholderText("Artist name...");
    connect(composer, &QLineEdit::textChanged, [this] ()
      {
          update_query();
      });

    album = new QLineEdit();
    album->setPlaceholderText("Album name...");
    connect(album, &QLineEdit::textChanged, [this] ()
      {
          update_query();
      });

    layout_search->addWidget(track);
    layout_search->addWidget(composer);
    layout_search->addWidget(album);

    auto *layout_view = new QVBoxLayout(this);
    layout_view->addLayout(layout_search);

    layout_view->addWidget(table);
    container->setLayout(layout_view);


//    auto query = QSqlQuery("SELECT Name, Composer FROM track");
//    model->setQuery(std::move(query));

//    query = new QSqlQuery();
//    query->prepare(
//        "SELECT Name, Composer, Album.Title FROM Track "
//        "INNER JOIN Album ON Track.AlbumId = Album.AlbumId "
//        "WHERE Album.Title LIKE '%' || :album_title || '%' "
//    );
//    query->bindValue(":album_title", "Sinatra");
//    query->exec();
//    model->setQuery(std::move(*query));
    update_query();

    setCentralWidget(container);
  }

void Window::update_query ()
  {
    auto query = QSqlQuery();

    static auto text = "SELECT Name, Composer, Album.Title FROM Track "
                       "INNER JOIN Album ON Track.AlbumId=Album.AlbumId WHERE "
                       "Track.Name LIKE '%' || :track_name || '%' AND "
                       "Track.Composer LIKE '%' || :track_composer || '%' AND "
                       "Album.Title LIKE '%' || :album_title || '%'";

    query.prepare(text);

    query.bindValue(":track_name", track->text());
    query.bindValue(":track_composer", composer->text());
    query.bindValue(":album_title", album->text());

    query.exec();

    model->setQuery(std::move(query));
  }

Window::~Window ()
= default;
