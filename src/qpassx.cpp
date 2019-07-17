#include "qpassx.h"
#include "ui_qpassx.h"

QpassX::QpassX(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::QpassX)
{
  ui->setupUi(this);
  db = new QDatabase();

}

QpassX::~QpassX()
{
  delete ui;
}

void QpassX::on_actionQuit_triggered()
{
  this->close();
}

void QpassX::on_actionNew_triggered()
{


  formnew *formnewdb = new formnew();
  formnewdb->show();
}

void QpassX::on_actionOpen_triggered()
{
  qDebug() << "on_actionOpen_triggered";
  QString fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Open QpassX QDatabase"), "",
                                                  tr("QpassX Databse (*.qdbx);;All Files (*)"));
  if (fileName.isEmpty()){
      return;
    }else {
      // open db
      if(db->openDB(fileName)){
        //loadScheme();
         QList<QString> tables, fields;
         tables << "qpassxscheme";
         fields << "usrnm" << "psswd";
         //mylist.append("jorge");
         QString qpass= "jorge1";
         //db->select(tables, fields,"psswd="+qpass);
         int result;

         result= db->execQuery(tr("select usrnm, psswd from qpassxscheme where psswd='%1'").arg(qpass),"");
         if(result==true){
             qDebug() << "result:"<<result;
         }else{
             qDebug() << "result: fail no es valid";
           }

      }else{

      };
    }

}

void QpassX::on_actionClear_history_triggered()
{

}

void QpassX::on_actionChange_password_triggered()
{

}

void QpassX::on_actionDatabase_settings_triggered()
{

}

void QpassX::on_actionImport_from_triggered()
{

}

void QpassX::on_actionExport_database_triggered()
{
  qDebug() << "on_actionExport_database_triggered";
}

void QpassX::on_actionSettings_triggered()
{

}

void QpassX::on_actionAbout_triggered()
{

}

void QpassX::on_actionCheck_for_updates_triggered()
{

}

void QpassX::on_actionFind_triggered()
{
  qDebug() << "on_actionFind_triggered";
  //db->search("users", 1);
  QList<QString> tables, fields;
  //tables << "users" << "information";
  fields << "one" << "two" << "three";
  //mylist.append("jorge");

  db->select(tables, fields,"id=1");

}

void QpassX::on_actionEdit_entry_triggered()
{

}

void QpassX::on_actionDelete_entry_triggered()
{
    qDebug() << "on_actionDelete_entry_triggered";
}

void QpassX::on_actionNew_entry_triggered()
{
    qDebug() << "on_actionNew_entry_triggered";
    QTreeWidgetItem *groups = new QTreeWidgetItem(ui->treeWidget);
    groups->setText(0, tr("Cities"));
    groups->setFlags(groups->flags()|Qt::ItemIsEditable);



    //groups->setFlags(eflag);
    /*QTreeWidgetItem *osloItem = new QTreeWidgetItem(cities);
        osloItem->setText(0, tr("Oslo"));*/

}

void QpassX::on_actionCopy_username_triggered()
{

}

void QpassX::on_actionCopy_password_triggered()
{

}

void QpassX::on_actionOpen_url_triggered()
{

}

void QpassX::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    qDebug() << "on_treeWidget_itemClicked";
}

void QpassX::on_treeWidget_itemChanged(QTreeWidgetItem *item, int column)
{
    /*qDebug() << "on_treeWidget_itemChanged"<<"col"<<column<<"texto"<<item->text(column);
    Qt::ItemFlags fl = item->flags();
    qDebug() << fl;*/
}

void QpassX::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    qDebug() << "on_treeWidget_currentItemChanged"<< current->text(0);
}
