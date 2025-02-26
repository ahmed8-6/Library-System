#include "Transaction.h"

int Transaction:: cnt = 0;

Transaction::Transaction(Book book, Member member, string type, string date): book(book), member(member), type(type), date(date) {
    transactionId = ++cnt;
}

int Transaction::getTransactionId() {
    return transactionId;
}

void Transaction::displayTransaction() {
    cout << "Transaction type: " << type << endl;
    cout << "Member ID: " << member.getId() << endl;
    cout << "Book title: " << book.getTitle() << endl;
    cout << "Date: " << date << endl;
}
