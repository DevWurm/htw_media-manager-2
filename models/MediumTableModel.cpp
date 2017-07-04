//
// Created by devwurm on 24.06.17.
//

#include <QVariant>
#include "MediumTableModel.h"

int MediumTableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant MediumTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch(index.column()) {
            case 0: return this->model[index.row()]->getTitle();
            case 1: return this->model[index.row()]->getCreator();
            case 2: return this->model[index.row()]->getYear();
            case 3: return this->model[index.row()]->getType();
        }
    }
    return QVariant();
}

QVariant MediumTableModel::headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch(section) {
            case 0: return QString("Title");
            case 1: return QString("Creator");
            case 2: return QString("Year");
            case 3: return QString("Type");
            case 4: return QString("Borrower");
        }
    }
    return QVariant();
}
