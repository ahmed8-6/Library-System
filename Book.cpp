
#include "Book.h"

int Book::cnt = 0;

Book::Book(): title("NULL"), isbn(0), author("Unkown"), edition("NULL"), genre("NULL"), year(0), isAvailable(false) {
    id = (++cnt);
}

Book::Book(string t, string isbn, string a, string e, string g, int y, bool isAvlbl): title(t), isbn(isbn), author(a),
    edition(e), genre(g), year(y), isAvailable(isAvlbl) {
    id = (++cnt);
}

int Book::getId() {
    return id;
}

void Book::setId(int id) {
    this->id = id;
}

string Book::getTitle() {
    return title;
}

void Book::displayBook() {
    cout << "Book ID: " << id << endl;
    cout << "Book Title: " << title << endl;
    cout << "Book isbn: " << isbn << endl;
    cout << "Author: " << author << endl;
    cout << "Edition: " << edition << endl;
    cout << "Genre: " << genre << endl;
    cout << "published Year: " << year << endl;
}

