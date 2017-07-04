//
// Created by devwurm on 04.07.17.
//

#include "ContactsComboboxDelegate.h"
#include "../models/domain/Contact.h"
#include <QWidget>
#include <QComboBox>
#include <QStyledItemDelegate>
#include <memory>
#include <QVariant>

ContactsComboboxDelegate::ContactsComboboxDelegate(QList<shared_ptr<Contact>> &contacts, QObject *parent) : QStyledItemDelegate(parent), contacts(contacts) {
};

QWidget *ContactsComboboxDelegate::createEditor(QWidget *parent,
                                                const QStyleOptionViewItem &option,
                                                const QModelIndex &index) const {
    QComboBox *editor = new QComboBox(parent);
    for (shared_ptr<Contact> contact: contacts) {
        editor->addItem(contact->getFirstname() + QString(" ") +contact->getLastname());
    }
    editor->addItem("none");

    return editor;
}

void ContactsComboboxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QComboBox *comboBox = static_cast<QComboBox *>(editor);

    const QVariant &valueVariant = index.model()->data(index, Qt::EditRole);
    if (valueVariant.isNull()) {
        comboBox->setCurrentIndex(comboBox->findText(QString("none")));
        return;
    }

    Contact value = valueVariant.value<Contact>();
    comboBox->setCurrentIndex(comboBox->findText(value.getFirstname() + QString(" ") + value.getLastname()));
}

void ContactsComboboxDelegate::setModelData(QWidget *editor,
                                            QAbstractItemModel *model,
                                            const QModelIndex &index) const {
    QComboBox *comboBox = static_cast<QComboBox *>(editor);
    QString name = comboBox->currentText();

    if (name == QString("none")) {
        model->setData(index, QVariant(), Qt::EditRole);
        return;
    }

    for (shared_ptr<Contact> contact : contacts) {
        if ((contact->getFirstname() + QString(" ") + contact->getLastname()) == name) {
            QVariant v;
            v.setValue(*contact);
            model->setData(index, v, Qt::EditRole);
        }
    }
}

void ContactsComboboxDelegate::updateEditorGeometry(QWidget *editor,
                                                    const QStyleOptionViewItem &option,
                                                    const QModelIndex &index) const {
    editor->setGeometry(option.rect);
}