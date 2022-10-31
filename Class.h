//
// Created by Mansur on 08.10.2022.
//

/**
 * @file Class.h
 */

#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include "Hour.h"
#include "Subject.h"
#include <iostream>
using namespace std;

/**
 * @class Containing class information.
 */
class Class {
    public:
        /**
         * @brief Constructor.
         * @param input_line -> Line from csv file containing class details.
         */
        explicit Class(const string& input_line);

        /// @brief Gets subject of the class.
        Subject get_Subject() const;

        /**
         * @brief Gets day of the class.
         * @return string with the name of the day
         */
        string get_day() const;

        /**
         * @brief Gets day index.
         * @return Index of the day(Monday = 0, ... , Friday = 4)
         */
        int get_day_index() const; // Monday -> 0, Tuesday -> 1 ....

        /// @brief Gets start time of the class.
        Hour get_hora_s() const;

        /// @brief Gets finish time of the class.
        Hour get_hora_f() const;

        /// @brief Gets duration of the class.
        Hour get_duration() const;

        /// @brief Gets the type of the class.
        string get_type() const;

        /// @brief Compares classes by less.
        bool is_less(Class right) const;

        /// @brief Compares classes by more.
        bool is_more(Class right) const;

        /// @brief Check if classes are equal.
        bool is_equal(Class right) const;

        /// @brief Overload of <em>operator< </em>.
        bool operator<(const Class& right) const;

        /// @brief Overload of <em>operator> </em>.
        bool operator>(const Class& right) const;

        /// @brief Overload of <em>operator== </em>.
        bool operator==(const Class& right) const;

        friend ostream& operator<< (ostream& out, const Class& s1);
    private:
        Subject subject; /// @brief Class subject
        string day; /// @brief Class day
        Hour hora_s; /// @brief Class start time
        Hour duration; /// @brief Class duration
        string type; /// @brief Class type
};


#endif //UNTITLED_CLASS_H
