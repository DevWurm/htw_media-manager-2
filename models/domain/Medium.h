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

#ifndef HTW_MEDIA_MANAGER_2_MEDIUM_H
#define HTW_MEDIA_MANAGER_2_MEDIUM_H

#include <QString>
#include <QVariant>
#include "Contact.h"

using namespace std;

class Medium {
private:
    const QString title;
    const QString creator;
    const int year;
    QVariant borrower;
public:
    Medium(QString title, QString creator, int year);
    Medium(QString title, QString creator, int year, Contact borrower);

    virtual QString getType() const = 0;
    void setBorrower(const Contact& borrower) { this->borrower.setValue(borrower); }
    void removeBorrower() { this->borrower.clear(); }
    QString getTitle() const { return this->title; }
    QString getCreator() const { return this->creator; }
    int getYear() const { return this->year; }
    const QVariant& getBorrower() const { return this->borrower; }
};

#endif //HTW_MEDIA_MANAGER_2_MEDIUM_H
