//
// Created by musta on 12.10.2022.
//

#include "Read_classes.h"
#include <fstream>
#include <algorithm>
Read_classes::Read_classes(const std::string &input_name_file) {
    string line;
    vector<Class> vectorT;
    vector<Class> vectorTP;
    vector<Class> vectorPL;
    bool f1 = true, f2 = true,f3 = true;

    ifstream inn(input_name_file);
    getline(inn, line);
    int Ti = 1, TPi = 1, PLi = 1;
    while(getline(inn, line)){
        Class s(line);

        if (s.get_type() == "T"){
            if(f1){
                vectorT.push_back(s);
                f1 = false;
                continue;
            }
            vectorT.push_back(s);
            int i;
            for(i = Ti ; i > 0 && s.get_Subject() < vectorT[i - 1].get_Subject(); i-- ){
                vectorT[i] = vectorT[i - 1];
            }
            vectorT[i] = s;
            Ti++;
        }

        if (s.get_type() == "TP"){
            if(f2){
                vectorTP.push_back(s);
                f2 = false;
                continue;
            }
            vectorTP.push_back(s);
            int i;
            for(i = TPi ; i > 0 && s.get_Subject() < vectorTP[i - 1].get_Subject(); i-- ){
                vectorTP[i] = vectorTP[i - 1];
            }
            vectorTP[i] = s;
            TPi++;
        }


        if (s.get_type() == "PL"){
            if(f3){
                vectorPL.push_back(s);
                f3 = false;
                continue;
            }
            vectorPL.push_back(s);
            int i;
            for(i = PLi ; i > 0 && s.get_Subject() < vectorPL[i - 1].get_Subject(); i-- ){
                vectorPL[i] = vectorPL[i - 1];
            }
            vectorPL[i] = s;
            PLi++;
        }
    }
    inn.close();
    classes_T = vectorT;
    classes_TP = vectorTP;
    classes_PL = vectorPL;

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

