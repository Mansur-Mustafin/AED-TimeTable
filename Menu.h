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
#include "read_student.h"
#include "Operations.h"

using namespace std;

/**
 * @class Menu.
 */
class Menu {

public:
    /// @brief Empty Constructor.
    Menu();

    /// @brief Prints menu and calls other functions.
    void main_menu();

    /// @brief Show options and calls functions for students operations.
    void students_operations();

    /// @brief Calls function to show number of students in year divided per UC.
    void number_of_students_in_year_per_uc();

    /// @brief Calls function to search for students with specific name.
    void students_with_name();

    /// @brief Calls function to show students in year.
    void show_students_in_year();

    /// @brief Show options and calls functions for classes operations.
    void classes_operations();

    /// @brief Show options and calls functions for UC's operations.
    void uc_operations();

    /// @brief Calls function to list students with more than 'X' UC's.
    void students_with_more_uc();

    /// @brief Gets data for a request to change class and writes it to a file.
    void request_change_class();

    /// @brief Calls function to process requests from students.
    void process_requests();
private:

    //void students_operations();

    Operations op; /// @brief Operations object with functions to proccess data.
};


#endif //UNTITLED_MENU_H
