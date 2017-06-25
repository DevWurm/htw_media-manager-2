#include "Medium.h"
#include "Contact.h"

Medium::Medium(QString title, QString creator, int year)
    : title(title), creator(creator), year(year), borrower() {}

Medium::Medium(QString title, QString creator, int year, Contact borrower)
    : title(title), creator(creator), year(year), borrower() {
    this->borrower.setValue(borrower);
}

