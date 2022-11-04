//
// Created by musta on 30.10.2022.
//

#include "ReadRequests.h"
#include <fstream>

ReadRequests::ReadRequests(const std::string &inputline) {
    ifstream in(inputline);
    string line;
    while (getline(in, line)){
        Change c (line);
        Changes.push(c);
    }
}

queue<Change> ReadRequests::getChanges() const {
    return Changes;
}