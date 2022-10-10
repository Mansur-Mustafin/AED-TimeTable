//
// Created by Mansur on 08.10.2022.
//

#include "Student.h"

Student::Student(const std::string &input_line) {
    string feel, feel1;
    istringstream input (input_line);
    getline(input, feel, ','); // reed StudentCode
    StudentCode = stoul(feel);
    getline(input, feel, ','); // reed name
    name = feel;
    getline(input, feel, ','); // reed UCcode
    getline(input, feel1, ','); // reed ClassCode
    UCs.push_back(Subject(feel, feel1));
}

string Student::get_name() const {
    return this->name;
}

unsigned long Student::get_StudentCode() const {
    return this->StudentCode;
}

void Student::add_subject(const std::string &input_line) {
    string feel , feel1;
    istringstream input (input_line);
    getline(input, feel, ',');
    getline(input, feel, ',');
    getline(input, feel, ',');
    getline(input, feel1, ',');
    this->UCs.push_back(Subject(feel, feel1));
}

vector<Subject> Student::getClasses() const {
    return UCs;
}

ostream& operator<< (ostream& out, const Student& s1){
    out << s1.get_name() << ' ' << s1.get_StudentCode();
    return out;
}

bool Student::is_less_than_by_name(const Student& right){
    return this->name < right.name;
}

bool Student::is_less_than_by_code(const Student& right){
    return this->StudentCode < right.StudentCode;
}

void Student::remove_subject(const Subject& subject){
    vector<Subject>::iterator it;
    for(it = UCs.begin() ; it != UCs.end(); it++){
        if((*it == subject)){
            UCs.erase(it);
            break;
        }
    }

}





