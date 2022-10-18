#include <iostream>
#include <algorithm>
#include "Operations.h"
#include "Hour.h"
int main() {

    /*
    Read_student a ("students_classes.csv", "classes_per_uc.csv");
    for(auto p : a.get_subjects()) cout << p.get_UCcode() << ' ' << p.get_ClassCode() <<  ' ' << p.get_number_of_student() << endl;
    cout << "-----------------------------" << endl;

    for(auto p : a.get_students()){
        cout << p.get_StudentCode() << ' ';
        for(auto i : p.getSubjects()) cout << i.get_UCcode() << ' ' << i.get_ClassCode() << " ; ";
        cout << endl;
    }
    */

    Operations op ("students_classes.csv", "classes_per_uc.csv","classes.csv");
    op.print_time_table(op.GetTimeTable("202059062"));


    Hour h1(16.5);
    Hour h2(16);
    bool a = h1 > h2;

    //cout << a;

    return 0;
}



