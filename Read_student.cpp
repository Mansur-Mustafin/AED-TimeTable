//
// Created by musta on 14.10.2022.
//

#include "Read_student.h"
#include <fstream>

#include "Read_class_per_uc.h"

using namespace std;

Read_student::Read_student(const string& fname, const string& UC_student) { // vou receber lista atual das ucs com os numeros dos estudantes
                                                                                //vou receber um vetor dos estudantes

    Read_class_per_uc UC (UC_student); // todos subjects
    s = UC.get_subjects();

    ifstream inn(fname);
    string line;
    getline(inn, line);
    getline(inn, line);
    Student s_old(line);

    int i = UC.Binary_search(s_old.getSubjects()[0]);
    s[i].plus_student_n();

    while (getline(inn, line)){
        Student s_new(line);

        i = UC.Binary_search(s_new.getSubjects()[0]);
        s[i].plus_student_n();

        if(s_new.get_StudentCode() == s_old.get_StudentCode()){
            s_old.add_subject(line);
        }else{
            v.push_back(s_old);
            s_old = s_new;
        }
    }

}

vector<Subject> Read_student::get_subjects() const {
    return s;
}

vector<Student> Read_student::get_students() const {
    return v;
}
