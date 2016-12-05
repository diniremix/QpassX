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
