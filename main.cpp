#include <iostream>
#include "Student.h"
#include "Hour.h"
#include "Subject.h"
#include "Read_class_per_uc.h"
#include <fstream>
#include <algorithm>
#include "Read_classes.h"

int main() {
    Read_classes a ("classes.csv");
    Subject s ("L.EIC023,3LEIC06");
    //for(auto p : a.get_classes_T()) cout << p.get_day();


    int index_T = a.Binary_search_of_class_T(s);
    int index_TP = a.Binary_search_of_class_TP(s);
    int index_PL = a.Binary_search_of_class_PL(s);

    cout << index_T ;
    //cout << a.get_classes_TP()[index_TP].get_day();
    cout << a.get_classes_T()[index_T].get_day() << ' ' << a.get_classes_PL()[index_PL].get_day();


    return 0;
}
