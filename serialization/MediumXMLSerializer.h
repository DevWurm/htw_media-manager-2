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

#ifndef HTW_MEDIA_MANAGER_2_MEDIUMXMLSERIALIZER_H

#include <memory>
#include "AbstractXMLModelSerializer.h"
#include "../models/domain/Medium.h"
#include "../models/domain/Contact.h"

using namespace std;

/**
 * Implementation of an AbstractXMLModelSerializer for Medium model data
 */
class MediumXMLSerializer: public AbstractXMLModelSerializer<shared_ptr<Medium>> {
private:
    QList<shared_ptr<Contact>> &contactData; // contact model data, to find the asociated borrowers

    /**
     * Helper method for constructing a medium of the specified type without a borrower
     */
    static shared_ptr<Medium> createMedium(QString type, QString title, QString creator, int year);

    /**
     * Helper method for constructing a medium of the specified type with a borrower
     */
    static shared_ptr<Medium> createMedium(QString type, QString title, QString creator, int year, Contact &borrower);
protected:
    void writeItem(QXmlStreamWriter &xmlStreamWriter, const shared_ptr<Medium> &item);
    shared_ptr<Medium> readItem(QDomNode &itemNode);

public:
    MediumXMLSerializer(QList<shared_ptr<Contact>> &contactData, QString modelTag, QString itemTag):
        AbstractXMLModelSerializer(modelTag, itemTag), contactData(contactData)  {};
};

#define HTW_MEDIA_MANAGER_2_MEDIUMXMLSERIALIZER_H
#endif //HTW_MEDIA_MANAGER_2_MEDIUMXMLSERIALIZER_H
