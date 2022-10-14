//
// Created by musta on 08.10.2022.
//

#include "Hour.h"

Hour::Hour(float x) {
    int m = x * 60;
    this->hora = m / 60;
    this->minutes = m % 60;
}

Hour Hour::operator+(const Hour &right) const {
    int h = this->hora + right.hora;
    int m = this->minutes + right.minutes;
    if (m >= 60) {
        m %= 60;
        h += 1;
    }
    return Hour{h,m};
}

bool Hour::operator<(const Hour& right) const{
    int h1 = hora * 60 + minutes;
    int h2 = right.hora * 60 + right.minutes;
    return h1 < h2;
}

int Hour::get_hora() const {
    return hora;
}

int Hour::get_minutes() const{
    return minutes;
}

ostream& operator<< (ostream& out, const Hour& s1){
    out << s1.hora << ':' << setfill('0') << setw(2) <<  s1.minutes;
    return out;
}



