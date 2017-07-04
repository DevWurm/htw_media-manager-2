//
// Created by devwurm on 26.06.17.
//
#include <memory>

#include "../models/domain/Contact.h"
#include "ContactsController.h"

using namespace std;

void ContactsController::addItem() {
    shared_ptr <Contact> contact = make_shared<Contact>(
        firstnameInput.text(),
        lastnameInput.text()
    );
    model.addRow(contact);

    firstnameInput.clear();
    lastnameInput.clear();
};

