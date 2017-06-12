#include "medium.h"

medium::medium(QString title, QString creator, int year)
    : title(title), creator(creator), year(year), borrower() {}

medium::medium(QString title, QString creator, int year, contact borrower)
    : title(title), creator(creator), year(year), borrower(borrower) {}

