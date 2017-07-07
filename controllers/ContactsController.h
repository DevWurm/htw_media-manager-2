/*
    MIT License
    Copyright (c) 2017 Leo Lindhorst
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

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
