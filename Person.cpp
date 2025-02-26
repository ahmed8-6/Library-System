#include "Person.h"

int Person::cnt = 0;

Person::Person(string name, string contact): name(name), contact(contact) {
    id = ++cnt;
}

int Person::getId() {
    return id;
}

void Person::setId(int id) {
    this->id = id;
}


string Person::getName() {
    return name;
}

string Person::getContact() {
    return contact;
}
