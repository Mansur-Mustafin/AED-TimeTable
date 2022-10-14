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
#include <iostream>
using namespace std;

class Class {
    public:
        explicit Class(const string& input_line);
        Subject get_Subject() const;
        string get_day() const;
        int get_day_index() const; // Monday -> 0, Tuesday -> 1 ....
        Hour get_hora_s() const;
        Hour get_hora_f() const; // retorna fim de aula
        Hour get_duration() const;
        string get_type() const;
        bool is_less(Class right) const;
        bool is_more(Class right) const;
        bool is_equal(Class right) const;

    private:
        Subject subject;
        string day;
        Hour hora_s;
        Hour duration;
        string type;
};


#endif //UNTITLED_CLASS_H
