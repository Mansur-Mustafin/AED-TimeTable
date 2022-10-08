#include <iostream>
#include "Student.h"
#include "Hour.h"
int main() {
    /*
    Student s ("202025232,Iara,L.EIC002,1LEIC05");
    s.add_class("202025232,Iara,L.EIC004,1LEIC06");
    cout << s.get_name() << endl;
    cout << s.get_StudentCode()<< endl;
    vector<pair<string, string>> a = s.getClasses();
    for(auto p : a) cout << p.first << ',' << p.second << endl ;

    cout << s << endl; // podemos logo fazer print
    */

    Hour h1 (10.5);
    cout << h1.get_hora() << ':' << h1.get_minutes() << endl;
    Hour h2 (2);
    cout << h2.get_hora() << ':' << h2.get_minutes() << endl;
    Hour h3 = h1 + h2;
    cout << h3.get_hora() << ':' << h3.get_minutes() << endl;
    bool i = h3 < h1;
    cout << i;
    return 0;
}

