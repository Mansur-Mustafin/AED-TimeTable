//
// Created by musta on 16.10.2022.
//

#include "Operations.h"
Operations::Operations(const std::string &fm_student, const std::string &UC_student, const std::string &fm_classes) {
    Read_classes rc = Read_classes (fm_classes);
    Read_student rs = Read_student (fm_student, UC_student);
    this->rs = rs;
    this->rc = rc;
    //cout << rs.get_students().size();
}

vector<Class> Operations::GetTimeTable(const std::string &number) {
    //cout << rs.get_students().size();
    vector<Subject> subjects =  rs.Bynary_serch_of_student(number).getSubjects();

    Student s = rs.Bynary_serch_of_student(number);
    //cout << s;


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