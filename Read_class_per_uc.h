//
// Created by Mansur on 11.10.2022.
//

/**
 * @file Read_class_per_uc.h
 */

#ifndef UNTITLED_READ_CLASS_PER_UC_H
#define UNTITLED_READ_CLASS_PER_UC_H
#include "Subject.h"

/**
 * @class that reads classes_per_uc csv file.
 */
class Read_class_per_uc {
public:
    /**
     * @brief Constructor.
     * @param input_name_file -> Name of the csv file.
     */
    explicit Read_class_per_uc(const string& input_name_file);

    /// @brief Gets subjects.
    vector<Subject> get_subjects() const;

    /// @brief Binary search of subject.
    int Binary_search(const Subject& key) const;
private:
    vector<Subject> subjects; /// Subjects
};


#endif //UNTITLED_READ_CLASS_PER_UC_H
