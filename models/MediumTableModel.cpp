//
// Created by devwurm on 24.06.17.
//

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
    if (index.column() != 4)
        return QAbstractItemModel::flags(index);

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}
