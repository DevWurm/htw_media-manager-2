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

#include <iostream>

using namespace std;

void ContactXMLSerializer::writeItem(QXmlStreamWriter &xmlStreamWriter, const shared_ptr <Contact> &item) {
    xmlStreamWriter.writeTextElement("firstname", item->getFirstname());
    xmlStreamWriter.writeTextElement("lastname", item->getLastname());
}

shared_ptr<Contact> ContactXMLSerializer::readItem(QDomNode &itemNode) {
    QDomElement firstname = itemNode.firstChildElement("firstname");
    QDomElement lastname = itemNode.firstChildElement("lastname");

    if (firstname.isNull() || lastname.isNull())
        throw Exception("XML is malformed: Expected Contact to contain firstname and lastname");

    return make_shared<Contact>(firstname.text(), lastname.text());
}