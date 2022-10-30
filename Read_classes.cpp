//
// Created by Mansur on 12.10.2022.
//

#include "Read_classes.h"
#include <fstream>
#include <algorithm>
Read_classes::Read_classes(const std::string &input_name_file) {
    string line;
    ifstream inn(input_name_file);
    getline(inn, line);
    int Ti = 1, TPi = 1, PLi = 1;
    while(getline(inn, line)){
        Class s(line);
        if (s.get_type() == "T"){
            classes_T.insert(s);
        }
        if (s.get_type() == "TP"){
            classes_TP.insert(s);
        }
        if (s.get_type() == "PL"){
            classes_PL.insert(s);
        }
    }
    inn.close();
}

Read_classes::Read_classes() {
    classes_T = {};
    classes_TP = {};
    classes_PL = {};
}

set<Class> Read_classes::get_classes_T(){
    return classes_T;
}

set<Class> Read_classes::get_classes_TP() {
    return classes_TP;
}

set<Class> Read_classes::get_classes_PL() {
    return classes_PL;
}

/*

vector <Class> Read_classes::Binary_search_of_class_T(Subject key){
    vector <Class> v;
    int low = 0;
    int high = classes_T.size() - 1;
    int middle;
    while(low <= high){

        middle = low + (high - low) / 2;
        if(key < classes_T[middle].get_Subject()){
            high = middle - 1;
        }
        else if(key > classes_T[middle].get_Subject()){
            low = middle + 1;
        }
        else break;
    }

    v.push_back(classes_T[middle]);

    if(middle > 1){
        if(classes_T[middle - 1].get_Subject() == key) v.push_back(classes_T[middle - 1]);
    }
    if(middle < classes_T.size() - 1){
        if(classes_T[middle + 1].get_Subject() == key) v.push_back(classes_T[middle + 1]);
    }

    return v;
}


Class Read_classes::Binary_search_of_class_TP(Subject key){
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
        else return classes_TP[middle];
    }
    Class s ("1LEIC02,L.EIC002,Monday,10.5,2,TP");
    return s;
}

Class Read_classes::Binary_search_of_class_PL(Subject key){
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
        else return classes_PL[middle];
    }
    Class s ("1LEIC02,L.EIC002,Monday,10.5,2,TP");
    return s;
}

*/