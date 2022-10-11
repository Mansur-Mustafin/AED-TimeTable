#include <iostream>
#include "Student.h"
#include "Hour.h"
#include "Subject.h"
#include "Read_class_per_uc.h"
#include <fstream>
#include <algorithm>


int main() {

    Read_class_per_uc a ("classes_per_uc.csv");
    Subject s ("L.EIC025,3LEIC08");
    cout << a.Binary_search(s);
    return 0;

}

