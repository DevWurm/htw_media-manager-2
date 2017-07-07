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

#include "MediumXMLSerializer.h"
#include "../exceptions/Exception.h"
#include "../models/domain/Contact.h"
#include "../models/domain/Book.h"
#include "../models/domain/Film.h"
#include "ContactXMLSerializer.h"
#include <QXmlStreamWriter>
#include <QDomNode>
#include <QFile>
#include <QString>
#include <memory>

#include <iostream>

using namespace std;

void MediumXMLSerializer::writeItem(QXmlStreamWriter &xmlStreamWriter, const shared_ptr<Medium> &item) {
    xmlStreamWriter.writeTextElement("title", item->getTitle());
    xmlStreamWriter.writeTextElement("creator", item->getCreator());
    xmlStreamWriter.writeTextElement("year", to_string(item->getYear()).c_str());
    xmlStreamWriter.writeTextElement("type", item->getType());

    if (!item->getBorrower().isNull()) {
        for (shared_ptr<Contact> contact: contactData) {
            if (contact->getId() == item->getBorrower().value<Contact>().getId()) {
                xmlStreamWriter.writeTextElement("borrower", contact->getId());
                return;
            }
        }

        xmlStreamWriter.writeStartElement("borrower");
        Contact borrower = item->getBorrower().value<Contact>();
        ContactXMLSerializer::writeContactItem(xmlStreamWriter, borrower);
        xmlStreamWriter.writeEndElement();
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

    if (borrower.isNull()) {
        return MediumXMLSerializer::createMedium(type.text(), title.text(), creator.text(), year.text().toInt());
    } else if (borrower.firstChild().isText()) {
        for (shared_ptr<Contact> contact: contactData) {
            if (contact->getId() == borrower.text()) {
                return MediumXMLSerializer::createMedium(type.text(), title.text(), creator.text(), year.text().toInt(), *contact);
            }
        }
        throw Exception("Data are inconsistent: Referenced contact is not available");
    } else {
        Contact borrowerContact = ContactXMLSerializer::readContactItem(borrower);
        return MediumXMLSerializer::createMedium(type.text(), title.text(), creator.text(), year.text().toInt(), borrowerContact);
    }
}

shared_ptr<Medium> MediumXMLSerializer::createMedium(QString type, QString title, QString creator, int year) {
    if (type == "Book") {
        return make_shared<Book>(title, creator, year);
    } else {
        return make_shared<Film>(title, creator, year);
    }
}

shared_ptr<Medium> MediumXMLSerializer::createMedium(QString type, QString title, QString creator, int year, Contact &borrower) {
    if (type == "Book") {
        return make_shared<Book>(title, creator, year, borrower);
    } else {
        return make_shared<Film>(title, creator, year, borrower);
    }
}
