//
// Created by musta on 12.10.2022.
//

#include "Read_classes.h"
#include <fstream>
#include <algorithm>
Read_classes::Read_classes(const std::string &input_name_file) {
    ifstream in(input_name_file);
    string line;
    getline(in, line);
    while (getline(in, line)) {
        Class s(line);
        if (s.get_type() == "T") {
            classes_T.push_back(s);
        }
        if (s.get_type() == "TP") {
            classes_TP.push_back(s);
        }
        if (s.get_type() == "PL") {
            classes_PL.push_back(s);
        }
    }
    sort(classes_T.begin(),classes_T.end(), [ ]( const Class& lhs, const Class& rhs ){return lhs.is_less(rhs);} );
    sort(classes_TP.begin(),classes_TP.end(), [ ]( const Class& lhs, const Class& rhs ){return lhs.is_less(rhs);} );
    sort(classes_PL.begin(),classes_PL.end(), [ ]( const Class& lhs, const Class& rhs ){return lhs.is_less(rhs);} );
    // reescrever estes 3 funcoes!!!!!!!
}



vector<Class> Read_classes::get_classes_T() const{
    return classes_T;
}

vector<Class> Read_classes::get_classes_TP() const{
    return classes_TP;
}

vector<Class> Read_classes::get_classes_PL() const{
    return classes_PL;
}

int Read_classes::Binary_search_of_class_T(Subject key){
    int low = 0;
    int high = classes_T.size() - 1;
    while(low <= high){
        int middle = low + (high - low) / 2;
        if(key < classes_T[middle].get_Subject()){
            high = middle - 1;
        }
        else if(key > classes_T[middle].get_Subject()){
            low = middle + 1;
        }
        else return middle;
    }
    return -1;
}

int Read_classes::Binary_search_of_class_TP(Subject key){
    int low = 0;
    int high = classes_TP.size() - 1;
    while(low <= high){
        int middle = low + (high - low) / 2;
        if(key < classes_TP[middle].get_Subject()){
            high = middle - 1;
        }
        else if(key > classes_TP[middle].get_Subject()){
            low = middle + 1;
        }
        else return middle;
    }
    return -1;
}

int Read_classes::Binary_search_of_class_PL(Subject key){
    int low = 0;
    int high = classes_PL.size() - 1;
    while(low <= high){
        int middle = low + (high - low) / 2;
        if(key < classes_PL[middle].get_Subject()){
            high = middle - 1;
        }
        else if(key > classes_PL[middle].get_Subject()){
            low = middle + 1;
        }
        else return middle;
    }
    return -1;
}

