#include <iostream>
#include "Student.h"
#include "Hour.h"
#include "Subject.h"
int main() {

    Student s ("202025232,Iara,L.EIC002,1LEIC05");
    s.add_subject("202025232,Iara,L.EIC004,1LEIC06");
    s.add_subject("202025232,Iara,L.EIC004,1LEIC07");
    s.add_subject("202025232,Iara,L.EIC004,1LEIC08");

    Subject s2 ("L.EIC004,1LEIC06");

    s.remove_subject(s2);
    vector<Subject> a = s.getClasses();
    for(auto p : a) cout << p.get_UCcode() << ',' << p.get_ClassCode() << endl ;

    // cout << s << endl; // podemos logo fazer print

/*
    Hour h1 (10.5);
    cout << h1.get_hora() << ':' << h1.get_minutes() << endl;
    Hour h2 (2);
    cout << h2.get_hora() << ':' << h2.get_minutes() << endl;
    Hour h3 = h1 + h2;
    cout << h3.get_hora() << ':' << h3.get_minutes() << endl;
    bool i = h3 < h1;
    cout << i;

*/

/*
Subject s ("L.EIC001,3LEIC09");

Subject s2 ("L.EIC002,1LEIC10");
cout << s.get_year() << endl;
bool a = s < s2;
cout << a;
  */
    return 0;

}

