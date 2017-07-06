//
// Created by devwurm on 05.07.17.
//

#ifndef HTW_MEDIA_MANAGER_2_ABSTRACTCSVMODELSERIALIZER_H

#include <QString>
#include <QDomDocument>
#include <QXmlStreamWriter>
#include <QFile>
#include "../exceptions/Exception.h"

template <class T>
class AbstractXMLModelSerializer {
private:
    QString modelTag;
    QString itemTag;

protected:
    virtual void writeItem(QXmlStreamWriter &xmlStreamWriter, const T &item) = 0;
    virtual T readItem(QDomNode &itemNode) = 0;

public:
    AbstractXMLModelSerializer(
        QString modelTag,
        QString itemTag
    ): modelTag(modelTag), itemTag(itemTag) {};

    void serialize(QList<T> &source, QFile &dest);
    void deserialize(QFile &source, QList<T> &dest);
};

template <class T>
void AbstractXMLModelSerializer<T>::serialize(QList <T> &source, QFile &dest) {
    QXmlStreamWriter xml;
    xml.setDevice(&dest);

    xml.writeStartElement(modelTag);

    for (T &item: source) {
        xml.writeStartElement(itemTag);
        writeItem(xml, item);
        xml.writeEndElement();
    }

    xml.writeEndElement();
}

template <class T>
void AbstractXMLModelSerializer<T>::deserialize(QFile &source, QList <T> &dest) {
    QDomDocument doc;

    if(!doc.setContent(&source))
        throw Exception("Could not parse XML");

    QDomNodeList modelNodes = doc.elementsByTagName(modelTag);
    for (int i = 0; i < modelNodes.size(); i++) {
        QDomNodeList itemNodes = modelNodes.item(i).toElement().elementsByTagName(itemTag);
        for (int j = 0; j < itemNodes.size(); j++) {
            QDomNode itemNode = itemNodes.item(j);
            T item = readItem(itemNode);
            dest.append(item);
        }
    }
}

#define HTW_MEDIA_MANAGER_2_ABSTRACTCSVMODELSERIALIZER_H
#endif //HTW_MEDIA_MANAGER_2_ABSTRACTCSVMODELSERIALIZER_H
