//
// Created by musta on 16.10.2022.
//

#ifndef UNTITLED_OPERATIONS_H
#define UNTITLED_OPERATIONS_H

#include "Read_student.h"

class Operations {
public:
    Operations(const string& fm_student, const string& UC_student,const string& fm_classes);
    vector<Class> GetTimeTable(const string& number); // encontra horario por numero up recebe string mesmo
private:
    Read_classes rc;
    Read_student rs;
};


#endif //UNTITLED_OPERATIONS_H
