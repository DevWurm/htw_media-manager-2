#include <iostream>
#include "ui_media-manager.h"

using namespace std;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;
    Ui::MediaManager ui;
    ui.setupUi(window);

    window->show();
    return app.exec();
}
