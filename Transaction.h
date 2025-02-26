
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Member.h"


class Transaction {
private:
    int transactionId;
    Book book;
    Member member;
    string type;
    string date;
    static int cnt;
public:
    Transaction(Book book, Member member, string type, string date);

    int getTransactionId();

    void displayTransaction();
};


#endif //TRANSACTION_H
