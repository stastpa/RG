#include "CMenu.h"

using namespace std;

int main() {
    cout << "\033[2J\033[1;1H";
    CMenu menu = CMenu();
    try {
        menu.CreateMenu();
    }
    catch (runtime_error &ex)
    {
        cout << "Application terminated\n";
        return 1;
    }
    return 0;
}