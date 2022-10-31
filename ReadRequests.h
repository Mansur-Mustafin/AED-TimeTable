//
// Created by musta on 30.10.2022.
//

/**
 * @file ReadRequests.h
 */
#ifndef UNTITLED_READREQUESTS_H
#define UNTITLED_READREQUESTS_H

#include <queue>
#include "Change.h"

/**
 * @class that reads the requests file.
 */
class ReadRequests {
public:
    /**
     * @brief Constructor.
     * @param inputline -> Line from the csv file.
     */
    explicit ReadRequests(const string& inputline);

    /// @brief Gets queue with requests in the file.
    queue<Change> getChanges() const;
private:
    queue<Change> Changes; /// @brief Queue with requests.
};


#endif //UNTITLED_READREQUESTS_H
