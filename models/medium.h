#ifndef HTW_MEDIA_MANAGER_2_MEDIUM_H
#define HTW_MEDIA_MANAGER_2_MEDIUM_H

#include <QString>
#include "contact.h"
#include "../util/optional.h"

using namespace std;

class medium {
private:
    const QString title;
    const QString creator;
    const int year;
    optional<const contact> borrower;
public:
    medium(QString title, QString creator, int year);
    medium(QString title, QString creator, int year, contact borrower);

    virtual QString getType() const = 0;
    void setBorrower(const contact& borrower) { this->borrower.setValue(borrower); }
    void removeBorrower() { this->borrower.removeValue(); }
    QString getTitle() const { return this->title; }
    QString getCreator() const { return this->creator; }
    int getYear() const { return this->year; }
    const optional<const contact>& getBorrower() const { return this->borrower; }
};

#endif //HTW_MEDIA_MANAGER_2_MEDIUM_H
