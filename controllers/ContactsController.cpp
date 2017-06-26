//
// Created by devwurm on 26.06.17.
//

#include <QModelIndexList>
#include <QModelIndex>

#include "../models/domain/Contact.h"
#include "ContactsController.h"

void ContactsController::addContact() {
    model.addRow(Contact(
        firstnameInput.text(),
        lastnameInput.text()
    ));

    firstnameInput.clear();
    lastnameInput.clear();
};

void ContactsController::deleteContacts() {
    QModelIndexList selection = contactsTable.selectionModel()->selectedRows();

    for (QModelIndex index: selection) {
        model.removeRow(index.row());
    }
};
