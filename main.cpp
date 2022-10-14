#include <iostream>
#include "Student.h"
#include "Hour.h"
#include "Subject.h"
#include "Read_class_per_uc.h"
#include <fstream>
#include <algorithm>
#include "Read_student.h"

int main() {
    /*
    Student s ("202071557,Ludovico,L.EIC022,3LEIC02");
    cout << s.get_StudentCode();
    */

    Read_student a ("students_classes.csv", "classes_per_uc.csv");
    for(auto p : a.get_subjects()) cout <<p.get_UCcode() << ' ' << p.get_number_of_student() << endl;
    cout << "-----------------------------" << endl;

    for(auto p : a.get_students()){
        cout << p.get_StudentCode() << ' ';
        for(auto i : p.getSubjects()) cout << i.get_UCcode() << ' ' << i.get_ClassCode() << " ; ";
        cout << endl;
    }



    return 0;
}
