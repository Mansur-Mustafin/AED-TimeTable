//
// Created by Mansur on 08.10.2022.
//

#include "Student.h"

Student::Student(const std::string &input_line) {
    string feel, feel1;
    istringstream input (input_line);
    getline(input, feel, ',');
    StudentCode = stoi(feel);
    getline(input, feel, ',');
    name = feel;
    getline(input, feel, ',');
    getline(input, feel1, ',');
    Subject s (feel, feel1);
    UCs.insert(s);
}

Student::Student(const std::string &name, int code, set<Subject>& UC) {
    UCs = UC;
    this->name = name;
    StudentCode = code;
}

Student::Student() {
    StudentCode = 0;
    name = "mansur";
}

string Student::get_name() const {
    return this->name;
}

int Student::get_StudentCode() const {
    return this->StudentCode;
}

void Student::add_subject(const std::string &input_line) {
    string feel , feel1;
    istringstream input (input_line);
    getline(input, feel, ',');
    getline(input, feel, ',');
    getline(input, feel, ',');
    getline(input, feel1, ',');
    Subject s (feel, feel1);

    UCs.insert(s);
}

set<Subject> Student::getSubjects() const {
    return UCs;
}

void Student::setSubjects(set<Subject>& s ) {
    UCs = s;
}

ostream& operator<< (ostream& out, const Student& s1){
    out << s1.get_name() << ' ' << s1.get_StudentCode();
    return out;
}

bool Student::is_less_than_by_name(const Student& right){
    return this->name < right.name;
}

bool Student::is_less_than_by_code(const Student& right) const{
    return this->StudentCode < right.StudentCode;
}

bool Student::operator<(const Student& right) const{
    return this->get_StudentCode() < right.get_StudentCode();
}

bool Student::operator>(const Student& right) const{
    return this->get_StudentCode() > right.get_StudentCode();
}

bool Student::operator<=(const Student& right) const{
    return this->get_StudentCode() <= right.get_StudentCode();
}

bool Student::operator>=(const Student& right) const{
    return this->get_StudentCode() >= right.get_StudentCode();
}

bool Student::operator==(const Student& right) const{
    return this->get_StudentCode() == right.get_StudentCode();
}