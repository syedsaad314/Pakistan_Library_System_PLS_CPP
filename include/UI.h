#ifndef UI_H
#define UI_H
#include <string>
using namespace std;

class UI {
public:
    static void clear();
    static void header(string t);
    static void success(string m);
    static void error(string m);
    static void loading(string n);
};
#endif