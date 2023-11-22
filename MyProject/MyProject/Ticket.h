#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <vector>
#include <string>

class Ticket {
private:
    std::string ticketType;
    int uniqueID;
    static int nextID;

public:
    Ticket();
    Ticket(const std::string& type);

    // Accessor methods
    const std::string& getTicketType() const;
    int getUniqueID() const;

    // Other methods
    void displayTicketDetails() const;

    // Overloaded operators
    bool operator==(const Ticket& other) const;
    bool operator<(const Ticket& other) const;

    // Static method
    static int getNextID();
};

std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
std::istream& operator>>(std::istream& is, Ticket& ticket);

#endif // TICKET_H
