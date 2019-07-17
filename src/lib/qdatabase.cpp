#include "qdatabase.h"

QDatabase::QDatabase()
{
}

bool QDatabase::createDB(QString path)
{
  //QString dataDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
  //QDir dir(dataDir);
  QDir dir;
  QString dbName = dir.filePath(path);
  db= QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(dbName);
  qDebug() << "Creating database:" << dbName;

  if (!db.open()) {
      qDebug() << "cannot open Database";
      return false;
    }else{
      bool  ret=false;
      QSqlQuery query;

      //Describe QPASSXINFO
      ret=query.exec("create table if not exists  qpassxinfo ( "
                     "id INTEGER primary key autoincrement NOT NULL, "
                     "title VARCHAR(255) NOT NULL, "
                     "username VARCHAR(64) NOT NULL, "
                     "password VARCHAR(64) NOT NULL, "
                     "url TEXT VARCHAR(255) DEFAULT (NULL), "
                     "notes TEXT DEFAULT (NULL), "
                     "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP )"
                     );
      qDebug() << "creating QPASSXINFO" << ret;

      //Describe QPASSXSCHEME
      ret=query.exec("create table if not exists qpassxscheme ("
                     "id INTEGER primary key autoincrement NOT NULL, "
                     "usrnm VARCHAR(64) NOT NULL, "
                     "psswd VARCHAR(64) NOT NULL, "
                     "apikey VARCHAR(32) NOT NULL, "
                     "version VARCHAR(3) NOT NULL, "
                     "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP )"
                     );
      qDebug() << "creating QPASSXSCHEME" << ret;

      return true;
    }
}

bool QDatabase::openDB(QString path)
{
  qDebug() << "opening Database: " << path;
  QDir dir;
  QString dbName = dir.filePath(path);
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(dbName);
  qDebug() << db.password();

  if (!db.open()) {
      qDebug() << "cannot open Database";
      return false;
    }else{
      return true;
    }
}

void QDatabase::search(QString table, int id)
{
  bool ret= false;
  QSqlQuery query;

  QString q= QObject::tr("SELECT * FROM %1 WHERE id= %2").arg(table).arg(id);
  qDebug() << "el query: " << q;
  query.prepare(q);
  ret= query.exec();

  qDebug() << "estado consulta: " << ret;
  if (query.next()){
      qDebug() << "el next ";
    }else{
      qDebug() << "no hubo next";
    }
}

void QDatabase::select(QList<QString> tables, QList<QString> fields, QString conds)
{
  QString sql="SELECT ";

  if(tables.isEmpty()){
      qDebug() << "tables vacio: ";
    }
  sql+=" FROM ";
  int count =tables.size();
  int i=1;
  qDebug() << "tables: "<<count;
  while (!tables.isEmpty()){
      if (i<count){
          sql+=tables.takeFirst()+", ";
        }else{
          sql+=" ";
          break;
        }
      i++;
    }
  qDebug() << "sql: "<<sql;

  if(fields.isEmpty()){
      qDebug() << "fields vacio: ";
    }

  if(conds.isEmpty()){
      qDebug() << "conds vacio: ";
    }


}

bool QDatabase::execQuery(QString sqlQuery, QString params)
{
  bool ret= false;
  QSqlQuery query;

  qDebug() << "consulta: " << sqlQuery;

  ret= query.exec(sqlQuery);
  qDebug() << "estado consulta: " << ret;

  return ret;
}

void QDatabase::closeDB(){
  if (db.open()){
      db.close();
    }
}

QDatabase::~QDatabase()
{
  closeDB();
}
