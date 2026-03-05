#include "../include/UI.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void UI::clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void UI::header(string t) {
    clear();
    cout << "\033[1;36m==================================================\033[0m" << endl;
    cout << "\033[1;33m       " << t << "       \033[0m" << endl;
    cout << "\033[1;36m==================================================\033[0m" << endl << endl;
}

void UI::success(string m) {
    cout << "\033[1;32m[✔] SUCCESS: " << m << "\033[0m" << endl;
}

void UI::error(string m) {
    cout << "\033[1;31m[✘] ERROR: " << m << "\033[0m" << endl;
}

void UI::loading(string n) {
    cout << "\033[1;37m" << n << "\033[0m";
    for(int i=0; i<3; i++) {
        this_thread::sleep_for(chrono::milliseconds(400));
        cout << "." << flush;
    }
    cout << endl;
}