//
// Created by musta on 30.10.2022.
//


#include "Student.h"

bool sortStudentsByNameAssending(const Student& s1, const Student& s2 ){
    return s1.get_name() < s2.get_name();
}

bool SortStudentsByNameDescn(const Student& s1, const Student& s2 ){
    return s1.get_name() > s2.get_name();
}

