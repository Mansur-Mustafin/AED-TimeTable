#include <iostream>
#include <algorithm>
#include "Operations.h"
#include "Hour.h"
int main() {

    Operations op ("students_classes.csv", "classes_per_uc.csv","classes.csv");

    op.print_time_table(op.GetTimeTable("202059062"));


    Hour h1(16.5);
    Hour h2(16);
    bool a = h1 > h2;

    //cout << a;


    return 0;
}



