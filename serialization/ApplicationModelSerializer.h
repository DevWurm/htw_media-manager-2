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

#ifndef HTW_MEDIA_MANAGER_2_APPLICATIONMODELSERIALIZER_H

#include <QList>
#include <QFile>
#include <memory>
#include "../models/domain/Contact.h"
#include "../models/domain/Medium.h"
#include "ContactXMLSerializer.h"
#include "MediumXMLSerializer.h"

/**
 * Class for serializing/deserializing the application model data into a file
 */
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

    /**
     * Serialize the current applications model data into to a destination file
     * @param dest The destination file
     */
    void serialize(QFile &dest);

    /**
     * Deserialize the content of the source file into the current application model data
     * @param source The source file
     */
    void deserialize(QFile &source);
};

#define HTW_MEDIA_MANAGER_2_APPLICATIONMODELSERIALIZER_H
#endif //HTW_MEDIA_MANAGER_2_APPLICATIONMODELSERIALIZER_H
