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

    //vector<Class> aulas =  op.GetTimeTable("202027952");


    //sort(aulas.begin(),aulas.end(),[ ] (const Class& c1, class Class& c2) {return c1.get_day_index() < c2.get_day_index();});
    //sort(aulas.begin(),aulas.end(),[ ] (const Class& c1, class Class& c2) {return c1.get_hora_s() < c2.get_hora_s();});

    //Subject s ("L.EIC015,2LEIC13");
    //cout << op.N_of_students_in_class(s) << endl;
    //Subject s2 ("L.EIC015,xXXXXxx");
    //cout << op.N_of_students_in_UC(s2);

    //for(const auto& aula : aulas) cout << aula << endl;
    return 0;
}


