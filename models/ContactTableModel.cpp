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
