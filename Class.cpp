//
// Created by Mansur on 08.10.2022.
//

#include "Class.h"

Class::Class(const std::string &input_line) {
    string feel, feel1;
    istringstream input (input_line);
    getline(input, feel, ','); // ClassCode
    getline(input, feel1, ','); //
    subject = Subject(feel1, feel);
    getline(input, feel, ',');
    day = feel;
    getline(input, feel, ',');
    hora_s = Hour(stof(feel));
    getline(input, feel, ',');
    duration = Hour(stof(feel));
    getline(input, feel, ',');
    type = feel;
}

Subject Class::get_Subject() const{
    return this->subject;
}

string Class::get_day() const{
    return this->day;
}

int Class::get_day_index() const{
    map<string, int> index_day {{"Monday",0},{"Tuesday",1},{"Wednesday",2},{"Thursday",3},{"Friday",4}};
    return index_day[day];
}
Hour Class::get_hora_s() const{
    return hora_s;
}
Hour Class::get_hora_f() const{
    Hour h = hora_s + duration;
    return h;
}
Hour Class::get_duration() const{
    return duration;
}
string Class::get_type() const{
    return type;
}


