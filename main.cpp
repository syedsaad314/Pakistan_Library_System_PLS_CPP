#include "include/LibraryEngine.h"
#include "include/UI.h"
#include <iostream>

using namespace std;

int main() {
    LibraryEngine titan;
    int choice;

    do {
        UI::header("PAKISTAN LIBRARY SYSTEM (PLS) v1.0");
        cout << "\033[1;33m1. Catalog Asset\033[0m" << endl;
        cout << "\033[1;33m2. View Inventory\033[0m" << endl;
        cout << "\033[1;33m3. Issue Borrowing\033[0m" << endl;
        cout << "\033[1;33m4. Process Return\033[0m" << endl;
        cout << "\033[1;33m5. Check Fines\033[0m" << endl;
        cout << "\033[1;33m6. Decommission Asset\033[0m" << endl;
        cout << "\033[1;31m0. Logout\033[0m" << endl;
        cout << "\nOperation Selection > ";
        
        if (!(cin >> choice)) {
            UI::error("Input must be numeric.");
            cin.clear(); cin.ignore(10000, '\n');
            UI::loading("Resetting Interface");
            continue;
        }

        switch(choice) {
            case 1: titan.addNewBook(); break;
            case 2: titan.generateInventoryReport(); break;
            case 3: {
                string bid; cout << "Enter Book ID: "; cin >> bid;
                titan.borrowBook("STUDENT_01", bid);
                break;
            }
            case 4: {
                string bid; cout << "Enter Book ID: "; cin >> bid;
                titan.returnBook("STUDENT_01", bid);
                break;
            }
            case 5: titan.calculateFine("STUDENT_01"); break;
            case 6: {
                string bid; cout << "Enter ID to Remove: "; cin >> bid;
                titan.removeBook(bid);
                break;
            }
            case 0: UI::success("Secure Session Terminated."); break;
            default: UI::error("Unknown Operation.");
        }

        if(choice != 0) {
            cout << "\nPress Enter to return to Command Center...";
            cin.ignore(); cin.get();
        }
    } while (choice != 0);

    return 0;
}