//
// Created by Mansur on 12.10.2022.
//

/**
 * @file Read_classes.h
 */

#ifndef UNTITLED_READ_CLASSES_H
#define UNTITLED_READ_CLASSES_H
#include <vector>
#include <set>
#include "Class.h"

/**
 * @class that reads classes csv file.
 */
class Read_classes {
public:

    /**
     * @brief Constructor.
     * @param input_name_file -> Name of the csv file.
     */
    explicit Read_classes(const string& input_name_file);

    ///@brief Empty constructor.
    Read_classes();

    /// @brief Gets classes of type T
    set<Class> get_classes_T() const;

    /// @brief Gets classes of type TP
    set<Class> get_classes_TP() const;

    /// @brief Gets classes of type PL
    set<Class> get_classes_PL() const;

private:
    set<Class> classes_T; /// @brief Classes of type T
    set<Class> classes_TP; /// @brief Classes of type TP
    set<Class> classes_PL; /// @brief Classes of type PL
};


#endif //UNTITLED_READ_CLASSES_H
