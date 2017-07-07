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
    QList<shared_ptr<Contact>> contactsData; // contacts model data
    QList<shared_ptr<Medium>> mediaData; // media model data
    ApplicationModelSerializer applicationModelSerializer(contactsData, mediaData);

    passwd* pw = getpwuid(getuid());
    QString persistenceLocation = QString(pw->pw_dir) + QString("/.htw-media-manager-data.xml"); // location of the data file

    try {
        QFile dataFile(persistenceLocation);
        applicationModelSerializer.deserialize(dataFile);
    } catch (Exception e) {
        cerr << e.what() << endl;
        return 1;
    }

    // setup UI
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;
    Ui::MediaManager ui;
    ui.setupUi(window);

    // setup contacts view
    ContactTableModel contactsModel(contactsData);
    ContactsController contactsController(ui, contactsModel);
    ui.contacts_table->setModel(&contactsModel);

    // setup media view
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
