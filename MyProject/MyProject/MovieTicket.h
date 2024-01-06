// MovieTicket.h
#pragma once

#include "Ticket.h"

class MovieTicket : public Ticket {
private:
    std::string movieDetails;

public:
    MovieTicket(int eventId, const std::string& movieDetails);

    // Implementation of pure virtual method
    void sendByEmail(const std::string& email) const override;

    // Additional methods
    void displayMovieDetails() const;
};

