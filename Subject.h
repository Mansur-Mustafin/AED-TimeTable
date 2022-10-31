//
// Created by Mansur on 08.10.2022.
//

/**
 * @file Subject.h
 */
#ifndef UNTITLED_SUBJECT_H
#define UNTITLED_SUBJECT_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>


using namespace std;

/**
 * @class containing class information.
 */
class Subject {
    public:
        // constructor by string csv format UCcode;ClassCode
        explicit Subject(const string& input_line);

        Subject(){UCcode = "1";ClassCode = "1";number_of_student = 0;};

        Subject(const string& s1, const string& s2);

        /// @brief gets UC code.
        string get_UCcode() const;

        /// @brief Gets class code.
        string get_ClassCode() const;

        ///@brief Gets year of subject.
        int get_year() const;

        ///@brief gets student number in UC.
        int get_number_of_student() const;

        /// @brief Overload of <em>operator< </em>.
        bool operator<(const Subject& right) const;

        /// @brief Overload of <em>operator<= </em>.
        bool operator<=(const Subject& right) const;

        /// @brief Overload of <em>operator> </em>.
        bool operator>(const Subject& right) const;

        /// @brief Overload of <em>operator=> </em>.
        bool operator>=(const Subject& right) const;

        /// @brief Overload of <em>operator== </em>.
        bool operator==(const Subject& right) const;

        /// @brief Overload of <em>operator!= </em>.
        bool operator!=(const Subject& right) const;

        /// @brief Check if UCs are equal.
        bool UC_is_equal(const Subject& right) const;

        /// @brief Compares UC.
        bool UC_is_less(const Subject& right) const;

        /// @brief Increases number of student in UC.
        void plus_student_n();

        /// @brief Decreases number of student in UC.
        void minus_student_n();


    private:
        string UCcode; /// @brief UC code.
        string ClassCode; /// @brief Class code.
        int number_of_student; /// @brief Number of students in UC.
};


#endif //UNTITLED_SUBJECT_H
