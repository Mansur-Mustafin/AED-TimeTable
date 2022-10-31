//
// Created by Mansur on 16.10.2022.
//

/**
 * @file Operations.h
 */

#ifndef UNTITLED_OPERATIONS_H
#define UNTITLED_OPERATIONS_H

#include "Read_student.h"
#include "ReadRequests.h"
#include <list>

/**
 * @class with methods to do all sorts of operations with the received data.
 */
class Operations {
public:
    /**
     * @brief Constructor.
     * @param fm_student -> Name of the students_classes csv file.
     * @param UC_student -> Name of the classes_per_uc csv file.
     * @param fm_classes -> Name of the classes csv file.
     */
    Operations(const string& fm_student, const string& UC_student,const string& fm_classes);

    ///@brief Empty constructor.
    Operations();

    /**
     * @brief Gets student time table.
     * @param number -> Student code.
     * @return List with classes.
     */
    list<Class> GetTimeTable(const string& number); // encontra horario por numero up recebe string mesmo

    /**
     * @brief Gets UC time table.
     * @param UC -> UC code.
     * @return List with classes.
     */
    list<Class> GetTimeTableforUC(const string& UC);

    /**
     * @brief Prints time table.
     * @param v -> List with classes.
     */
    void print_time_table(list<Class> v) const;

    /**
     * @brief Gets number of student in a class.
     * @param s -> Subject.
     * @return Number of students.
     */
    int N_of_students_in_class(Subject s) const; // input: uma turma, output: numero de estudantes inscritos testa turma

    /**
     * @brief Gets number of students in a year.
     * @param n -> Year to search.
     * @return Number of Students in year.
     */
    int N_of_students_in_year(int n) const; // input year

    /**
     * @brief Gets number of student in all UCs and list of all classes in uc.
     * @param s -> Subject.
     * @return List of subjects with the number of students
     */
    list<Subject> N_of_students_in_UC(Subject s) const;  // input : Subject("L.EIC001,xXXXXxx") se quiseres a UC L.EIC001

    /**
     * @brief Gets students in a class.
     * @param s -> Subject.
     * @return List of students.
     */
    list<Student> students_in_class(Subject s) const;

    /**
     * @brief Gets students in a year.
     * @param n -> Year to search for.
     * @return List of students.
     */
    list<Student> students_in_year(int n) const;

    /**
     * @brief Gets students in a UC.
     * @param s -> Subject.
     * @return List of students.
     */
    list<Student> students_in_UC(Subject s) const;

    /**
     * @brief Gets students with more than 'X' UC.
     * @param n -> Base number of UC.
     * @return List of students.
     */
    list<Student> students_with_more_UC(int n) const;

    /**
     * @brief Search students with specific name.
     * @param name -> Name to search for.
     * @return List of Students.
     */
    list<Student> students_with_name(const string& name) const;


    void processChanges(const string& fn) const;

    /// @brief Gets maximum capacity of a class;
    int getCap() const;

    int Cap; /// @brief Maximum capacity of a class.
private:
    Read_classes rc; /// @brief Read_classes object with 3 sets containing classes.
    Read_student rs; /// @brief Read_student object with 1 set with all students and 1 vector with with all subjects.

};

#endif //UNTITLED_OPERATIONS_H
