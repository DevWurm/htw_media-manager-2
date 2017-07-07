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

#ifndef HTW_MEDIA_MANAGER_2_COLLECTIONMODEL_H

#include <memory>
#include <QAbstractTableModel>
#include <QList>

using namespace std;

/**
 * Abstract base class for a list based QT model for a TabelView
 * @tparam T The type of the model data
 */
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
