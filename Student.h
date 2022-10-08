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

using namespace std;

class Student {
    public:
        //constructor by string csv format ';'
        explicit Student(const string& parametrs);
        // getters
        string get_name() const;
        unsigned long get_StudentCode() const;


    private:
        string name;
        unsigned long StudentCode{};
        map<string, vector<string>> UCs;
};


#endif //UNTITLED_STUDENT_H
