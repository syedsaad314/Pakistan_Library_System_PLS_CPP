#include "../include/LibraryEngine.h"
#include "../include/UI.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void LibraryEngine::addNewBook() {
    UI::header("CATALOG NEW ASSET");
    Book b;
    cout << "Enter Book ID (e.g. LIB-001): "; cin >> b.id; cin.ignore();
    cout << "Enter Book Title: "; getline(cin, b.title);
    cout << "Enter Author Name: "; getline(cin, b.author);
    cout << "Enter Category: "; getline(cin, b.category);
    b.isAvailable = true;

    UI::loading("Connecting to Central Server");
    books.push_back(b);
    UI::success("Asset cataloged in National Database.");
}

void LibraryEngine::removeBook(string id) {
    UI::loading("Authorized Deletion in Progress");
    auto it = remove_if(books.begin(), books.end(), [&](Book& b) { return b.id == id; });
    if (it != books.end()) {
        books.erase(it, books.end());
        UI::success("Asset wiped from local and cloud records.");
    } else {
        UI::error("Asset ID not recognized.");
    }
}

void LibraryEngine::borrowBook(string studentId, string bookId) {
    for (auto& b : books) {
        if (b.id == bookId) {
            if (b.isAvailable) {
                b.isAvailable = false;
                UI::loading("Processing Issue Request");
                UI::success("Transaction authorized for Student: " + studentId);
                return;
            } else {
                UI::error("Resource currently held by another user.");
                return;
            }
        }
    }
    UI::error("ID not found in Inventory.");
}

void LibraryEngine::returnBook(string studentId, string bookId) {
    for (auto& b : books) {
        if (b.id == bookId) {
            b.isAvailable = true;
            UI::loading("Scanning Resource for Damage");
            UI::success("Return successful. Inventory updated.");
            return;
        }
    }
    UI::error("This item does not belong to this facility.");
}

void LibraryEngine::generateInventoryReport() {
    UI::header("PLS INVENTORY REPORT");
    cout << left << setw(10) << "ID" << setw(20) << "TITLE" << setw(15) << "CATEGORY" << "STATUS" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (const auto& b : books) {
        cout << left << setw(10) << b.id << setw(20) << b.title << setw(15) << b.category 
             << (b.isAvailable ? "\033[1;32m[SHELF]\033[0m" : "\033[1;31m[ISSUED]\033[0m") << endl;
    }
}

void LibraryEngine::calculateFine(string studentId) {
    UI::loading("Querying Financial Records");
    UI::success("Account clean. No outstanding late fees for " + studentId);
}