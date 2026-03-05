#ifndef LIBRARYENGINE_H
#define LIBRARYENGINE_H
#include "Book.h"
#include <vector>

using namespace std;

class LibraryEngine {
private:
    vector<Book> books;
public:
    void addNewBook();
    void removeBook(string id);
    void borrowBook(string studentId, string bookId);
    void returnBook(string studentId, string bookId);
    void generateInventoryReport();
    void calculateFine(string studentId);
};
#endif