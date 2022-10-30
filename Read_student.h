//
// Created by Mansur on 14.10.2022.
//

#ifndef UNTITLED_READ_STUDENT_H
#define UNTITLED_READ_STUDENT_H
#include "Read_classes.h"
#include "Student.h"

class Read_student {
public:
    explicit Read_student(const string& fm_student, const string& UC_student);
    Read_student();
    set<Student> get_students() const;
    vector<Subject> get_subjects() const;
    Student Bynary_serch_of_student(const string& key); // encontra estudante em vetor dos estudantes por numero UP
private:
    set<Student> v;
    vector<Subject> s;
};


#endif //UNTITLED_READ_STUDENT_H
