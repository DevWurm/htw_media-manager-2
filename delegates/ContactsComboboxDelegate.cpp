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