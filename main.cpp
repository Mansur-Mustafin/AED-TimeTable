#include <iostream>
#include <algorithm>
#include "Operations.h"
#include "Hour.h"
int main() {

    Operations op ("students_classes.csv", "classes_per_uc.csv","classes.csv");

    vector<Student> v = op.students_in_year(2);
    for(auto s : v){
        cout << s << endl;
    }

    return 0;
}


