//
// Created by Mansur on 08.10.2022.
//

#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include "Hour.h"
#include "Subject.h"

using namespace std;

class Class {
    public:
        explicit Class(const string& input_line);
    private:
        Subject index;
        string day;
        Hour hora_s;
        Hour duration;
        string type;
};


#endif //UNTITLED_CLASS_H
