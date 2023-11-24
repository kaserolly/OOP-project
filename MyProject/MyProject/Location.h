// Location.h
#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <vector>

class Location {
private:
    std::string name;
    int maxSeats;
    int numRows;
    int numZones;
    std::vector<int> seatsPerRow;

    Location();
    Location(const std::string& name, int maxSeats, int numRows, int numZones, const std::vector<int>& seatsPerRow);

    // Accessor methods
    std::string getName() const;
    int getMaxSeats() const;
    int getNumRows() const;
    int getNumZones() const;
    const std::vector<int>& getSeatsPerRow() const;

    // Other generic methods
    void displayInfo() const;
    int calculateTotalSeats() const;

    // Rule of 3
    Location(const Location& other);
    Location& operator=(const Location& other);
    ~Location();

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& out, const Location& location);
    friend std::istream& operator>>(std::istream& in, Location& location);
    int operator[](int index) const;
    Location operator+(const Location& other) const;
    Location operator-(const Location& other) const;
    Location operator*(int multiplier) const;
    Location operator/(int divisor) const;
    Location& operator++();
    Location operator++(int);
    Location& operator--();
    Location operator--(int);
    explicit operator int() const;
    bool operator!() const;
    bool operator<(const Location& other) const;
    bool operator>(const Location& other) const;
    bool operator<=(const Location& other) const;
    bool operator>=(const Location& other) const;
    bool operator==(const Location& other) const;

private:
    void copyFrom(const Location& other);
    void clear();
};

#endif // LOCATION_H
