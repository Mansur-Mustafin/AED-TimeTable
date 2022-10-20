//
// Created by Mansur on 16.10.2022.
//

#ifndef UNTITLED_OPERATIONS_H
#define UNTITLED_OPERATIONS_H

#include "Read_student.h"

class Operations {
public:
    Operations(const string& fm_student, const string& UC_student,const string& fm_classes);
    vector<Class> GetTimeTable(const string& number); // encontra horario por numero up recebe string mesmo
    void print_time_table(vector<Class> v) const;
    int N_of_students_in_class(Subject s) const; // input: uma turma, output: numero de estudantes inscritos testa turma
    int N_of_students_in_year(int n) const; // input year
    int N_of_students_in_UC(Subject s) const;  // input : Subject("L.EIC001,xXXXXxx") se quiseres a UC L.EIC001
    vector<Student> students_in_class(Subject s) const;
    vector<Student> students_in_year(int n) const;
    vector<Student> students_in_UC(Subject s) const;
    vector<Student> students_with_more_UC(int n) const;
private:
    Read_classes rc;
    Read_student rs;
};

#endif //UNTITLED_OPERATIONS_H
