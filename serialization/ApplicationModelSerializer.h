//
// Created by devwurm on 06.07.17.
//

#ifndef HTW_MEDIA_MANAGER_2_APPLICATIONMODELSERIALIZER_H

#include <QList>
#include <QFile>
#include <memory>
#include "../models/domain/Contact.h"
#include "../models/domain/Medium.h"
#include "ContactXMLSerializer.h"
#include "MediumXMLSerializer.h"

class ApplicationModelSerializer {
private:
    QList <shared_ptr<Contact>> &contactsModel;
    QList <shared_ptr<Medium>> &mediaModel;
    ContactXMLSerializer contactXmlSerializer;
    MediumXMLSerializer mediumXmlSerializer;
public:
    ApplicationModelSerializer(
        QList <shared_ptr<Contact>> &contactsModel,
        QList <shared_ptr<Medium>> &mediaModel
    ) :
        contactsModel(contactsModel),
        mediaModel(mediaModel),
        contactXmlSerializer("contacts", "contact"),
        mediumXmlSerializer(contactsModel, "media", "medium")
    {};

    void serialize(QFile &dest);
    void deserialize(QFile &source);
};

#define HTW_MEDIA_MANAGER_2_APPLICATIONMODELSERIALIZER_H
#endif //HTW_MEDIA_MANAGER_2_APPLICATIONMODELSERIALIZER_H
