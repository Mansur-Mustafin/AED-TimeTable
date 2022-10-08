//
// Created by Mansur on 08.10.2022.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include "Subject.h"

using namespace std;

class Student {
    public:
        //constructor by string csv format ';'
        explicit Student(const string& input_line);
        // getters
        string get_name() const;
        unsigned long get_StudentCode() const;
        vector<Subject> getClasses() const;
        // to add one more class to student instead create new student
        void add_class(const string& input_line);
        // print to
        friend ostream& operator<< (ostream& out, const Student& s1);
        // compare function by name or by up
        bool is_less_than_by_name(const Student& right);
        bool is_less_than_by_code(const Student& right);
    private:
        string name;
        unsigned long StudentCode{};
        vector<Subject> UCs;
};


#endif //UNTITLED_STUDENT_H
