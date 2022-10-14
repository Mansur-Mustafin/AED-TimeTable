//
// Created by musta on 08.10.2022.
//

#ifndef UNTITLED_HOUR_H
#define UNTITLED_HOUR_H
#include <iostream>
#include <iomanip>
using namespace std;

class Hour {
public:
    // constructor
    explicit Hour(float x);
    Hour(){hora = 1; minutes = 1;};
    Hour(int x , int y){hora = x; minutes = y;};
    // sum
    Hour operator+(const Hour& right) const;
    // compare
    bool operator<(const Hour& right) const;
    // getter
    int get_hora() const;
    int get_minutes() const;
    friend ostream& operator<< (ostream& out, const Hour& s1);
private:
    int hora;
    int minutes;
};


#endif //UNTITLED_HOUR_H
