#ifndef HTW_MEDIA_MANAGER_2_CONTACT_H
#define HTW_MEDIA_MANAGER_2_CONTACT_H

#include <QString>
#include <QVariant>

using namespace std;

class Contact {
private:
    const QString firstname;
    const QString lastname;
public:
    Contact(): Contact(QString(), QString()){};
    Contact(QString firstname, QString lastname);
    Contact(const Contact& contact): Contact(contact.firstname, contact.lastname){};
    ~Contact(){};

    QString getFirstname() const {return firstname;}
    QString getLastname() const {return lastname;}
};

Q_DECLARE_METATYPE(Contact);

#endif //HTW_MEDIA_MANAGER_2_CONTACT_H