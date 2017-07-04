//
// Created by devwurm on 04.07.17.
//

#ifndef HTW_MEDIA_MANAGER_2_CONTACTSCOMBOBOXDELEGATE_H
#include <QStyledItemDelegate>
#include <memory>
#include "../models/domain/Contact.h"

using namespace std;

class ContactsComboboxDelegate: public QStyledItemDelegate {
    Q_OBJECT;
private:
    QList<shared_ptr<Contact>> &contacts;
public:
    ContactsComboboxDelegate(QList<shared_ptr<Contact>> &contacts, QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#define HTW_MEDIA_MANAGER_2_CONTACTSCOMBOBOXDELEGATE_H
#endif //HTW_MEDIA_MANAGER_2_CONTACTSCOMBOBOXDELEGATE_H
