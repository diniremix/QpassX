#include "auth.h"

Auth::Auth()
{

}

QString Auth::generateHash(QString _hash)
{
  QCryptographicHash chiper256(QCryptographicHash::Sha256);

  QByteArray result =chiper256.hash(_hash.toLocal8Bit(),QCryptographicHash::Sha256);

  return result.toHex();
}

QString Auth::generateKey(QString _key){

  QDateTime UTC(QDateTime::currentDateTimeUtc());
  QString cyear= UTC.toString("yyyy");

  QString _nhash= QString("%1%2%3").arg(cyear).arg(_key).arg("QpassXV1");

  QString hashkey= generateHash(_nhash);

  return hashkey;
}

bool Auth::isValidKey(QString key, QString compkey){
  return (key == compkey);
}

QString Auth::getTimeStamp(){
  QDateTime UTC(QDateTime::currentDateTimeUtc());
  QDateTime local(UTC.toLocalTime());
  return local.toString("yyyyMMddHHmmss");
}
