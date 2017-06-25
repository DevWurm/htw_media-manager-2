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
