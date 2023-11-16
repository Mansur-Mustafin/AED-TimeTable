//
// Created by ianbe on 27/10/2022.
//

/**
 * @file Menu.h
 */

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <climits>
#include "Read_student.h"
#include "Operations.h"


using namespace std;

/**
 * @class Menu.
 */
class Menu {

public:
    /// @brief Empty Constructor.
    /// Complex O(Nlog(N))
    Menu();

    /// @brief Prints menu and calls other functions.
    /// Complex O(1)
    void main_menu();

    /// @brief Show options and calls functions for students operations.
    /// Complex O(Nlog(N))
    void students_operations();

    /// @brief Calls function to show number of students in year divided per UC.
    ///Complex O(Nlog(N))
    void number_of_students_in_year_per_uc();

    /// @brief Calls function to search for students with specific name.
    ///Complex O(N^2)
    void students_with_name();

    /// @brief Calls function to show students in year.
    ///Complex O(Nlog(N))
    void show_students_in_year();

    /// @brief Show options and calls functions for classes operations.
    ///Complex O(Nlog(N))
    void classes_operations();

    /// @brief Show options and calls functions for UC's operations.
    ///Complex O(Nlog(N))
    void uc_operations();

    /// @brief Calls function to list students with more than 'X' UC's.
    ///Complex O(Nlog(N))
    void students_with_more_uc();

    /// @brief Gets data for a request to change class and writes it to a file.
    ///Complex O(1)
    void request_change_class();

    /// @brief Calls function to process requests from students.
    ///Complex O(N^2)
    void process_requests();
private:
    Operations op; /// @brief Operations object with functions to proccess data.
};


#endif //UNTITLED_MENU_H
