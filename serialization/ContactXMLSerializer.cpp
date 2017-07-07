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
