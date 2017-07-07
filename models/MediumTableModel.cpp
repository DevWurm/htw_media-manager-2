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

#include <QVariant>
#include "domain/Contact.h"
#include "MediumTableModel.h"

int MediumTableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant MediumTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0:
                return this->model[index.row()]->getTitle();
            case 1:
                return this->model[index.row()]->getCreator();
            case 2:
                return this->model[index.row()]->getYear();
            case 3:
                return this->model[index.row()]->getType();
            case 4: {
                const QVariant &borrowerVariant = this->model[index.row()]->getBorrower();
                if (borrowerVariant.isNull())
                    return QString("none");

                const Contact borrower = borrowerVariant.value<Contact>();
                return borrower.getFirstname() + QString(" ") + borrower.getLastname();
            }
        }
    }
    else if (role == Qt::EditRole) {
        switch (index.column()) {
            case 4:
                return this->model[index.row()]->getBorrower();
        }
    }
    return QVariant();
}

QVariant MediumTableModel::headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("Title");
            case 1:
                return QString("Creator");
            case 2:
                return QString("Year");
            case 3:
                return QString("Type");
            case 4:
                return QString("Borrower");
        }
    }
    return QVariant();
}

bool MediumTableModel::setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) {
    if (role == Qt::EditRole && index.column() == 4) {
        if (value.isNull()) {
            model[index.row()]->removeBorrower();
            return true;
        }

        const Contact contact = value.value<Contact>();
        model[index.row()]->setBorrower(contact);
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags MediumTableModel::flags(const QModelIndex &index) const {
    // make column 4 (borrower) editable to allow the borrower association
    if (index.column() != 4)
        return QAbstractItemModel::flags(index);

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}
