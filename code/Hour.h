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
    /**
     * @brief Constructor.
     * Complex O(1)
     * @param x -> hours in float, (10.5 => 10:30)
     */
    explicit Hour(float x);
    /**
     * @brief Constructor default.
     * Complex O(1)
     */
    Hour(){hora = 1; minutes = 1;};
    /**
     * @brief Constructor.
     * Complex O(1)
     * @param x -> hours
     * @param y -> minutes
     */
    Hour(int x , int y){hora = x; minutes = y;};

    /// @brief Overload of <em>operator+ </em>.
    /// Complex O(1)
    Hour operator+(const Hour& right) const;

    /// @brief Overload of <em>operator- </em>.
    /// Complex O(1)
    Hour operator-(const Hour& right) const;

    /// @brief Overload of <em>operator< </em>.
    /// Complex O(1)
    bool operator<(const Hour& right) const;

    /// @brief Overload of <em>operator> </em>.
    /// Complex O(1)
    bool operator>(const Hour& right) const;

    /// @brief Overload of <em>operator>= </em>.
    /// Complex O(1)
    bool operator>=(const Hour& right) const;

    /// @brief Overload of <em>operator<= </em>.
    /// Complex O(1)
    bool operator<=(const Hour& right) const;

    /// @brief Overload of <em>operator== </em>.
    /// Complex O(1)
    bool operator==(const Hour& right) const;

    /// @brief Gets hour.
    /// Complex O(1)
    int get_hora() const;

    /// @brief Gets minute.
    /// Complex O(1)
    int get_minutes() const;

    /// @brief Overload of <em>operator<< </em>.
    /// Complex O(1)
    friend ostream& operator<< (ostream& out, const Hour& s1);

private:
    int hora; /// @brief Hora.
    int minutes;/// @brief Minuto.
};


#endif //UNTITLED_HOUR_H
