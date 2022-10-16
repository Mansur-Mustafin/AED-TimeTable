//
// Created by musta on 16.10.2022.
//

#include <algorithm>
#include "Operations.h"
Operations::Operations(const std::string &fm_student, const std::string &UC_student, const std::string &fm_classes) {
    Read_classes rc = Read_classes (fm_classes);
    Read_student rs = Read_student (fm_student, UC_student);
    this->rs = rs;
    this->rc = rc;
}

vector<Class> Operations::GetTimeTable(const std::string &number)  {
    vector<Subject> subjects =  rs.Bynary_serch_of_student(number).getSubjects();
    vector <Class> Aulas = {};
    for(const auto& subject : subjects){
        for(const auto& cT : rc.get_classes_T()){
            if(cT.get_Subject() == subject) Aulas.push_back(cT);
        }
        for(const auto& cTP : rc.get_classes_TP()){
            if(cTP.get_Subject() == subject) Aulas.push_back(cTP);
        }
        for(const auto& cPL : rc.get_classes_PL()){
            if(cPL.get_Subject() == subject) Aulas.push_back(cPL);
        }
    }
    return Aulas;
}

int Operations::N_of_students_in_class(Subject key) const{
    vector<Subject> subjects =  rs.get_subjects();
    int low = 0;
    int high = subjects.size() - 1;
    while(low <= high){
        int middle = low + (high - low) / 2;
        if(key < subjects[middle]) high = middle - 1;
        else if(key > subjects[middle]) low = middle + 1;
        else return subjects[middle].get_number_of_student();
    }
    return -1;
}

int Operations::N_of_students_in_UC(Subject key) const{
    int i,R = 0;
    vector<Subject> subjects =  rs.get_subjects();
    int low = 0;
    int high = subjects.size() - 1;
    while(low <= high){
        int middle = low + (high - low) / 2;
        if(key.UC_is_less(subjects[middle])) high = middle - 1;
        else if(key.get_UCcode() > subjects[middle].get_UCcode()) low = middle + 1;
        else{
            i = middle;
            break;
        }
    }
    int m = i;
    for(m; subjects[m].UC_is_equal(key) ;m++){
        R+= subjects[m].get_number_of_student();
    }
    i--;
    for(i; subjects[i].UC_is_equal(key) ;i--){
        R+= subjects[i].get_number_of_student();
    }
    return R;
}


