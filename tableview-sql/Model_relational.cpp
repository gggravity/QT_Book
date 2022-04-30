#include "Model_relational.h"

Model_relational::Model_relational (QObject *parent) :
    QSqlRelationalTableModel(parent)
  {

  }

Model_relational::~Model_relational ()
= default;
