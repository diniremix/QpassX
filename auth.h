#ifndef AUTH_H
#define AUTH_H

#include <QCryptographicHash>
#include <QString>
#include <QDateTime>
#include <QDebug>

class Auth
{
public:
  Auth();
  QString generateKey(QString _key);
  bool isValidKey(QString key, QString compkey);
  QString getTimeStamp();
private:
  QString generateHash(QString _hash);
};

#endif // AUTH_H
