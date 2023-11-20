// Location.cpp
#include "Location.h"

Location::Location() : name(""), maxSeats(0), numRows(0), numZones(0), seatsPerRow() {}

Location::Location(const std::string& name, int maxSeats, int numRows, int numZones, const std::vector<int>& seatsPerRow)
    : name(name), maxSeats(maxSeats), numRows(numRows), numZones(numZones), seatsPerRow(seatsPerRow) {}

std::string Location::getName() const {
    return name;
}

int Location::getMaxSeats() const {
    return maxSeats;
}

int Location::getNumRows() const {
    return numRows;
}

int Location::getNumZones() const {
    return numZones;
}

const std::vector<int>& Location::getSeatsPerRow() const {
    return seatsPerRow;
}

void Location::displayInfo() const {
    std::cout << "Location: " << name << "\nMax Seats: " << maxSeats << "\nNum Rows: " << numRows
              << "\nNum Zones: " << numZones << "\nSeats per Row: ";
    for (int seats : seatsPerRow) {
        std::cout << seats << " ";
    }
    std::cout << std::endl;
}

int Location::calculateTotalSeats() const {
    // Implement the calculation logic based on the characteristics of the location
    // For example, totalSeats = numRows * sum(seatsPerRow)
}

std::ostream& operator<<(std::ostream& out, const Location& location) {
    // Implement the output operator based on your desired format
}

std::istream& operator>>(std::istream& in, Location& location) {
    // Implement the input operator to read data into the Location object
}
