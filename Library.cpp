#include "Library.h"

void Library::addBook(Book book) {
    books.push_back(book);
    cout << "Book added successfully!\n";
}

void Library::deleteBook(string title) {
    auto index = books.begin();
    for (auto &book : books) {
        if (book.getTitle() == title) {
            books.erase(index);
            cout << "Book deleted successfully!\n";
            for (; index != books.end(); index++) {
                index->setId(index->getId()-1);
            }
            return;
        }
        index++;
    }
    cout << "Book does not exist\n";
}

void Library::searchBook(string title) {
    for (auto &book : books) {
        if (book.getTitle() == title) {
            book.displayBook();
            return;
        }
    }
    cout << "Book not found\n";
}


void Library::addMember(Member member) {
    members.push_back(member);
    cout << "Member added successfully!\n";
    cout << "Member (" << member.getName() <<") ID is " << member.getId() << endl;
}
void Library::deleteMember(int id) {
    auto index = members.begin();
    for (auto &member : members) {
        if (member.getId() == id) {
            members.erase(index);
            cout << "Member deleted successfully!\n";
            return;
        }
        index++;
    }
    cout << "Member does not exist\n";
}

void Library::addTransaction(Transaction transaction) {
    transactions.push_back(transaction);
}



void Library::lendBook(string title, int memberID) {
    for (auto &book : books) {
        if (title == book.getTitle()) {
            if (!book.isAvailable) {
                cout << "Book is not available at this time\n";
                return;
            }
            for (auto &member : members) {
                if (memberID == member.getId()) {
                    member.borrowBook(book);
                    addTransaction(Transaction(book, member, "borrow", __DATE__));
                    book.isAvailable = false;
                    cout << "Book is borrowed successfully!\n";
                    return;
                }
            }
            cout << "Member not found!\n";
            return;
        }
    }
    cout << "Book not found\n";
}

void Library::returnBook(string title, int memberID) {
    for (auto &book : books) {
        if (title == book.getTitle() && !book.isAvailable) {
            for (auto &member : members) {
                if (member.getId() == memberID) {
                    if (!member.returnBook(book)) {
                        return;
                    }
                    addTransaction(Transaction(book, member, "return", __DATE__));
                    book.isAvailable = true;
                    cout << "Book is returned successfully!\n";
                    return;
                }
            }
            cout << "Member not found!\n";
            return;
        }
    }
    cout << "Book not found\n";
}

void Library::viewBooks() {
    for (auto &book : books) {
        cout << book.getId() << "- " << book.getTitle();
        if (book.isAvailable) {
            cout << " (Available)\n";
        }
        else {
            cout << " (Borrowed)\n";
        }
    }
}

void Library::viewMembers() {
    for (auto &member : members) {
        cout << member.getId() << "- " << member.getName() << endl;
    }
}



void Library::displayTransactions() {
    for (auto &transaction : transactions) {
        transaction.displayTransaction();
        cout << "--------------------------------------\n";
    }
}


