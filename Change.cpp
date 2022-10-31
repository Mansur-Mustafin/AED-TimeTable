//
// Created by musta on 30.10.2022.
//

#include "Change.h"

Change::Change(const std::string &input_line) {
    string UCcode, Classcode;
    istringstream input (input_line);
    getline(input, UCcode, ','); // reed StudentCode
    getline(input, Classcode, ','); // reed name
    cur = Subject(UCcode,Classcode);
    string number;
    getline(input, number, ','); // reed UCcode
    student = Student(number+",Mansur,L.EIC001,1LEIC01");
    getline(input, UCcode, ','); // reed StudentCode
    getline(input, Classcode, ','); // reed name
    next = Subject(UCcode,Classcode);
}

Student Change::getStudent() const{
    return student;
}

Subject Change::getCurSub() const{
    return cur;
}

Subject Change::getNextSub() const{
    return next;
}