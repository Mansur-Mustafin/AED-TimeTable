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
         * @param input_line -> Line from csv file containing student.
         */
        explicit Student(const string& input_line);

        Student(const string& name, int code, set<Subject>& UC);


        /// @brief Empty constructor
        Student();

        /**
         * @brief Gets student's name.
         * @return Name
         */
        string get_name() const;

        /**
         * @brief Gets student's code.
         * @return Student code
         */
        int get_StudentCode() const;

        /**
         * @brief Gets student's subjects
         * @return Subjects
         */
        set<Subject> getSubjects() const;


        void setSubjects(set<Subject>& s);

        /**
         * @brief Adds subject to a existing student
         * @param input_line -> line in the format of csv file
         */
        void add_subject(const string& input_line);

        // FALTA AQUI!!!

        ///@brief Overload of <em>operator<< </em>
        friend ostream& operator<< (ostream& out, const Student& s1);

        /// @brief Overload of <em>operator< </em>.
        bool operator<(const Student& right) const;

        /// @brief Overload of <em>operator> </em>.
        bool operator>(const Student& right) const;

        /// @brief Overload of <em>operator<= </em>.
        bool operator<=(const Student& right) const;

        /// @brief Overload of <em>operator=> </em>.
        bool operator>=(const Student& right) const;

        /// @brief Overload of <em>operator== </em>.
        bool operator==(const Student& right) const;

        /// @brief Compares students by name
        bool is_less_than_by_name(const Student& right);

        /// @brief Compares students by student code
        bool is_less_than_by_code(const Student& right) const;


    private:
        string name;  /// @brief Student name
        int StudentCode; /// @brief Student code
        set<Subject> UCs; /// @brief student UC's
};

#endif //UNTITLED_STUDENT_H
