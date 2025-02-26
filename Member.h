
#ifndef MEMBER_H
#define MEMBER_H
#include "Book.h"
#include "Person.h"


class Member : public Person {
private:
    vector<Book> borrowedBooks;

public:
    Member(string name, string contact);
    void borrowBook(Book book);

    bool returnBook(Book book);

    void showBooks();

};


#endif //MEMBER_H
