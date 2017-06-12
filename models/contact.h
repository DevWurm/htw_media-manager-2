#ifndef HTW_MEDIA_MANAGER_2_CONTACT_H
#define HTW_MEDIA_MANAGER_2_CONTACT_H

#include <QString>

using namespace std;

class contact {
private:
    const QString firstname;
    const QString lastname;
public:
    contact(QString firstname, QString lastname);

    QString getFirstname() const {return firstname;}
    QString getLastname() const {return lastname;}
};

#endif //HTW_MEDIA_MANAGER_2_CONTACT_H
