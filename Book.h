

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"


using namespace __gnu_pbds;
using namespace std;
#ifndef BOOK_H

#define BOOK_H


class Book {
private:
    int id;
    string isbn;
    string title;
    string author;
    string edition;
    string genre;
    int year;
    static int cnt;

public:
    Book();

    Book(string t, string isbn, string a, string e, string g, int y, bool isAvlbl);

    bool isAvailable;

    int getId();

    void setId(int id);

    string getTitle();

    void displayBook();
};


#endif //BOOK_H
