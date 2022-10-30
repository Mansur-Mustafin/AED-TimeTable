//
// Created by musta on 30.10.2022.
//

#ifndef UNTITLED_CHANGE_H
#define UNTITLED_CHANGE_H


#include "Student.h"

class Change {
public:
    explicit Change(const string& s);
    Student getSudent() const;
    Subject getCurSub() const;
    Subject getNextSub() const;
private:
    Student student;
    Subject cur;
    Subject next;
};


#endif //UNTITLED_CHANGE_H
