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
     * Complex O(Nlog(N))
     * @param fm_student -> Name of the students_classes csv file.
     * @param UC_student -> Name of the classes_per_uc csv file.
     * @param fm_classes -> Name of the classes csv file.
     */
    Operations(const string& fm_student, const string& UC_student,const string& fm_classes);

    ///@brief Empty constructor.
    /// Complex O(Nlog(N))
    Operations();

    /**
     * @brief Gets student time table.
     * Complex O(Nlog(N))
     * @param number -> Student code.
     * @return List with classes.
     */
    list<Class> GetTimeTable(const string& number);

    /**
     * @brief Gets UC time table.
     * @param UC -> UC code.
     * @return List with classes.
     */
    list<Class> GetTimeTableforUC(const string& UC);

    /**
     * @brief Prints time table.
     * Complex O(N)
     * @param v -> List with classes.
     */
    void print_time_table(list<Class> v) const;

    /**
     * @brief Gets number of student in a class.
     * Complex O(log(N))
     * @param s -> Subject.
     * @return Number of students.
     */
    int N_of_students_in_class(Subject s) const;

    /**
     * @brief Gets number of students in a year mapping with UCs.
     *Complex O(Nlog(N))
     * @param n -> Year to search.
     * @return map with UCs and number of students in UCs.
     */
    map<string, int> N_of_students_in_year(int n) const;

    /**
     * @brief Gets number of student in all UCs and list of all classes in uc.
     * Complex O(N)
     * @param s -> Subject.
     * @return List of subjects with the number of students
     */
    list<Subject> N_of_students_in_UC(Subject s) const;

    /**
     * @brief Gets students in a class.
     * Complex O(Nlog(N))
     * @param s -> Subject.
     * @return List of students.
     */
    list<Student> students_in_class(Subject s) const;

    /**
     * @brief Gets students in a year.
     * Complex O(Nlog(N))
     * @param n -> Year to search for.
     * @return List of students.
     */
    list<Student> students_in_year(int n) const;

    /**
     * @brief Gets students in a UC.
     * Complex O(Nlog(N))
     * @param s -> Subject.
     * @return List of students.
     */
    list<Student> students_in_UC(Subject s) const;

    /**
     * @brief Gets students with more than 'X' UC.
     * Complex O(N)
     * @param n -> Base number of UC.
     * @return List of students.
     */
    list<Student> students_with_more_UC(int n) const;

    /**
     * @brief Search students with specific name.
     * Complex O(N^2)
     * @param name -> Name to search for.
     * @return List of Students.
     */
    list<Student> students_with_name(const string& name) const;

    /**
     * @brief Proccess requests of students.
     * Complex O(N^2*log(N))
     * @param fn -> file name with queue of requirements
     */
    void processChanges(const string& fn);

    /// @brief Gets maximum capacity of a class;
    /// Complex O(1)
    int getCap() const;

    int Cap; /// @brief Maximum capacity of a class.
private:
    Read_classes rc; /// @brief Read_classes object with 3 sets containing classes.
    Read_student rs; /// @brief Read_student object with 1 set with all students and 1 vector with with all subjects.
};

#endif //UNTITLED_OPERATIONS_H
