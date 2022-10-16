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
        explicit Student(const string& input_line); // tem que mudar o subject method
        // getters
        string get_name() const;
        int get_StudentCode() const;
        vector<Subject> getSubjects() const;
        // to add one more class to student instead create new student
        void add_subject(const string& input_line);
        // print to
        friend ostream& operator<< (ostream& out, const Student& s1);
        // compare function by name or by up
        bool is_less_than_by_name(const Student& right);
        bool is_less_than_by_code(const Student& right) const;
        // remove subject from vector UCs
        //void remove_subject(const Subject& subject); // acho que nao vale a pena esta funcao, porque vamos so trocar os esudantes.

    private:
        string name;
        int StudentCode;
        vector<Subject> UCs;
};


#endif //UNTITLED_STUDENT_H
