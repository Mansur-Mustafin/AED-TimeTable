//
// Created by Mansur on 14.10.2022.
//

/**
 * @file Read_student.h
 */

#ifndef UNTITLED_READ_STUDENT_H
#define UNTITLED_READ_STUDENT_H
#include "Read_classes.h"
#include "Student.h"

/**
 * @class that reads students csv file
 */
class Read_student {
public:

    /**
     * @brief Constructor.
     * @param fm_student -> Name of the csv file.
     * @param UC_student
     */
    explicit Read_student(const string& fm_student, const string& UC_student);

    /// @brief Empty constructor.
    Read_student();

    /// @brief Gets students.
    set<Student> get_students() const;

    /// @brief Gets subjects.
    vector<Subject> get_subjects() const;

    /// @brief Finds student in students set by student code.
    Student Bynary_serch_of_student(const string& key); // encontra estudante em vetor dos estudantes por numero UP
private:
    set<Student> v; /// @brief Students list.
    vector<Subject> s; /// @brief Subjects list.
};


#endif //UNTITLED_READ_STUDENT_H
