//
// Created by Mansur on 08.10.2022.
//

/**
 * @file Student.h
 */


#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include "Subject.h"


using namespace std;

/**
 * @class containing student information.
 */
class Student {
    public:

        /**
         * @brief Constructor.
         * complex: O(1)
         * @param input_line -> Line from csv file containing student.
         */
        explicit Student(const string& input_line);

        /**
         * @brief Constructor.
         * complex: O(1)
         * @param name -> Student name.
         * @param code -> Student code.
         * @param UC -> Subjects taken by student.
         */
        Student(const string& name, int code, set<Subject>& UC);


        /// @brief Empty constructor
        ///complex: O(1)
        Student();

        /**
         * @brief Gets student's name.
         * complex: O(1)
         * @return Name
         */

        string get_name() const;

        /**
         * @brief Gets student's code.
         * complex: O(1)
         * @return Student code
         */
        int get_StudentCode() const;

        /**
         * @brief Gets student's subjects
         * complex: O(1)
         * @return Subjects
         */
        set<Subject> getSubjects() const;

        ///@brief Set subjects for student
        ///@param s -> new set of subjects of student
        ///complex: O(1)
        void setSubjects(set<Subject>& s);

        /**
         * @brief Adds subject to a existing student
         * complex: O(1)
         * @param input_line -> line in the format of csv file
         */
        void add_subject(const string& input_line);


        ///@brief Overload of <em>operator<< </em>
        ///complex: O(1)
        friend ostream& operator<< (ostream& out, const Student& s1);

        /// @brief Overload of <em>operator< </em>.
        ///complex: O(1)
        bool operator<(const Student& right) const;

        /// @brief Overload of <em>operator> </em>.
        ///complex: O(1)
        bool operator>(const Student& right) const;

        /// @brief Overload of <em>operator<= </em>.
        ///complex: O(1)
        bool operator<=(const Student& right) const;

        /// @brief Overload of <em>operator=> </em>.
        ///complex: O(1)
        bool operator>=(const Student& right) const;

        /// @brief Overload of <em>operator== </em>.
        ///complex: O(1)
        bool operator==(const Student& right) const;

        /// @brief Compares students by name
        ///complex: O(1)
        bool is_less_than_by_name(const Student& right);

        /// @brief Compares students by student code
        ///complex: O(1)
        bool is_less_than_by_code(const Student& right) const;


    private:
        string name;  /// @brief Student name
        int StudentCode; /// @brief Student code
        set<Subject> UCs; /// @brief student UC's
};

#endif //UNTITLED_STUDENT_H
