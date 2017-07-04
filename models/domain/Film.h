//
// Created by devwurm on 29.06.17.
//

#ifndef HTW_MEDIA_MANAGER_2_FILM_H
#define HTW_MEDIA_MANAGER_2_FILM_H

#include "Medium.h"
#include "Contact.h"
#include <QString>

class Film: public Medium {
public:
    Film(QString title, QString creator, int year): Medium(title, creator, year) {};
    Film(QString title, QString creator, int year, Contact borrower): Medium(title, creator, year, borrower) {};

    QString getType() const {
        return QString("Film");
    }
};

#endif //HTW_MEDIA_MANAGER_2_FILM_H
