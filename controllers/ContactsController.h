//
// Created by devwurm on 26.06.17.
//

#ifndef HTW_MEDIA_MANAGER_2_CONTACTSCONTROLLER_H
#define HTW_MEDIA_MANAGER_2_CONTACTSCONTROLLER_H

#include <QAbstractButton>
#include <QLineEdit>
#include <QObject>
#include <QTableView>

#include "AbstractTableViewController.h"
#include "../models/AbstractListModel.h"
#include "../models/domain/Contact.h"
#include "../ui_media-manager.h"

class ContactsController: public AbstractTableViewController<Contact> {
    Q_OBJECT;
private:
    QLineEdit &firstnameInput;
    QLineEdit &lastnameInput;
public:
    ContactsController(QPushButton &addContactButton,
                       QPushButton &deleteContactsButton,
                       QLineEdit &firstnameInput,
                       QLineEdit &lastnameInput,
                       QTableView &contactsTable,
                       AbstractListModel<Contact> &model
    ) : AbstractTableViewController(
            addContactButton,
            deleteContactsButton,
            model,
            contactsTable
        ),
        firstnameInput(firstnameInput),
        lastnameInput(lastnameInput)
        {};

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
    void addItem();
};

#endif //HTW_MEDIA_MANAGER_2_CONTACTSCONTROLLER_H
