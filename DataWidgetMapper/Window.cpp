#include <bits/stdc++.h>
#include <QTableView>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlRelationalDelegate>
#include <QFormLayout>
#include <QSpinBox>
#include <QLabel>
#include <QDataWidgetMapper>
#include <QPushButton>
#include "Window.h"

using namespace std;

Window::Window (QMainWindow *parent) :
    QMainWindow(parent)
  {
    setWindowTitle("TableViewSqlQueryModel Demo");

    auto track_id = new QSpinBox();
    track_id->setRange(0, 2147483647);
    track_id->setDisabled(true);

    auto name = new QLineEdit();

    auto album = new QComboBox();

    auto media_type = new QComboBox();

    auto genre = new QComboBox();

    auto composer = new QLineEdit();

    auto milliseconds = new QSpinBox();
    milliseconds->setRange(0, 2147483647);
    milliseconds->setSingleStep(1);

    auto bytes = new QSpinBox();
    bytes->setRange(0, 2147483647);
    bytes->setSingleStep(1);

    auto unit_price = new QDoubleSpinBox();
    unit_price->setRange(0, 999);
    unit_price->setSingleStep(0.01);
    unit_price->setPrefix("$");

    auto form = new QFormLayout();
    form->addRow(new QLabel("Track ID"), track_id);
    form->addRow(new QLabel("Track name"), name);
    form->addRow(new QLabel("Composer"), composer);
    form->addRow(new QLabel("Milliseconds"), milliseconds);
    form->addRow(new QLabel("Bytes"), bytes);
    form->addRow(new QLabel("Unit Price"), unit_price);

    auto model = new QSqlTableModel();

    auto mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(track_id, 0);
    mapper->addMapping(name, 1);
    mapper->addMapping(composer, 5);
    mapper->addMapping(milliseconds, 6);
    mapper->addMapping(bytes, 7);
    mapper->addMapping(unit_price, 8);

    model->setTable("Track");
    model->select();

    mapper->toFirst();

    setMinimumSize(QSize(400, 400));
    auto controls = new QHBoxLayout();

    auto prev_rec = new QPushButton("Previous");
    connect(prev_rec, &QPushButton::clicked, [mapper](){mapper->toPrevious();});

    auto next_rec = new QPushButton("Next");
    connect(next_rec, &QPushButton::clicked, [mapper](){mapper->toNext();});

    auto save_rec = new QPushButton("Save Changes");
    connect(save_rec, &QPushButton::clicked, [mapper](){mapper->submit();});

    controls->addWidget(prev_rec);
    controls->addWidget(next_rec);
    controls->addWidget(save_rec);

    auto layout = new QVBoxLayout();
    layout->addLayout(form);
    layout->addLayout(controls);

    auto widget = new QWidget();
    widget->setLayout(layout);
    setCentralWidget(widget);
  }



Window::~Window ()
= default;
