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
