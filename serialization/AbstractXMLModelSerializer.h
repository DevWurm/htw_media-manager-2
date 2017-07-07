/*
    MIT License
    Copyright (c) 2017 Leo Lindhorst
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

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
