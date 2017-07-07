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

#ifndef HTW_MEDIA_MANAGER_2_CONTACT_H
#define HTW_MEDIA_MANAGER_2_CONTACT_H

#include <QString>
#include <QVariant>

using namespace std;

class Contact {
private:
    const QString id;
    const QString firstname;
    const QString lastname;
public:
    Contact(): Contact(QString(), QString()){};
    Contact(QString firstname, QString lastname);
    Contact(QString id, QString firstname, QString lastname);
    Contact(const Contact& contact): Contact(contact.id, contact.firstname, contact.lastname){};
    ~Contact(){};

    QString getId() const { return id;}
    QString getFirstname() const {return firstname;}
    QString getLastname() const {return lastname;}
};

Q_DECLARE_METATYPE(Contact);

#endif //HTW_MEDIA_MANAGER_2_CONTACT_H
