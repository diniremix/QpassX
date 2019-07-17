#include "xmlreader.h"


xmlreader::xmlreader()
{

}
QString xmlreader::errorString() const
{
    qDebug() << "xmlreader::errorString fn";
    return QObject::tr("%1\nLine %2, column %3")
            .arg(xml.errorString())
            .arg(xml.lineNumber())
            .arg(xml.columnNumber());
}

bool xmlreader::read(QIODevice *device)
{
    qDebug() << "xmlreader::read fn";
    xml.setDevice(device);

    if (xml.readNextStartElement()) {
        if (xml.name() == QLatin1String("qpassx")
                && xml.attributes().value(versionAttribute()) == QLatin1String("1.0")) {
            readXML();
        } else {
            xml.raiseError(QObject::tr("The file is not an QpassX XML version 1.0 file."));
        }
    }

    return !xml.error();
}
void xmlreader::readXML()
{
    qDebug() << "xmlreader::readXML fn";
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("qpassx"));

    while (xml.readNextStartElement()) {
        if (xml.name() == QLatin1String("groups"))
            readGroups(0);
            //readGroups(0);
        else if (xml.name() == QLatin1String("element"))
            readElement(0);
        else
            xml.skipCurrentElement();
    }
}
void xmlreader::readGroups(QTreeWidgetItem *item)
{
    qDebug() << "xmlreader::readGroups fn";
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("groups"));

    /*QTreeWidgetItem *folder = createChildItem(item);
    bool folded = (xml.attributes().value(foldedAttribute()) != QLatin1String("no"));
    folder->setExpanded(!folded);*/

    /*while (xml.readNextStartElement()) {
        if (xml.name() == QLatin1String("title"))
            readTitle(folder);
        else if (xml.name() == QLatin1String("folder"))
            readFolder(folder);
        else if (xml.name() == QLatin1String("bookmark"))
            readBookmark(folder);
        else if (xml.name() == QLatin1String("separator"))
            readSeparator(folder);
        else
            xml.skipCurrentElement();
    }*/
}

void xmlreader::readElement(QTreeWidgetItem *item)
{
    qDebug() << "xmlreader::readElement fn";
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("element"));

    /*QTreeWidgetItem *bookmark = createChildItem(item);
    bookmark->setFlags(bookmark->flags() | Qt::ItemIsEditable);
    bookmark->setIcon(0, bookmarkIcon);
    bookmark->setText(0, QObject::tr("Unknown title"));
    bookmark->setText(1, xml.attributes().value(hrefAttribute()).toString());*/

    while (xml.readNextStartElement()) {
        if (xml.name() == QLatin1String("name"))
            //readTitle(bookmark);
            readTitle(item);
        else
            xml.skipCurrentElement();
    }
}

void xmlreader::readTitle(QTreeWidgetItem *item)
{
    qDebug() << "xmlreader::readTitle fn";
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("name"));

    QString title = xml.readElementText();
    //item->setText(0, title);
    qDebug() << "xmlreader::readTitle title:"<<title;
    listado.append(title);

}

QList<QString> xmlreader::getListItems(){
    qDebug() << "xmlreader::getListItems fn";
    return listado;

}

xmlreader::~xmlreader()
{

}
