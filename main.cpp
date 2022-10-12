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
    Subject s ("L.EIC003,1LEIC01");

    for(auto p : a.get_classes_T()) {
        cout << p.get_Subject().get_UCcode() << ' ' << p.get_Subject().get_ClassCode() <<  endl;
    }

    vector<Class> index_T = a.Binary_search_of_class_T(s);

    for(auto p : index_T){cout << p.get_day()<< p.get_hora_s().get_hora()<< p.get_hora_s().get_minutes() << endl;}


    return 0;
}
