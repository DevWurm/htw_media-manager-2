#include <iostream>
#include "ui_media-manager.h"

#include "models/domain/Contact.h"
#include "models/domain/Medium.h"
#include "models/ContactTableModel.h"
#include "controllers/ContactsController.h"
#include "models/MediumTableModel.h"
#include "controllers/MediaController.h"
#include "delegates/ContactsComboboxDelegate.h"
#include "exceptions/Exception.h"
#include "serialization/ContactXMLSerializer.h"
#include <QList>
#include <QFile>
#include <memory>


using namespace std;

int main(int argc, char* argv[]) {
    QList<shared_ptr<Contact>> contactsData;
    ContactXMLSerializer contactXMLSerializer("contacts", "contact");

    try {
        QFile dataFile("htw-media-manager-data.xml");
        if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text))
            throw Exception("Could not open data file");

        contactXMLSerializer.deserialize(dataFile, contactsData);
    } catch (Exception e) {
        cerr << e.what();
        return 1;
    }

    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;
    Ui::MediaManager ui;
    ui.setupUi(window);

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
    int appCode =  app.exec();

    try {
        QFile dataFile("htw-media-manager-data.xml");
        if (!dataFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
            throw Exception("Could not open data file");

        contactXMLSerializer.serialize(contactsData, dataFile);
    } catch (Exception e) {
        cerr << e.what();
        return 2;
    }

    return appCode;
}
