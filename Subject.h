//
// Created by musta on 08.10.2022.
//

#ifndef UNTITLED_SUBJECT_H
#define UNTITLED_SUBJECT_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;


class Subject {
    public:
        // constructor by string csv format UCcode;ClassCode
        explicit Subject(const string& input_line);
        Subject(){UCcode = "1";ClassCode = "1";};
        // constructor
        Subject(const string& s1, const string& s2);
        // getters
        string get_UCcode() const;
        string get_ClassCode() const;
        // get year of Subject
        int get_year() const;
    private:
        string UCcode;
        string ClassCode;
};


#endif //UNTITLED_SUBJECT_H
