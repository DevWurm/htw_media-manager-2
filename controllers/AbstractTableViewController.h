//
// Created by devwurm on 02.07.17.
//

#ifndef HTW_MEDIA_MANAGER_2_ABSTRACTTABLEVIEWCONTROLLER_H

#include <QObject>
#include <QTableView>
#include <QAbstractButton>

#include "../models/AbstractListModel.h"
#include "AbstractTableViewSingalSlots.h"

template<class S>
class AbstractTableViewController: public AbstractTableViewSignalSlots {
protected:
    QAbstractButton &addItemButton;
    QAbstractButton &deleteItemsButton;
    AbstractListModel<S> &model;
    QTableView &table;
public:
    AbstractTableViewController(
        QAbstractButton &addItemButton,
        QAbstractButton &deleteItemsButton,
        AbstractListModel<S> &model,
        QTableView &table
    ) : addItemButton(addItemButton),
        deleteItemsButton(deleteItemsButton),
        model(model),
        table(table) {
        QObject::connect(&addItemButton, SIGNAL(clicked()), this, SLOT(addItem()));
        QObject::connect(&deleteItemsButton, SIGNAL(clicked()), this, SLOT(deleteItems()));
    }

    virtual void deleteItems();
};

template <class S>
void AbstractTableViewController<S>::deleteItems() {
    QModelIndexList selection = table.selectionModel()->selectedRows();

    for (QModelIndex index: selection) {
        model.removeRow(index.row());
    }
};

#define HTW_MEDIA_MANAGER_2_ABSTRACTTABLEVIEWCONTROLLER_H
#endif //HTW_MEDIA_MANAGER_2_ABSTRACTTABLEVIEWCONTROLLER_H
