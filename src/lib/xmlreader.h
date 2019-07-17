#ifndef XMLREADER_H
#define XMLREADER_H

#include <QObject>
#include <QXmlStreamReader>
#include <QDebug>
#define VERSION = 1.0
#include <QList>

QT_BEGIN_NAMESPACE
class QTreeWidget;
class QTreeWidgetItem;
QT_END_NAMESPACE

class xmlreader
{
public:
    xmlreader();
    ~xmlreader();

    QString errorString() const;

	bool read(QIODevice *device);
    void readGroups(QTreeWidgetItem *item);
    void readElement(QTreeWidgetItem *item);
    void readTitle(QTreeWidgetItem *item);
    QList<QString> getListItems();

	static inline QString versionAttribute() { return QStringLiteral("version"); }

private:
    QXmlStreamReader xml;
    QList<QString> listado;
    //QTreeWidget *treeWidget;
    void readXML();
};
#endif // XMLREADER_H
