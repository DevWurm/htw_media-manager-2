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
#include "serialization/ApplicationModelSerializer.h"
#include <QList>
#include <QFile>
#include <memory>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

using namespace std;

int main(int argc, char* argv[]) {
    QList<shared_ptr<Contact>> contactsData;
    QList<shared_ptr<Medium>> mediaData;
    ApplicationModelSerializer applicationModelSerializer(contactsData, mediaData);

    passwd* pw = getpwuid(getuid());
    QString persistenceLocation = QString(pw->pw_dir) + QString("/.htw-media-manager-data.xml");

    try {
        QFile dataFile(persistenceLocation);
        applicationModelSerializer.deserialize(dataFile);
    } catch (Exception e) {
        cerr << e.what() << endl;
        return 1;
    }

    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;
    Ui::MediaManager ui;
    ui.setupUi(window);

    ContactTableModel contactsModel(contactsData);
    ContactsController contactsController(ui, contactsModel);
    ui.contacts_table->setModel(&contactsModel);

    MediumTableModel mediaModel(mediaData);
    MediaController mediaController(ui, mediaModel);
    ui.media_table->setModel(&mediaModel);

    ContactsComboboxDelegate comboboxDelegate(contactsData);
    ui.media_table->setItemDelegateForColumn(4,&comboboxDelegate);

    window->show();
    int appCode =  app.exec();

    try {
        QFile dataFile(persistenceLocation);
        applicationModelSerializer.serialize(dataFile);
    } catch (Exception e) {
        cerr << e.what() << endl;
        return 2;
    }

    return appCode;
}
