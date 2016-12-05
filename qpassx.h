#ifndef QPASSX_H
#define QPASSX_H

#include <QMainWindow>

namespace Ui {
  class QpassX;
}

class QpassX : public QMainWindow
{
  Q_OBJECT

public:
  explicit QpassX(QWidget *parent = 0);
  ~QpassX();

private:
  Ui::QpassX *ui;
};

#endif // QPASSX_H
