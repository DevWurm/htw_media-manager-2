//
// Created by devwurm on 24.06.17.
//

#ifndef HTW_MEDIA_MANAGER_2_MEDIUMTABLEMODEL_H

#include "domain/Medium.h"
#include "AbstractListModel.h"

class MediumTableModel: public AbstractListModel<Medium> {
public:
    MediumTableModel(QList<shared_ptr<Medium>> &model, QObject *parent = 0) : AbstractListModel<Medium>(model, parent) {};

    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#define HTW_MEDIA_MANAGER_2_MEDIUMTABLEMODEL_H

#endif //HTW_MEDIA_MANAGER_2_MEDIUMTABLEMODEL_H
