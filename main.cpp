#include <iostream>
#include <algorithm>
#include "Operations.h"

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
    vector<Class> aulas =  op.GetTimeTable("202060167");
    for(const auto& aula : aulas) cout << aula << endl;
    return 0;
}
