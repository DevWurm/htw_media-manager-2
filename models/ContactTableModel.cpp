//
// Created by devwurm on 24.06.17.
//

#include "ContactTableModel.h"

int ContactTableModel::rowCount(const QModelIndex &parent) const {
    return this->contacts.size();
}

int ContactTableModel::columnCount(const QModelIndex &parent) const {
    return 2;
}

QVariant ContactTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch(index.column()) {
            case 0: return this->contacts[index.row()].getFirstname();
            case 1: return this->contacts[index.row()].getLastname();
        }
    }
    return QVariant();
}
