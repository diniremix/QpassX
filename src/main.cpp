#include "qpassx.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QpassX w;
  w.show();

  return a.exec();
}
