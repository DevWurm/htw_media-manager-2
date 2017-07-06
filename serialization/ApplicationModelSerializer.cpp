//
// Created by devwurm on 06.07.17.
//

#include <QFile>
#include <QDomDocument>
#include <QXmlStreamWriter>
#include "../exceptions/Exception.h"
#include "ApplicationModelSerializer.h"

using namespace std;

void ApplicationModelSerializer::serialize(QFile &dest) {
    if (!dest.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
        throw Exception("Could not open data file");

    try {
        QXmlStreamWriter writer;
        writer.setDevice(&dest);

        writer.writeStartElement("htw-media-manager-data");
        contactXmlSerializer.serialize(contactsModel, writer);
        mediumXmlSerializer.serialize(mediaModel, writer);
        writer.writeEndElement();
    } catch (Exception e) {
        dest.close();
        throw e;
    }
}

void ApplicationModelSerializer::deserialize(QFile &source) {
    if (!source.exists() || source.size() == 0)
        return;

    if (!source.open(QIODevice::ReadOnly | QIODevice::Text))
        throw Exception("Could not open data file");

    try {
        QDomDocument doc;
        if (!doc.setContent(&source))
            throw Exception("Could not parse XML");

        contactXmlSerializer.deserialize(doc, contactsModel);
        mediumXmlSerializer.deserialize(doc, mediaModel);
    } catch (Exception e) {
        source.close();
        throw e;
    }
}