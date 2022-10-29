//
// Created by ianbe on 27/10/2022.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "read_student.h"
#include "Operations.h"

using namespace std;

class Menu {

public:
    Menu();

    void main_menu();

    void students_operations();

    void number_of_students_in_year();

    void students_with_name();

    void show_students_in_year();

    void classes_operations();

    void uc_operations();

    void students_with_more_uc();
private:

    //void students_operations();

    Operations op ;
};


#endif //UNTITLED_MENU_H
