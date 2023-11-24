#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>

int main() {
    // Example usage

    // Create a location
    std::vector<std::vector<int>> seatsPerRow = {{10, 15, 20}, {12, 18, 24}};
    Location footballStadium(1000, 2, 2, seatsPerRow);

    // Display location information
    footballStadium.displayLocationInfo();

    // Create an event
    Event footballMatch("Football Match", "2023-01-01", "15:00");

    // Display event information
    footballMatch.displayEventInfo();

    // Generate a ticket
    Ticket footballTicket("FootballMatch");
    std::cout << "Generated Ticket ID: " << footballTicket.getTicketId() << "\n";

    return 0;
}
