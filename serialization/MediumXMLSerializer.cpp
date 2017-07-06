//
// Created by devwurm on 06.07.17.
//

#include "MediumXMLSerializer.h"
#include "../exceptions/Exception.h"
#include "../models/domain/Contact.h"
#include "../models/domain/Book.h"
#include "../models/domain/Film.h"
#include <QXmlStreamWriter>
#include <QDomNode>
#include <QFile>
#include <QString>
#include <memory>

using namespace std;

void MediumXMLSerializer::writeItem(QXmlStreamWriter &xmlStreamWriter, const shared_ptr<Medium> &item) {
    xmlStreamWriter.writeTextElement("title", item->getTitle());
    xmlStreamWriter.writeTextElement("creator", item->getCreator());
    xmlStreamWriter.writeTextElement("year", to_string(item->getYear()).c_str());
    xmlStreamWriter.writeTextElement("type", item->getType());

    if (!item->getBorrower().isNull()) {
        xmlStreamWriter.writeTextElement("borrower", item->getBorrower().value<Contact>().getId());
    }
}

shared_ptr<Medium> MediumXMLSerializer::readItem(QDomNode &itemNode) {
    QDomElement title = itemNode.firstChildElement("title");
    QDomElement creator = itemNode.firstChildElement("creator");
    QDomElement year = itemNode.firstChildElement("year");
    QDomElement type = itemNode.firstChildElement("type");
    QDomElement borrower = itemNode.firstChildElement("borrower");

    if (title.isNull() || creator.isNull() || year.isNull() || type.isNull())
        throw Exception("XML is malformed: Expected medium to contain title and creator and year and type");

    if (!borrower.isNull()) {
        for (shared_ptr<Contact> contact: contactData) {
           if (contact->getId() == borrower.text()) {
               if (type.text() == "Book") {
                   return make_shared<Book>(title.text(), creator.text(), year.text().toInt(), *contact);
               } else {
                   return make_shared<Film>(title.text(), creator.text(), year.text().toInt(), *contact);
               }
           }
        }

        throw Exception("Data are inconsistent: Referenced contact is not available");
    }

    if (type.text() == "Book") {
        return make_shared<Book>(title.text(), creator.text(), year.text().toInt());
    } else {
        return make_shared<Film>(title.text(), creator.text(), year.text().toInt());
    }
}