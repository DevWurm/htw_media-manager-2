//
// Created by devwurm on 02.07.17.
//
#include <memory>

#include "MediaController.h"
#include "../models/domain/Book.h"
#include "../models/domain/Film.h"

using namespace std;

void MediaController::addItem() {
    if (typeInput.currentText() == "Book") {
        shared_ptr<Book> book = make_shared<Book>(
           titleInput.text(),
           creatorInput.text(),
           yearInput.date().year()
        );
        model.addRow(book);
    } else if (typeInput.currentText() == "Film") {
        shared_ptr<Film> film = make_shared<Film>(
            titleInput.text(),
            creatorInput.text(),
            yearInput.date().year()
        );
        model.addRow(film);
    }

    titleInput.clear();
    creatorInput.clear();
};
