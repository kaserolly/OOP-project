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
    int totalSeats = numRows * static_cast<int>(seatsPerRow.size());
    return totalSeats;
}

Location::Location(const Location& other) {
    copyFrom(other);
}

Location& Location::operator=(const Location& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

Location::~Location() {
    clear();
}

std::ostream& operator<<(std::ostream& out, const Location& location) {
    out << "Location: " << location.getName() << "\nMax Seats: " << location.getMaxSeats()
        << "\nNum Rows: " << location.getNumRows() << "\nNum Zones: " << location.getNumZones()
        << "\nSeats per Row: ";
    for (int seats : location.getSeatsPerRow()) {
        out << seats << " ";
    }
    out << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Location& location) {
    std::cout << "Enter location name: ";
    in >> location.name;
    std::cout << "Enter max seats: ";
    in >> location.maxSeats;
    std::cout << "Enter number of rows: ";
    in >> location.numRows;
    std::cout << "Enter number of zones: ";
    in >> location.numZones;
    std::cout << "Enter seats per row (space-separated): ";
    location.seatsPerRow.clear();
    int seats;
    while (in >> seats) {
        location.seatsPerRow.push_back(seats);
    }
    return in;
}

int Location::operator[](int index) const {
    if (index >= 0 && index < static_cast<int>(seatsPerRow.size())) {
        return seatsPerRow[index];
    }
    return -1; // or throw an exception
}

Location Location::operator+(const Location& other) const {
    Location result(*this);
    // Perform addition operation on relevant fields
    return result;
}

Location Location::operator-(const Location& other) const {
    Location result(*this);
    // Perform subtraction operation on relevant fields
    return result;
}

Location Location::operator*(int multiplier) const {
    Location result(*this);
    // Perform multiplication operation on relevant fields
    return result;
}

Location Location::operator/(int divisor) const {
    if (divisor != 0) {
        Location result(*this);
        // Perform division operation on relevant fields
        return result;
    } else {
        // Handle division by zero
        return *this;
    }
}

Location& Location::operator++() {
    // Implement pre-increment operation on relevant fields
    return *this;
}

Location Location::operator++(int) {
    Location result(*this);
    // Implement post-increment operation on relevant fields
    return result;
}

Location& Location::operator--() {
    // Implement pre-decrement operation on relevant fields
    return *this;
}

Location Location::operator--(int) {
    Location result(*this);
    // Implement post-decrement operation on relevant fields
    return result;
}

Location::operator int() const {
    // Implement explicit cast to int based on relevant fields
    return 0;
}

bool Location::operator!() const {
    // Implement negation operator based on relevant fields
    return true;
}

bool Location::operator<(const Location& other) const {
    // Implement less than operator based on relevant fields
    return true;
}

bool Location::operator>(const Location& other) const {
    // Implement greater than operator based on relevant fields
    return true;
}

bool Location::operator<=(const Location& other) const {
    // Implement less than or equal to operator based on relevant fields
    return true;
}

bool Location::operator>=(const Location& other) const {
    // Implement greater than or equal to operator based on relevant fields
    return true;
}

bool Location::operator==(const Location& other) const {
    // Implement equality operator based on relevant fields
    return true;
}

void Location::copyFrom(const Location& other) {
    name = other.name;
    maxSeats = other.maxSeats;
    numRows = other.numRows;
    numZones = other.numZones;
    seatsPerRow = other.seatsPerRow;
}

void Location::clear() {
    // Perform cleanup for dynamically allocated resources if any
}
