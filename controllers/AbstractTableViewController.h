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

#ifndef HTW_MEDIA_MANAGER_2_ABSTRACTTABLEVIEWCONTROLLER_H

#include <QObject>
#include <QTableView>
#include <QAbstractButton>

#include "../models/AbstractListModel.h"
#include "AbstractTableViewSingalSlots.h"

/**
 * Abstract base class for a controller which connects the model data of a TableView to corresponding form elements
 * @tparam S The type of the model data
 */
template<class S>
class AbstractTableViewController: public AbstractTableViewSignalSlots {
protected:
    QAbstractButton &addItemButton;
    QAbstractButton &deleteItemButton;
    AbstractListModel<S> &model;
    QTableView &table;
public:
    AbstractTableViewController(
        QAbstractButton &addItemButton,
        QAbstractButton &deleteItemButton,
        AbstractListModel<S> &model,
        QTableView &table
    ) : addItemButton(addItemButton),
        deleteItemButton(deleteItemButton),
        model(model),
        table(table) {
        QObject::connect(&addItemButton, SIGNAL(clicked()), this, SLOT(addItem()));
        QObject::connect(&deleteItemButton, SIGNAL(clicked()), this, SLOT(deleteItem()));
    }

    /**
     * Default implementation for deleting the currently selected item from the TableView
     */
    virtual void deleteItem();
};

template <class S>
void AbstractTableViewController<S>::deleteItem() {
    QModelIndexList selection = table.selectionModel()->selectedRows();

    if (selection.size() > 0) {
        model.removeRow(selection[0].row());
    }
};

#define HTW_MEDIA_MANAGER_2_ABSTRACTTABLEVIEWCONTROLLER_H
#endif //HTW_MEDIA_MANAGER_2_ABSTRACTTABLEVIEWCONTROLLER_H
