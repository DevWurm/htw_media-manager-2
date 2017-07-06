//
// Created by devwurm on 06.07.17.
//

#ifndef HTW_MEDIA_MANAGER_2_MEDIUMXMLSERIALIZER_H

#include <memory>
#include "AbstractXMLModelSerializer.h"
#include "../models/domain/Medium.h"

using namespace std;

class MediumXMLSerializer: public AbstractXMLModelSerializer<shared_ptr<Medium>> {
private:
    QList<shared_ptr<Contact>> &contactData;
protected:
    void writeItem(QXmlStreamWriter &xmlStreamWriter, const shared_ptr<Medium> &item);
    shared_ptr<Medium> readItem(QDomNode &itemNode);

public:
    MediumXMLSerializer(QList<shared_ptr<Contact>> &contactData, QString modelTag, QString itemTag):
        AbstractXMLModelSerializer(modelTag, itemTag), contactData(contactData)  {};
};

#define HTW_MEDIA_MANAGER_2_MEDIUMXMLSERIALIZER_H
#endif //HTW_MEDIA_MANAGER_2_MEDIUMXMLSERIALIZER_H
