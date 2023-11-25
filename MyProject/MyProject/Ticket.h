// Ticket.h
#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <vector>

class Ticket
{
    static int nextId;
    int id;
    std::string type;

    Ticket();
    Ticket(const std::string& type);

    // Accessor methods
    int getId() const;
    std::string getType() const;

    // Other generic methods
    void displayInfo() const;

    // Rule of 3
    Ticket(const Ticket& other);
    Ticket& operator=(const Ticket& other);
    ~Ticket();

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& out, const Ticket& ticket);
    friend std::istream& operator>>(std::istream& in, Ticket& ticket);
    bool operator==(const Ticket& other) const;

    void copyFrom(const Ticket& other);
    void clear();
};

#endif // TICKET_H
