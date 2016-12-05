#include "qpassx.h"
#include "ui_qpassx.h"

QpassX::QpassX(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::QpassX)
{
  ui->setupUi(this);
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

}

void QpassX::on_actionOpen_triggered()
{

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

}

void QpassX::on_actionEdit_entry_triggered()
{

}

void QpassX::on_actionDelete_entry_triggered()
{

}

void QpassX::on_actionNew_entry_triggered()
{

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
