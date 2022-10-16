//
// Created by Mansur on 14.10.2022.
//

#include "Read_student.h"
#include <fstream>
#include <algorithm>

#include "Read_class_per_uc.h"

using namespace std;

Read_student::Read_student(const string& fname, const string& UC_student) { // vou receber lista atual das UCs com os numeros dos estudantes e vou receber um vetor dos estudantes

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

    sort(v.begin(),v.end(), [ ] (const Student& s1, const Student& s2) {return s1.get_StudentCode() < s2.get_StudentCode();});
}


Read_student::Read_student() {
    s = {};
    v = {};
}


vector<Subject> Read_student::get_subjects() const {
    return s;
}

vector<Student> Read_student::get_students() const {
    return v;
}

Student Read_student::Bynary_serch_of_student(const std::string &keystr) {

    int key = stoi(keystr);
    int low = 0;
    int high = get_students().size();
    //cout << high;
    while(low < high){
        //cout << low << high << endl;
        int middle = low + (high - low) / 2;
        if(key < v[middle].get_StudentCode()){
            high = middle - 1;
        }
        else if(key > v[middle].get_StudentCode()){
            low = middle + 1;
        }
        else return v[middle];
    }
    return Student("202102355,Mansur,L.EIC014,2LEIC04");
}