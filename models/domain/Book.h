//
// Created by devwurm on 29.06.17.
//

#ifndef HTW_MEDIA_MANAGER_2_BOOK_H
#define HTW_MEDIA_MANAGER_2_BOOK_H

#include "Medium.h"
#include "Contact.h"
#include <QString>

class Book: public Medium {
public:
    Book(QString title, QString creator, int year): Medium(title, creator, year) {};
    Book(QString title, QString creator, int year, Contact borrower): Medium(title, creator, year, borrower) {};

    QString getType() const {
        return QString("Book");
    }
};

#endif //HTW_MEDIA_MANAGER_2_BOOK_H
