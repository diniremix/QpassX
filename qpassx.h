#ifndef QPASSX_H
#define QPASSX_H

#include <QMainWindow>
#include "qdatabase.h"
#include <QFileDialog>

#include "formnew.h"


namespace Ui {
  class QpassX;
}

class QpassX : public QMainWindow
{
  Q_OBJECT

public:
  explicit QpassX(QWidget *parent = 0);
  ~QpassX();

private slots:
  void on_actionQuit_triggered();

  void on_actionNew_triggered();

  void on_actionOpen_triggered();

  void on_actionClear_history_triggered();

  void on_actionChange_password_triggered();

  void on_actionDatabase_settings_triggered();

  void on_actionImport_from_triggered();

  void on_actionExport_database_triggered();

  void on_actionSettings_triggered();

  void on_actionAbout_triggered();

  void on_actionCheck_for_updates_triggered();

  void on_actionFind_triggered();

  void on_actionEdit_entry_triggered();

  void on_actionDelete_entry_triggered();

  void on_actionNew_entry_triggered();

  void on_actionCopy_username_triggered();

  void on_actionCopy_password_triggered();

  void on_actionOpen_url_triggered();

private:
  Ui::QpassX *ui;
  QDatabase *db;
};

#endif // QPASSX_H
