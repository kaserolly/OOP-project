// Location.cpp
#include "Location.h"
#include <iostream>

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
    int totalSeats = numRows;
    for (int seats : seatsPerRow) {
        totalSeats += seats;
    }
    return totalSeats;
}

std::ostream& operator<<(std::ostream& out, const Location& location) {
    out << location.getName() << " " << location.getMaxSeats() << " " << location.getNumRows() << " "
        << location.getNumZones() << " ";
    for (int seats : location.getSeatsPerRow()) {
        out << seats << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Location& location) {
    in >> location.name >> location.maxSeats >> location.numRows >> location.numZones;
    location.seatsPerRow.clear();
    int seats;
    while (in >> seats) {
        location.seatsPerRow.push_back(seats);
    }
    return in;
}

