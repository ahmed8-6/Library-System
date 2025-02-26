#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#ifndef LIBRARY_H
#define LIBRARY_H


class Library {
private:
    vector<Book> books;
    vector<Member> members;
    vector<Transaction> transactions;

public:
    void addBook(Book book);

    void deleteBook(string title);

    void addMember(Member member);

    void deleteMember(int id);

    void addTransaction(Transaction transaction);

    void lendBook(string title, int memberID);

    void returnBook(string title, int memberID);

    void viewBooks();

    void viewMembers();

    void searchBook(string title);

    void displayTransactions();

};


#endif //LIBRARY_H
