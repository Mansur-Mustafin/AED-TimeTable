//
// Created by Mansur on 16.10.2022.
//

#ifndef UNTITLED_OPERATIONS_H
#define UNTITLED_OPERATIONS_H

#include "Read_student.h"
#include "ReadRequests.h"
#include <list>

class Operations {
public:
    Operations(const string& fm_student, const string& UC_student,const string& fm_classes);
    Operations();
    list<Class> GetTimeTable(const string& number); // encontra horario por numero up recebe string mesmo
    list<Class> GetTimeTableforUC(const string& UC);
    void print_time_table(list<Class> v) const;
    int N_of_students_in_class(Subject s) const; // input: uma turma, output: numero de estudantes inscritos testa turma
    int N_of_students_in_year(int n) const; // input year
    int N_of_students_in_UC(Subject s) const;  // input : Subject("L.EIC001,xXXXXxx") se quiseres a UC L.EIC001
    list<Student> students_in_class(Subject s) const;
    list<Student> students_in_year(int n) const;
    list<Student> students_in_UC(Subject s) const;
    list<Student> students_with_more_UC(int n) const;
    list<Student> students_with_name(const string& name) const;
    void processChanges(const string& fn) const;
private:
    Read_classes rc;
    Read_student rs;
};

#endif //UNTITLED_OPERATIONS_H
