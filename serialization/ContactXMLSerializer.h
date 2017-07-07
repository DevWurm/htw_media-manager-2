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

#ifndef HTW_MEDIA_MANAGER_2_CONTACTXMLSERIALIZER_H

#include "AbstractXMLModelSerializer.h"
#include "../models/domain/Contact.h"
#include <memory>
#include <QFile>
#include <QDomNode>

using namespace std;

/**
 * Implementation of an AbstractXMLModelSerializer for Contact model data
 */
class ContactXMLSerializer: public AbstractXMLModelSerializer<shared_ptr<Contact>> {
protected:
    void writeItem(QXmlStreamWriter &xmlStreamWriter, const shared_ptr<Contact> &item);
    shared_ptr<Contact> readItem(QDomNode &itemNode);

public:
    ContactXMLSerializer(QString modelTag, QString itemTag): AbstractXMLModelSerializer(modelTag, itemTag) {};

    /**
     * Static method for serializing a contact item into a XML stream
     * @param xmlStreamWriter The target XML stream
     * @param item The source item
     */
    static void writeContactItem(QXmlStreamWriter &xmlStreamWriter, Contact &item);

    /**
     * Static method for deserializing a Contact from a Dom Node
     * @param itemNode The items DOM node
     * @return The deserialized Contact
     */
    static Contact readContactItem(QDomNode &itemNode);
};

#define HTW_MEDIA_MANAGER_2_CONTACTXMLSERIALIZER_H
#endif //HTW_MEDIA_MANAGER_2_CONTACTXMLSERIALIZER_H
