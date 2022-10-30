//
// Created by Mansur on 12.10.2022.
//

#ifndef UNTITLED_READ_CLASSES_H
#define UNTITLED_READ_CLASSES_H
#include <vector>
#include <set>
#include "Class.h"

class Read_classes {
public:
    explicit Read_classes(const string& input_name_file);
    Read_classes();
    set<Class> get_classes_T() ;
    set<Class> get_classes_TP();
    set<Class> get_classes_PL();
    //set <Class> Binary_search_of_class_T(Subject key);
    //Class Binary_search_of_class_TP(Subject key);
    //Class Binary_search_of_class_PL(Subject key);

private:
    set<Class> classes_T;
    set<Class> classes_TP;
    set<Class> classes_PL;
};


#endif //UNTITLED_READ_CLASSES_H
