#include <iostream>
#include "Student.h"
int main() {
    Student s ("202025232,Iara,L.EIC002,1LEIC05");
    cout << s.get_name() << endl;
    cout << s.get_StudentCode();
    return 0;
}
