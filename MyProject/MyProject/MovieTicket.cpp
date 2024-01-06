#include "MovieTicket.h"

MovieTicket::MovieTicket(int eventId, const std::string& movieDetails)
    : Ticket(eventId), movieDetails(movieDetails) {}

void MovieTicket::sendByEmail(const std::string& email) const {
    std::cout << "Movie Ticket ID " << getID() << " for " << movieDetails << " sent to " << email << " by email.\n";
}

void MovieTicket::displayMovieDetails() const {
    std::cout << "Movie Details: " << movieDetails << std::endl;
}

