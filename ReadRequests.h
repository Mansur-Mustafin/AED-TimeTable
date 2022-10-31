//
// Created by musta on 30.10.2022.
//

#ifndef UNTITLED_READREQUESTS_H
#define UNTITLED_READREQUESTS_H

#include <queue>
#include "Change.h"

class ReadRequests {
public:
    explicit ReadRequests(const string& inputline);
    queue<Change> getChanges() const;
private:
    queue<Change> Changes;
};


#endif //UNTITLED_READREQUESTS_H
