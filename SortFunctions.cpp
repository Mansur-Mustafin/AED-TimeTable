#include "Student.h"

static bool sortStudentsByNameAscending(const Student& s1, const Student& s2 ){
    return s1.get_name() < s2.get_name();
}

static bool sortStudentsByNameDescending(const Student& s1, const Student& s2 ){
    return s1.get_name() > s2.get_name();
}

static bool sortStudentsbyStCodeAscending(const Student& s1, const Student& s2){
    return s1.get_StudentCode() < s2.get_StudentCode();
}

static bool sortStudentsbyStCodeDescending(const Student& s1, const Student& s2){
    return s1.get_StudentCode() > s2.get_StudentCode();
}

static bool sortUCsbyStudentNumberAscending(const pair<string,int>& s1, const pair<string,int>& s2){
    return s1.second < s2.second;
}

static bool sortUCsbyStudentNumberDescending(const pair<string,int>& s1, const pair<string,int>& s2){
    return s1.second > s2.second;
}

static bool sortClassesByStudentNumberAscending(const Subject& s1, const Subject& s2){
    return s1.get_number_of_student() < s2.get_number_of_student();
}

static bool sortClassesByStudentNumberDescending(const Subject& s1, const Subject& s2){
    return s1.get_number_of_student() > s2.get_number_of_student();
}