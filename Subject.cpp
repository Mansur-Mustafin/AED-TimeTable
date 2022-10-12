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

int Subject::get_year() const { // if UP001
    if(UCcode == "UP001") return 1;
    char year = ClassCode[0];
    return int(year) - 48;
}

bool Subject::operator<(const Subject& right) const{
    if(UCcode == "UP001" && right.UCcode != "UP001") return false;
    else if(UCcode != "UP001" && right.UCcode == "UP001") return true;
    else if(UCcode == "UP001" && right.UCcode == "UP001"){
        return ClassCode < right.ClassCode;
    }
    else if(this->get_year() > right.get_year()) return false;
    else if(this->get_year() < right.get_year()) return true;
    else if(this->UCcode < right.UCcode) return true;
    else if(this->UCcode > right.UCcode) return false;
    else if(this->UCcode == right.UCcode && this->ClassCode < right.ClassCode) return true;
    else return false;
}

bool Subject::operator>(const Subject &right) const {
    if(UCcode == "UP001" && right.UCcode != "UP001") return true;
    else if(UCcode != "UP001" && right.UCcode == "UP001") return false;
    else if(UCcode == "UP001" && right.UCcode == "UP001"){
        return ClassCode > right.ClassCode;
    }
    if(get_year() > right.get_year()) return true;
    else if(get_year() < right.get_year()) return false;
    else if(UCcode < right.UCcode) return false;
    else if(UCcode > right.UCcode) return true;
    else if(ClassCode > right.ClassCode) return true;
    return false;
}

bool Subject::operator==(const Subject& right) const{
    if(UCcode == right.UCcode && ClassCode == right.ClassCode) return true;
    return false;
}

/*
int Subject::get_number_of_student() const {
    return number_of_students;
}

void Subject::update_n_students() {
    number_of_students++;
}
*/

bool Subject::UC_is_equal(const Subject &right) const {
    return UCcode==right.get_UCcode();
}

bool Subject::UC_is_less(const Subject &right) const {
    return UCcode<right.get_UCcode();
}
