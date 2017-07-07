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

#include <QFile>
#include <QDomDocument>
#include <QXmlStreamWriter>
#include "../exceptions/Exception.h"
#include "ApplicationModelSerializer.h"

using namespace std;

void ApplicationModelSerializer::serialize(QFile &dest) {
    // Serialize the application model data into an empty file using XML
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
    // Deserialize a XML file into the applications model data
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