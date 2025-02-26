#ifndef START_H
#define START_H
#include <thread>
#include <chrono>
#include "Library.h"

void start();

void test(Library *library);

void librarian(Library *library);

void member(Library *library);

void addBook(Library *library);

void deleteBook(Library *library);

void searchBook(Library *library);

void viewBooks(Library *library);

void borrowBook(Library *library);

void returnBook(Library *library);

void addMember(Library *library);

void deleteMember(Library *library);

void viewMembers(Library *library);

void viewTransacion(Library *library);

void exit();


Library library;


void test(Library *library) {
    // ADD MEMBERS AND BOOKS FOR FAST TESTING

    library->addBook(Book("The Great Gatsby", "9781234567897", "F. Scott Fitzgerald", "1st edition", "Tragedy", 1925,
                          true));
    library->addBook(Book("The Hobbit", "9780593201061", "J. R. R. Tolkien", "3rd edition", "Fantasy", 1937, true));
    library->addBook(Book("A Tale of Two Cities", "9782123456804", "Charles Dickens", "2nd edition",
                          "Historical fiction", 1859, true));
    library->addBook(Book("And Then There Were None", "9780997025492", "Agatha Christie", "1st edition", "Mystery",
                          1939, true));
    library->addMember(Member("Ahmed Adel", "+201558080553"));
    library->addMember(Member("Zaki Adel", "+201558080552"));
    library->addMember(Member("Mostafa Adel", "+201558080556"));
    library->lendBook("A Tale of Two Cities", 1);
}

void start() {
    system("cls");
    int access;
    cout << "Welcome To Our Library Management System:\n\n";
    cout << "Please, Choose your access type.\n";
    cout << "[1] Librarian\n";
    cout << "[2] Member\n";
    cout << "Enter An Option: ";
    cin >> access;
    fflush(stdin);
    // test();

    // CHECK IF THE USER IS A LIBRARIAN OR A MEMBER TO DETERMINE HIS ACCESS
    if (access == 1) {
        librarian(&library);
    } else if (access == 2) {
        member(&library);
    }
}

void librarian(Library *library) {
    system("cls");
    cout << "Library Management System\n\n";
    int choice;
    cout << "[1] ADD BOOK\n";
    cout << "[2] DELETE BOOK\n";
    cout << "[3] VIEW BOOKS\n";
    cout << "[4] ADD MEMBER\n";
    cout << "[5] DELETE MEMBER\n";
    cout << "[6] VIEW MEMBERS\n";
    cout << "[7] VIEW TRANSACTIONS\n";
    cout << "[8]HOME\n";
    cout << "[9] EXIT\n";
    cout << "Enter your choice: ";
    cin >> choice;
    fflush(stdin);
    system("cls");
    switch (choice) {
        case 1:
            addBook(library);
            break;
        case 2:
            deleteBook(library);
            break;
        case 3:
            viewBooks(library);
            break;
        case 4:
            addMember(library);
            break;
        case 5:
            deleteMember(library);
            break;
        case 6:
            viewMembers(library);
            break;
        case 7:
            viewTransacion(library);
            break;
        case 8:
            start();
            break;
        case 9:
            exit();
    }
    this_thread::sleep_for(chrono::milliseconds(4000));
    librarian(library);
}

void member(Library *library) {
    system("cls");
    cout << "Library Management System\n\n";
    int choice;
    cout << "[1] VIEW BOOKS\n";
    cout << "[2] SEARCH BOOK\n";
    cout << "[3] BORROW BOOK\n";
    cout << "[4] RETURN BOOK\n";
    cout << "[5]HOME\n";
    cout << "[6] EXIT\n";
    cout << "Enter your choice: ";
    cin >> choice;
    fflush(stdin);
    system("cls");
    switch (choice) {
        case 1:
            viewBooks(library);
            break;
        case 2:
            searchBook(library);
            break;
        case 3:
            borrowBook(library);
            break;
        case 4:
            returnBook(library);
            break;
        case 5:
            start();
            break;
        case 6:
            exit();
    }
    this_thread::sleep_for(chrono::milliseconds(4000));
    member(library);
}


void addBook(Library *library) {
    string title, isbn, author, edition, genre;
    int year;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book isbn: ";
    getline(cin, isbn);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter edition: ";
    getline(cin, edition);
    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter year: ";
    cin >> year;
    fflush(stdin);
    library->addBook(Book(title, isbn, author, edition, genre, year, true));
}

void deleteBook(Library *library) {
    cout << "Enter book title: ";
    string title;
    getline(cin, title);
    library->deleteBook(title);
}

void viewBooks(Library *library) {
    library->viewBooks();
}

void searchBook(Library *library) {
    cout << "Enter book title: ";
    string title;
    getline(cin, title);
    library->searchBook(title);
}

void borrowBook(Library *library) {
    string title;
    int memberId;
    cout << "Enter your ID: ";
    cin >> memberId;
    fflush(stdin);
    cout << "Enter book title: ";
    getline(cin, title);
    library->lendBook(title, memberId);
}

void returnBook(Library *library) {
    string title;
    int memberId;
    cout << "Enter your ID: ";
    cin >> memberId;
    fflush(stdin);
    cout << "Enter book title: ";
    getline(cin, title);
    library->returnBook(title, memberId);
}

void addMember(Library *library) {
    string name, contact;
    cout << "Enter Memebr Name: ";
    getline(cin, name);
    cout << "Enter Contact: ";
    getline(cin, contact);
    library->addMember(Member(name, contact));
}

void deleteMember(Library *library) {
    int id;
    cout << "Enter Memebr ID: ";
    cin >> id;
    library->deleteMember(id);
}

void viewMembers(Library *library) {
    library->viewMembers();
}

void viewTransacion(Library *library) {
    library->displayTransactions();
}

void exit() {
    _exit(1);
}


#endif
