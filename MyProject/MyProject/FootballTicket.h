#pragma once

#include "Ticket.h"

class FootballTicket : public Ticket {
private:
    std::string matchDetails;

public:
    FootballTicket(int eventId, const std::string& matchDetails);

    // Implementation of pure virtual method
    void sendByEmail(const std::string& email) const override;

    // Additional methods
    void displayFootballDetails() const;
};

