//
// Created by devwurm on 26.06.17.
//

#ifndef HTW_MEDIA_MANAGER_2_COLLECTIONMODEL_H

#include <memory>
#include <QAbstractTableModel>
#include <QList>

using namespace std;

template <class T>
class AbstractListModel: public QAbstractTableModel {
protected:
    QList<shared_ptr<T>>& model;

public:
    AbstractListModel(QList<shared_ptr<T>>& model, QObject * parent = 0): QAbstractTableModel(parent), model(model){};

    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const = 0;
    QVariant data(const QModelIndex &index, int role) const = 0;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const = 0;

    void addRow(const shared_ptr<T>& value);
    void removeRow(const int row);
};

template <class T>
int AbstractListModel<T>::rowCount(const QModelIndex &parent) const {
    return model.size();
}

template <class T>
void AbstractListModel<T>::addRow(const shared_ptr<T> &value) {
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

#define HTW_MEDIA_MANAGER_2_COLLECTIONMODEL_H
#endif //HTW_MEDIA_MANAGER_2_COLLECTIONMODEL_H
