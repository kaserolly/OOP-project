// Ticket.cpp
#include "Ticket.h"

int Ticket::nextId = 1;

Ticket::Ticket() : id(nextId++), type("") {}

Ticket::Ticket(const std::string& type) : id(nextId++), type(type) {}

int Ticket::getId() const {
    return id;
}

std::string Ticket::getType() const {
    return type;
}

void Ticket::displayInfo() const {
    std::cout << "Ticket ID: " << id << "\nType: " << type << "\n";
}

Ticket::Ticket(const Ticket& other) {
    copyFrom(other);
}

Ticket& Ticket::operator=(const Ticket& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

Ticket::~Ticket() {
    clear();
}

std::ostream& operator<<(std::ostream& out, const Ticket& ticket) {
    out << "Ticket ID: " << ticket.getId() << "\nType: " << ticket.getType() << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Ticket& ticket) {
    std::cout << "Enter ticket type: ";
    in >> ticket.type;
    return in;
}

bool Ticket::operator==(const Ticket& other) const {
    return id == other.id && type == other.type;
}

void Ticket::copyFrom(const Ticket& other) {
    id = other.id;
    type = other.type;
}

void Ticket::clear() {
    // Perform cleanup for dynamically allocated resources if any
}
