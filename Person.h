#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"


using namespace __gnu_pbds;
using namespace std;
#ifndef PERSON_H
#define PERSON_H


class Person {
protected:

    int id;
    string name;
    string contact;

    static int cnt;
public:
    Person(string name, string contact);
    int getId();

    void setId(int id);

    string getName();

    string getContact();
};


#endif //PERSON_H
