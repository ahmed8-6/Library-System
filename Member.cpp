
#include "Member.h"

Member::Member(string name, string contact): Person(name, contact) {
}


void Member::borrowBook(Book book) {
    borrowedBooks.push_back(book);
}

bool Member::returnBook(Book book) {
    auto index = borrowedBooks.begin();
    for (auto b : borrowedBooks) {
        if (b.getTitle() == book.getTitle()) {
            borrowedBooks.erase(index);
            return true;
        }
        index++;
    }
    cout << "This Member did not borrow this Book\n";
    return false;
}

void Member::showBooks() {
    int cnt = 1;
    for (auto b : borrowedBooks) {
        cout << cnt++ << ". "<< b.getTitle() << endl;
    }
}
