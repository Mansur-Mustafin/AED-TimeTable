//
// Created by Mansur on 08.10.2022.
//

#include "Student.h"

Student::Student(const std::string &parametrs) {
    string feel, feel1;
    istringstream input (parametrs);
    getline(input, feel, ','); // reed StudentCode
    StudentCode = stoul(feel);
    getline(input, feel, ','); // reed name
    name = feel;
    getline(input, feel, ','); // reed UCcode
    getline(input, feel1, ','); // reed ClassCode
    if(UCs.find(feel) == UCs.end()){
        //pair<string,vector<string>> p ;
        UCs.insert({feel , {feel1}});
    }else{
        UCs[feel].push_back(feel1);
    }
}

string Student::get_name() const {
    return this->name;
}

unsigned long Student::get_StudentCode() const {
    return this->StudentCode;
}





