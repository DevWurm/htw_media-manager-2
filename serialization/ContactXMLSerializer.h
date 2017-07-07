//
// Created by devwurm on 05.07.17.
//

#ifndef HTW_MEDIA_MANAGER_2_CONTACTXMLSERIALIZER_H

#include "AbstractXMLModelSerializer.h"
#include "../models/domain/Contact.h"
#include <memory>
#include <QFile>
#include <QDomNode>

using namespace std;

class ContactXMLSerializer: public AbstractXMLModelSerializer<shared_ptr<Contact>> {
protected:
    void writeItem(QXmlStreamWriter &xmlStreamWriter, const shared_ptr<Contact> &item);
    shared_ptr<Contact> readItem(QDomNode &itemNode);

public:
    ContactXMLSerializer(QString modelTag, QString itemTag): AbstractXMLModelSerializer(modelTag, itemTag) {};
    static void writeContactItem(QXmlStreamWriter &xmlStreamWriter, Contact &item);
    static Contact readContactItem(QDomNode &itemNode);
};

#define HTW_MEDIA_MANAGER_2_CONTACTXMLSERIALIZER_H
#endif //HTW_MEDIA_MANAGER_2_CONTACTXMLSERIALIZER_H
