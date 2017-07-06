//
// Created by devwurm on 05.07.17.
//

#ifndef HTW_MEDIA_MANAGER_2_ABSTRACTCSVMODELSERIALIZER_H

#include <QString>
#include <QDomDocument>
#include <QXmlStreamWriter>
#include "../exceptions/Exception.h"

using namespace std;

template<class T>
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
    ) : modelTag(modelTag), itemTag(itemTag) {};

    void serialize(QList <T> &source, QXmlStreamWriter &dest);
    void deserialize(QDomDocument &source, QList <T> &dest);
};

template<class T>
void AbstractXMLModelSerializer<T>::serialize(QList <T> &source, QXmlStreamWriter &dest) {
    dest.writeStartElement(modelTag);

    for (T &item: source) {
        dest.writeStartElement(itemTag);
        writeItem(dest, item);
        dest.writeEndElement();
    }

    dest.writeEndElement();
}

template<class T>
void AbstractXMLModelSerializer<T>::deserialize(QDomDocument &source, QList <T> &dest) {
    QDomNodeList modelNodes = source.elementsByTagName(modelTag);
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
