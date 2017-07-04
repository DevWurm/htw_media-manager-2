//
// Created by devwurm on 02.07.17.
//

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
