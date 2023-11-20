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

public:
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
};

// Overloaded operators
std::ostream& operator<<(std::ostream& out, const Location& location);
std::istream& operator>>(std::istream& in, Location& location);

#endif // LOCATION_H
