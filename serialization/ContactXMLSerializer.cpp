//
// Created by devwurm on 05.07.17.
//

#include "ContactXMLSerializer.h"
#include "../exceptions/Exception.h"
#include <QXmlStreamWriter>
#include <QDomNode>
#include <QFile>
#include <QString>
#include <memory>

using namespace std;

void ContactXMLSerializer::writeItem(QXmlStreamWriter &xmlStreamWriter, const shared_ptr <Contact> &item) {
    ContactXMLSerializer::writeContactItem(xmlStreamWriter, *item);
}

shared_ptr<Contact> ContactXMLSerializer::readItem(QDomNode &itemNode) {
    return make_shared<Contact>(ContactXMLSerializer::readContactItem(itemNode));
}

void ContactXMLSerializer::writeContactItem(QXmlStreamWriter &xmlStreamWriter, Contact &item) {
    xmlStreamWriter.writeTextElement("id", item.getId());
    xmlStreamWriter.writeTextElement("firstname", item.getFirstname());
    xmlStreamWriter.writeTextElement("lastname", item.getLastname());
}

Contact ContactXMLSerializer::readContactItem(QDomNode &itemNode) {
    QDomElement id = itemNode.firstChildElement("id");
    QDomElement firstname = itemNode.firstChildElement("firstname");
    QDomElement lastname = itemNode.firstChildElement("lastname");

    if (id.isNull() || firstname.isNull() || lastname.isNull())
        throw Exception("XML is malformed: Expected Contact to contain id and firstname and lastname");

    return Contact(id.text(), firstname.text(), lastname.text());
}
