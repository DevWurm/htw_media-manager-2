//
// Created by devwurm on 24.06.17.
//

#include <QVariant>
#include "ContactTableModel.h"

int ContactTableModel::columnCount(const QModelIndex &parent) const {
    return 2;
}

QVariant ContactTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch(index.column()) {
            case 0: return this->model[index.row()].getFirstname();
            case 1: return this->model[index.row()].getLastname();
        }
    }
    return QVariant();
}
