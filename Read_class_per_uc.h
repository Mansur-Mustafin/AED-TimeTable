//
// Created by musta on 11.10.2022.
//

#ifndef UNTITLED_READ_CLASS_PER_UC_H
#define UNTITLED_READ_CLASS_PER_UC_H
#include "Subject.h"

class Read_class_per_uc {
public:
    explicit Read_class_per_uc(const string& input_name_file); // constr
    vector<Subject> get_subjects() const;
private:
    vector<Subject> subjects;
};


#endif //UNTITLED_READ_CLASS_PER_UC_H
