#ifndef FORMNEW_H
#define FORMNEW_H

#include <QWidget>
#include "qdatabase.h"
#include <QFileDialog>
#include "auth.h"
#define MIN_LENGTH_PASSWORD  6


namespace Ui {
  class formnew;
}

class formnew : public QWidget
{
  Q_OBJECT

public:
  explicit formnew(QWidget *parent = 0);
  ~formnew();

private:
  Ui::formnew *ui;
  QString fileName;
  void genSchema(QString user, QString password, QString key);
  bool validatePass(QString pass);
  QString api(QString p);

private slots:
  void opendlg();
  void createdb();

};

#endif // FORMNEW_H
