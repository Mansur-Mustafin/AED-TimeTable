#include <iostream>
#include <algorithm>
#include <list>
#include "Operations.h"
#include "Hour.h"
int main() {

    Operations op ("students_classes.csv", "classes_per_uc.csv","classes.csv");

    //op.print_time_table(op.GetTimeTable("202030247"));
    //cout << op.N_of_students_in_UC(Subject("L.EIC014,xXXXXxx"));
    //cout << op.N_of_students_in_class(Subject("L.EIC022,3LEIC07"));
    //cout << op.N_of_students_in_year(3);

    Subject s ("L.EIC014,2LEIC14");

    vector<Student> v = op.students_in_class(s);
    //cout <<endl <<  v.size();
    for(auto p : v){
        cout << p << endl;
    }

    return 0;
}


