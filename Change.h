//
// Created by musta on 30.10.2022.
//

/**
 * @file Change.h
 */

#ifndef UNTITLED_CHANGE_H
#define UNTITLED_CHANGE_H


#include "Student.h"

/**
 * @class that contains information about requests
 */
class Change {
public:
    /**
     * @brief Constructor.
     * @param s -> line from the requests csv file.
     */
    explicit Change(const string& s);

    /// @brief Gets student requesting the change
    Student getSudent() const;

    /// @brief Gets current class of the student.
    Subject getCurSub() const;

    /// @brief Gets the class the student wants to change to.
    Subject getNextSub() const;

private:
    Student student; /// @brief Student.
    Subject cur; /// @brief Current class.
    Subject next; /// @brief Class the student wants to move to.
};


#endif //UNTITLED_CHANGE_H
