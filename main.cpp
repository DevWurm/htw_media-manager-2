#include <iostream>
#include "ui_media-manager.h"

#include "models/domain/Contact.h"
#include "models/ContactTableModel.h"
#include "controllers/ContactsController.h"
#include <QList>


using namespace std;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;
    Ui::MediaManager ui;
    ui.setupUi(window);

    QList<Contact> data;
    data.append(Contact("Test1", "Test2"));

    ContactTableModel model(data);

    ContactsController controller(ui, model);


    ui.contacts_table->setModel(&model);

    window->show();
    return app.exec();
}
