#include "code/Menu.h"
#include "code/SortFunctions.cpp"
#include <exception>

int main() {
    try {
        Menu menu = Menu();
        menu.main_menu();
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    } catch (...) {
        std::cerr << "An unknown exception occurred.\n";
    }
    return 0;
}
