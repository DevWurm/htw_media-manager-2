//
// Created by devwurm on 26.06.17.
//

#ifndef HTW_MEDIA_MANAGER_2_COLLECTIONMODEL_H
#define HTW_MEDIA_MANAGER_2_COLLECTIONMODEL_H

#include <QAbstractTableModel>
#include <QList>

template <class T>
class AbstractListModel: public QAbstractTableModel {
protected:
    QList<T>& model;

public:
    AbstractListModel(QList<T>& model, QObject * parent = 0): QAbstractTableModel(parent), model(model){};

    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const = 0;
    QVariant data(const QModelIndex &index, int role) const = 0;

    void addRow(const T& value);
    void removeRow(const int row);
};

template <class T>
int AbstractListModel<T>::rowCount(const QModelIndex &parent) const {
    return model.size();
}

template <class T>
void AbstractListModel<T>::addRow(const T &value) {
    beginInsertRows(QModelIndex(), model.size(), model.size());

    model.push_back(value);

    endInsertRows();
}

template <class T>
void AbstractListModel<T>::removeRow(const int row) {
    beginRemoveRows(QModelIndex(), row, row);

    model.removeAt(row);

    endRemoveRows();
}

#endif //HTW_MEDIA_MANAGER_2_COLLECTIONMODEL_H
