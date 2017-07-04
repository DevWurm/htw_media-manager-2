#include <iostream>
#include "ui_media-manager.h"

#include "models/domain/Contact.h"
#include "models/domain/Medium.h"
#include "models/ContactTableModel.h"
#include "controllers/ContactsController.h"
#include "models/MediumTableModel.h"
#include "controllers/MediaController.h"
#include "delegates/ContactsComboboxDelegate.h"
#include <QList>
#include <memory>


using namespace std;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;
    Ui::MediaManager ui;
    ui.setupUi(window);

    QList<shared_ptr<Contact>> contactsData;
    ContactTableModel contactsModel(contactsData);
    ContactsController contactsController(ui, contactsModel);
    ui.contacts_table->setModel(&contactsModel);

    QList<shared_ptr<Medium>> mediaData;
    MediumTableModel mediaModel(mediaData);
    MediaController mediaController(ui, mediaModel);
    ui.media_table->setModel(&mediaModel);

    ContactsComboboxDelegate comboboxDelegate(contactsData);
    ui.media_table->setItemDelegateForColumn(4,&comboboxDelegate);

    window->show();
    return app.exec();
}
