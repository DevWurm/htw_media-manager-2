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

#ifndef HTW_MEDIA_MANAGER_2_MEDIACONTROLLER_H

#include <QAbstractButton>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QObject>

#include "AbstractTableViewController.h"
#include "../models/domain/Medium.h"
#include "../ui_media-manager.h"

class MediaController: public AbstractTableViewController<Medium> {
private:
    QLineEdit &titleInput;
    QLineEdit &creatorInput;
    QDateEdit &yearInput;
    QComboBox &typeInput;
public:
    MediaController(
        QAbstractButton &addMediumButton,
        QAbstractButton &deleteMediaButton,
        QLineEdit &titleInput,
        QLineEdit &creatorInput,
        QDateEdit &yearInput,
        QComboBox &typeInput,
        QTableView &mediaTable,
        AbstractListModel<Medium> &model
    ) : AbstractTableViewController(
            addMediumButton,
            deleteMediaButton,
            model,
            mediaTable
        ),
        titleInput(titleInput),
        creatorInput(creatorInput),
        yearInput(yearInput),
        typeInput(typeInput)
        {};

    MediaController(Ui_MediaManager &ui, AbstractListModel<Medium> &model) :
        MediaController(
            *(ui.add_medium_button),
            *(ui.delete_medium_button),
            *(ui.title_input),
            *(ui.creator_input),
            *(ui.year_input),
            *(ui.type_input),
            *(ui.media_table),
            model
        ) {};
    void addItem();
};

#define HTW_MEDIA_MANAGER_2_MEDIACONTROLLER_H

#endif //HTW_MEDIA_MANAGER_2_MEDIACONTROLLER_H
