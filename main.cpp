#include <iostream>
#include <algorithm>
#include "Operations.h"
#include "Hour.h"
#include "Menu.h"
int main() {

    //Operations op ("students_classes.csv", "classes_per_uc.csv","classes.csv");

    //op.print_time_table(op.GetTimeTable("202020897"));
    //cout << op.N_of_students_in_UC(Subject("L.EIC022,xXXXXxx"));
    //cout << op.N_of_students_in_class(Subject("L.EIC022,3LEIC07"));
    //cout << op.N_of_students_in_year(1);
    /*
    Subject s("L.EIC022,1LEIC01");
    vector<Student> v = op.students_in_UC(s);
    for(auto s : v){
        cout << s << endl;
    }*/

    /*
    vector<Student> v = op.students_in_year(1);
    for(auto s : v){
        cout << s << endl;
    }
    */
    //cout << a;
    Menu menu = Menu();
    menu.main_menu();
    return 0;
}


