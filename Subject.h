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
        Subject(const string& s1, const string& s2);
        string get_UCcode() const;
        string get_ClassCode() const;
        int get_year() const; // get year of Subject
        bool operator < (const Subject& right) const; // pode ser errado
        bool operator>(const Subject& right) const;
        bool operator==(const Subject& right) const;
        bool UC_is_equal(const Subject& right) const;
        bool UC_is_less(const Subject& right) const;
    private:
        string UCcode;
        string ClassCode;
};


#endif //UNTITLED_SUBJECT_H
