//
// Created by musta on 11.10.2022.
//

#include <fstream>

#include "Read_class_per_uc.h"


Read_class_per_uc::Read_class_per_uc(const string& input_name_file){
    ifstream in(input_name_file);
    string line;
    getline(in, line);       // to - first line
    while (getline(in, line)){
        Subject s (line);
        subjects.push_back(s);
    }
}

vector<Subject> Read_class_per_uc::get_subjects() const {
    return subjects;
}

int Read_class_per_uc::Binary_search(const Subject& key) const{
    int low = 0;
    int high = subjects.size() - 1;
    while(low <= high){
        int middle = low + (high - low) / 2;
        if(key < subjects[middle]) high = middle - 1;
        else if(key > subjects[middle]) low = middle + 1;
        else return middle;
    }
    return -1;
}

