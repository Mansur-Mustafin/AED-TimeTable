#include <iostream>
#include "Student.h"
int main() {
    Student s ("202025232,Iara,L.EIC002,1LEIC05");
    s.add_class("202025232,Iara,L.EIC004,1LEIC06");
    cout << s.get_name() << endl;
    cout << s.get_StudentCode()<< endl;
    vector<pair<string, string>> a = s.getClasses();
    for(auto p : a) cout << p.first << ',' << p.second << endl ;

    cout << s; // podemos logo fazer print

    return 0;
}
