//
// Created by devwurm on 24.06.17.
//

#ifndef HTW_MEDIA_MANAGER_2_CONTACTTABLEMODEL_H

#include <memory>

#include "domain/Contact.h"
#include "AbstractListModel.h"

using namespace std;

class ContactTableModel: public AbstractListModel<Contact> {
public:
    ContactTableModel(QList <shared_ptr<Contact>> &model, QObject *parent = 0) : AbstractListModel<Contact>(model, parent) {};

    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#define HTW_MEDIA_MANAGER_2_CONTACTTABLEMODEL_H

#endif //HTW_MEDIA_MANAGER_2_CONTACTTABLEMODEL_H
