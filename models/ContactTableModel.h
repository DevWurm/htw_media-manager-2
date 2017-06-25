//
// Created by devwurm on 24.06.17.
//

#ifndef HTW_MEDIA_MANAGER_2_CONTACTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "domain/Contact.h"

class ContactTableModel: public QAbstractTableModel {
private:
    QList<Contact>& contacts;
public:
    ContactTableModel(QList<Contact>& contacts, QObject * parent = 0): QAbstractTableModel(parent), contacts(contacts){};

    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#define HTW_MEDIA_MANAGER_2_CONTACTTABLEMODEL_H

#endif //HTW_MEDIA_MANAGER_2_CONTACTTABLEMODEL_H
