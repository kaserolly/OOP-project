#include "FootballTicket.h"

FootballTicket::FootballTicket(int eventId, const std::string& matchDetails)
    : Ticket(eventId), matchDetails(matchDetails) {}

void FootballTicket::sendByEmail(const std::string& email) const {
    std::cout << "Football Ticket ID " << getID() << " for " << matchDetails << " sent to " << email << " by email.\n";
}

void FootballTicket::displayFootballDetails() const {
    std::cout << "Football Match Details: " << matchDetails << std::endl;
}

