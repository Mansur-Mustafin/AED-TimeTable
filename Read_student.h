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
     * complex: O(Nlog(N))
     * @param fm_student -> Name of the csv file student_classes.
     * @param UC_student ->  Name of the csv file classes_per_uc.
     */
    explicit Read_student(const string& fm_student, const string& UC_student);

    /// @brief Default constructor.
    ///complex: O(1)
    Read_student();

    /**
     * @brief Setter for student.
     * complex: O(1)
     * @param vnew -> New set of students.
     */
    void setStudents(set<Student>& vnew);

    /**
     * @brief Setter for subjects.
     * complex: O(1)
     * @param snew -> New set of subjects.
     */
    void setSubjects(vector<Subject>& snew);

    /// @brief Gets students.
    ///complex: O(1)
    set<Student> get_students() const;

    /// @brief Gets subjects.
    ///complex: O(1)
    vector<Subject> get_subjects() const;

private:
    set<Student> v; /// @brief Students list.
    vector<Subject> s; /// @brief Subjects list.
};


#endif //UNTITLED_READ_STUDENT_H
