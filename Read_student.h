//
// Created by musta on 14.10.2022.
//

#ifndef UNTITLED_READ_STUDENT_H
#define UNTITLED_READ_STUDENT_H
#include "Read_classes.h"
#include "Student.h"

class Read_student {
public:
    Read_student(const string& fm_student, const string& UC_student);
    vector<Student> get_students() const;
    vector<Subject> get_subjects() const;
private:
    vector<Student> v;
    vector<Subject> s;
};


#endif //UNTITLED_READ_STUDENT_H
