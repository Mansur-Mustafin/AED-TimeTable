//
// Created by musta on 11.10.2022.
//

#include <fstream>
#include "Read_class_per_uc.h"


Read_class_per_uc::Read_class_per_uc(const string& input_name_file){
    ifstream in(input_name_file);
    string line;
    getline(in, line);
    while (getline(in, line)){
        Subject s (line);
        subjects.push_back(s);
    }
}

vector<Subject> Read_class_per_uc::get_subjects() const {
    return subjects;
}

