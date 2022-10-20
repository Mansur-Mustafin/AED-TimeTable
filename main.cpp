#include <iostream>
#include <algorithm>
#include "Operations.h"
#include "Hour.h"
int main() {

    Operations op ("students_classes.csv", "classes_per_uc.csv","classes.csv");

    //op.print_time_table(op.GetTimeTable("202020897"));
    //cout << op.N_of_students_in_UC(Subject("L.EIC001,xXXXXxx"));
    //cout << op.N_of_students_in_class(Subject("L.EIC001,1LEIC01"));
    //cout << op.N_of_students_in_year(2);
    vector<Student> v = op.students_in_class(Subject("L.EIC001,1LEIC01"));
    for(auto s : v){
        cout << s << endl;
    }


    //cout << a;


    return 0;
}


