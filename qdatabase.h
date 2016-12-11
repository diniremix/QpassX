#ifndef QDATABASE_H
#define QDATABASE_H

#include <QObject>
#include <QString>

#include <QStandardPaths>
#include <QDebug>
#include <QDir>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QModelIndex>
#include <QtSql/QSqlQueryModel>
#include <QSqlDriver>
#include <QList>
#include <QDebug>

class QDatabase
{
public:
  QDatabase();
  ~QDatabase();
  bool createDB(QString path);
  bool openDB(QString path);
  void search(QString table, int id);
  void select(QList<QString> tables, QList<QString> fields, QString conds);
  bool execQuery(QString sqlQuery, QString params);
  void closeDB();
  QSqlDatabase db;
};

#endif // QDATABASE_H
