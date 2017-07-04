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
            case 0: return this->model[index.row()]->getFirstname();
            case 1: return this->model[index.row()]->getLastname();
        }
    }
    return QVariant();
}

QVariant ContactTableModel::headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch(section) {
            case 0: return QString("First Name");
            case 1: return QString("Last Name");
        }
    }
    return QVariant();
}
