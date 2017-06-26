//
// Created by devwurm on 26.06.17.
//

#ifndef HTW_MEDIA_MANAGER_2_CONTACTSCONTROLLER_H
#define HTW_MEDIA_MANAGER_2_CONTACTSCONTROLLER_H

#include <QAbstractButton>
#include <QLineEdit>
#include <QObject>

#include "../models/AbstractListModel.h"
#include "../models/domain/Contact.h"
#include "../ui_media-manager.h"

class ContactsController: public QObject {
    Q_OBJECT;
private:
    QAbstractButton &addContactButton;
    QAbstractButton &deleteContactsButton;
    QLineEdit &firstnameInput;
    QLineEdit &lastnameInput;
    QTableView &contactsTable;
    AbstractListModel<Contact> &model;
public:
    ContactsController(QPushButton &addContactButton,
                       QPushButton &deleteContactsButton,
                       QLineEdit &firstnameInput,
                       QLineEdit &lastnameInput,
                       QTableView &contactsTable,
                       AbstractListModel<Contact> &model
    ) : addContactButton(addContactButton),
        deleteContactsButton(deleteContactsButton),
        firstnameInput(firstnameInput),
        lastnameInput(lastnameInput),
        contactsTable(contactsTable),
        model(model) {

        QObject::connect(&addContactButton, SIGNAL(clicked()), this, SLOT(addContact()));
        QObject::connect(&deleteContactsButton, SIGNAL(clicked()), this, SLOT(deleteContacts()));
    };

    ContactsController(Ui_MediaManager& ui, AbstractListModel<Contact> &model):
            ContactsController(
                *(ui.add_contact_button),
                *(ui.delete_contact_button),
                *(ui.firstname_input),
                *(ui.lastname_input),
                *(ui.contacts_table),
                model
            ){};

public slots:
    void addContact();
    void deleteContacts();
};

#endif //HTW_MEDIA_MANAGER_2_CONTACTSCONTROLLER_H
