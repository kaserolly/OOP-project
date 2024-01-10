#pragma once
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include <vector>

class TicketManager {
    std::vector<Ticket> issuedTickets;
    Location location;
    Event event;

public:
    TicketManager(const Location& location, const Event& event);

    void generateTickets(int numTickets, const std::string& category);
    void displayTickets() const;
    bool validateTicket(const std::string& ticketId) const;

     void saveTicketsToFile(const std::string& filename) const;
    void loadTicketsFromFile(const std::string& filename);

    void displayMenu() const;
    void processUserChoice(int choice);
};
