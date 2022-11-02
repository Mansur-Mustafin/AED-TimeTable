#include <iostream>
#include <algorithm>
#include <list>
#include "Operations.h"
#include "Hour.h"
#include "Menu.h"
#include "SortFunctions.cpp"
#include "Change.h"

int main() {

    //Operations op ("students_classes.csv", "classes_per_uc.csv","classes.csv");


    //list<Subject> s = op.N_of_students_in_UC(Subject("L.EIC025,xXXXXxx"));

    //op.print_time_table(op.GetTimeTable("202020897"));
    //cout << op.N_of_students_in_UC(Subject("L.EIC014,xXXXXxx"));
    //cout << op.N_of_students_in_class(Subject("L.EIC015,2LEIC11"));


    //Subject s("L.EIC025,xXXXXxx");
    /*
    list<Student> v = op.students_in_year(1);
    for(auto s : v){
        cout << s << endl;
    }*/
    /*
    list<Subject> s = op.N_of_students_in_UC(Subject("L.EIC014,xXXXXxx"));

    int R = 0;
    for(auto i : s){
        cout << i.get_UCcode() << ',' << i.get_ClassCode() << ' ' << i.get_number_of_student() << endl;
        R += i.get_number_of_student();
    }
    cout << R << " total";



    //op.print_time_table(op.GetTimeTable("202065182"));
    //cout << endl;

    op.processChanges("requests.csv");
    cout << endl;
    //op.print_time_table(op.GetTimeTable("202065182"));

    //cout << op.N_of_students_in_UC(Subject("L.EIC014,xXXXXxx"));
    //cout << op.N_of_students_in_class(Subject("L.EIC015,2LEIC11"));
    */
    /*
    map<string, int> m = op.N_of_students_in_year(3);
    for(auto i : m){
        cout << i.first << ',' << i.second << endl;
    }
*/
     /*
    //Subject s("L.EIC025,xXXXXxx");
    /*
    list<Student> v = op.students_in_year(1);
    for(auto s : v){
        cout << s << endl;
    }*/





/*
     s = op.N_of_students_in_UC(Subject("L.EIC025,xXXXXxx"));
     R = 0;
    for(auto i : s){
        cout << i.get_UCcode() << ',' << i.get_ClassCode() << ' ' << i.get_number_of_student() << endl;
        R += i.get_number_of_student();
    }
    cout << R << " total";
*/

    Menu menu = Menu();
    menu.main_menu();
    return 0;
}
