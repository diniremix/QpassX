#include "formnew.h"
#include "ui_formnew.h"
#include <QMessageBox>
formnew::formnew(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::formnew)
{
  ui->setupUi(this);
  this->setWindowFlags(Qt::WindowTitleHint |  Qt::WindowCloseButtonHint| Qt::WindowSystemMenuHint);
}

formnew::~formnew()
{
  delete ui;
}


void formnew::opendlg(){
  fileName = QFileDialog::getSaveFileName(this,
                                          tr("Create new Database"), "",
                                          tr("QpassX Databse (*.qdbx);;All Files (*)"));

  QDir dir;
  QString tfile = dir.relativeFilePath(fileName);
  if (!fileName.isEmpty()){
      ui->edpath->setText(tfile);
    }
}

void formnew::createdb(){
  if (fileName.isEmpty()){
      QMessageBox::warning(this,
                           tr("QpassX"),
                           tr("select a new name for database"),QMessageBox::Ok);

    }else if (ui->edpassword->text().isEmpty()) {
      QMessageBox::warning(this,
                           tr("QpassX"),
                           tr("The 'password' field is required"),QMessageBox::Ok);
    }else {
      QString usr, passx, apikey;
      usr=ui->edusername->text();
      passx=ui->edpassword->text();

      if (usr.isEmpty()){
          usr="QpassXDbUser1";
      }

      int ret =validatePass(passx);
      if (ret==true){
          passx= api(passx);
          if (apikey.isEmpty()){
              apikey=api(passx);
          }
          genSchema(usr, passx, apikey);
      }
    }
}

bool formnew::validatePass(QString pass){
  if (pass.isEmpty()||pass.length()<0){
    return false;
  }else if (pass.length()< MIN_LENGTH_PASSWORD){
      QMessageBox::warning(this,
                           tr("QpassX"),
                           tr("the password must be contain at least 6 characters"),QMessageBox::Ok);
      return false;
  }else{
      return true;
  }
}

QString formnew::api(QString pwd){
  Auth *_authc= new Auth();
  QString api_key= _authc->generateKey(pwd);
  qDebug() << "api_key"<<api_key;
  return api_key;
}

void formnew::genSchema(QString user, QString password, QString key){
  QDatabase *db= new QDatabase();
  if(db->createDB(fileName)){
      qDebug() << "creating db for widget";
      //key="apikeyjore";

      QString q = tr("insert into qpassxscheme ('usrnm','psswd','apikey','version') values('%1','%2','%3','%4')")
          .arg(user)
          .arg(password)
          .arg(key)
          .arg("QpassXV1");

      int r= db->execQuery(q,"");
      if (r==true){
          qDebug() << "creating user for db";
          db->closeDB();
          QMessageBox::information(this,
                                   tr("QpassX"),
                                   tr("database has been created"),QMessageBox::Ok);
          this->close();
        }else{
          QMessageBox::critical(this,
                                tr("QpassX"),
                                tr("An error occurred while creating the database schema"),QMessageBox::Ok);
        }
    }else{
      QMessageBox::critical(this,
                            tr("QpassX"),
                            tr("An error occurred while creating the database"),QMessageBox::Ok);
    }
}
