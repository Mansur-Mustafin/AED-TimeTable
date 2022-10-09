//
// Created by Mansur on 08.10.2022.
//

#include "Class.h"

Class::Class(const std::string &input_line) {
    string feel, feel1;
    istringstream input (input_line);
    getline(input, feel, ','); // ClassCode
    getline(input, feel1, ','); //
    index = Subject(feel1, feel);
    getline(input, feel, ',');
    day = feel;
    getline(input, feel, ',');
    hora_s = Hour(stof(feel));
    getline(input, feel, ',');
    duration = Hour(stof(feel));
    getline(input, feel, ',');
    type = feel;
}
