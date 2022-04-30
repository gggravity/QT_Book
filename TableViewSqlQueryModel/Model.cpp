#include "Model.h"

Model::Model (QObject *parent) :
    QSqlQueryModel(parent)
  {

  }

Model::~Model ()
= default;
