//
// Created by devwurm on 02.07.17.
//

#ifndef HTW_MEDIA_MANAGER_2_ABSTRACTTABLEVIEWSINGALSLOTS_H
#define HTW_MEDIA_MANAGER_2_ABSTRACTTABLEVIEWSINGALSLOTS_H

#include <QObject>

class AbstractTableViewSignalSlots: public QObject {
    Q_OBJECT;
public slots:
    virtual void addItem() = 0;
    virtual void deleteItems() = 0;
};

#endif //HTW_MEDIA_MANAGER_2_ABSTRACTTABLEVIEWSINGALSLOTS_H
