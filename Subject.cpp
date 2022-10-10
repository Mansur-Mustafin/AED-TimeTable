//
// Created by musta on 08.10.2022.
//

#include "Subject.h"

Subject::Subject(const string& input_line){
    string feel, feel1;
    istringstream input (input_line);
    getline(input, feel, ',');
    getline(input, feel1, ',');
    UCcode = feel;
    ClassCode = feel1;
}

Subject::Subject(const string& s1, const string& s2){
    UCcode = s1;
    ClassCode = s2;
}

string Subject::get_UCcode() const {
    return UCcode;
}
string Subject::get_ClassCode() const {
    return ClassCode;
}

int Subject::get_year() const {
    char year = ClassCode[0];
    return int(year) - 48;
}

bool Subject::operator<(const Subject& right) const{
    if(this->get_year() > right.get_year()) return false;
    else if(this->UCcode < right.UCcode) return true;
        else if(this->UCcode > right.UCcode) return false;
        else if(this->UCcode == right.UCcode && this->ClassCode < right.ClassCode) return true;
        else return false;

}

bool Subject::operator==(const Subject& right) const{
    if(UCcode == right.UCcode && ClassCode == right.ClassCode) return true;
    return false;
}

