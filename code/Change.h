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
     * Complex O(1)
     * @param s -> line from the requests csv file.
     */
    explicit Change(const string& s);

    /// @brief Gets student requesting the change
    /// Complex O(1)
    Student getStudent() const;

    /// @brief Gets current class of the student.
    /// Complex O(1)
    Subject getCurSub() const;

    /// @brief Gets the class the student wants to change to.
    /// Complex O(1)
    Subject getNextSub() const;

private:
    Student student; /// @brief Student.
    Subject cur; /// @brief Current class.
    Subject next; /// @brief Class the student wants to move to.
};


#endif //UNTITLED_CHANGE_H
