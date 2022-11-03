//
// Created by musta on 08.10.2022.
//

/**
 * @file Hour.h
 */

#ifndef UNTITLED_HOUR_H
#define UNTITLED_HOUR_H
#include <iostream>
#include <iomanip>
using namespace std;

/**
 * @class Encapsulate time in a simple class
 */
class Hour {
public:
    explicit Hour(float x);
    Hour(){hora = 1; minutes = 1;};
    Hour(int x , int y){hora = x; minutes = y;};

    /// @brief Overload of <em>operator+ </em>.
    Hour operator+(const Hour& right) const;

    /// @brief Overload of <em>operator- </em>.
    Hour operator-(const Hour& right) const;

    /// @brief Overload of <em>operator< </em>.
    bool operator<(const Hour& right) const;

    /// @brief Overload of <em>operator> </em>.
    bool operator>(const Hour& right) const;

    /// @brief Overload of <em>operator>= </em>.
    bool operator>=(const Hour& right) const;

    /// @brief Overload of <em>operator<= </em>.
    bool operator<=(const Hour& right) const;

    /// @brief Overload of <em>operator== </em>.
    bool operator==(const Hour& right) const;

    /// @brief Gets hour.
    int get_hora() const;

    /// @brief Gets minute.
    int get_minutes() const;


    friend ostream& operator<< (ostream& out, const Hour& s1);

private:
    int hora; /// @brief Hora.
    int minutes;/// @brief Minuto.
};


#endif //UNTITLED_HOUR_H
