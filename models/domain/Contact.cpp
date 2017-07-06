#include "Contact.h"
#include <chrono>

using namespace std;

Contact::Contact(QString firstname, QString lastname) :
    id(
        to_string(chrono::duration_cast<chrono::milliseconds>(
            chrono::system_clock::now().time_since_epoch()
        ).count()).c_str()
    ), firstname(firstname), lastname(lastname) {
}

Contact::Contact(QString id, QString firstname, QString lastname) : id(id), firstname(firstname), lastname(lastname) {};