#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

struct Book {
    string id;
    string title;
    string author;
    string category;
    bool isAvailable;
};
#endif