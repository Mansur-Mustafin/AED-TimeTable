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