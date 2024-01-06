#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include "FootballTicket.h"
#include "MovieTicket.h"
#include <iostream>
#include <vector>

int main() {
    // ...

    EventLocation eventLocation;
    EventLocation eventLocation2;

    // Load EventLocation data from file
    eventLocation.loadFromFile("event_location_data.bin");

    std::vector<Event*> events;
    std::vector<Ticket*> tickets;

    // Add events and generate tickets
    Event* footballMatch = new Event("Football Match", "02/01/2023", "3:00 PM");
    events.push_back(footballMatch);

    Event* movieEvent = new Event("Movie Premiere", "02/10/2023", "7:30 PM");
    events.push_back(movieEvent);

    Ticket* footballTicket = new FootballTicket(footballMatch->getName(), "Stadium: Stand 1, Seat: 10");
    tickets.push_back(footballTicket);

    Ticket* movieTicket = new MovieTicket(movieEvent->getName(), "Movie: Avengers: Endgame, Seat: VIP");
    tickets.push_back(movieTicket);

    // Save EventLocation data to file
    eventLocation.saveToFile("event_location_data.bin");

    // Process events and display ticket details
    for (Event* event : events) {
        event->processEvent();
    }

    for (Ticket* ticket : tickets) {
        ticket->sendByEmail("participant@example.com");
    }

    // Cleanup
    for (Event* event : events) {
        delete event;
    }

    for (Ticket* ticket : tickets) {
        delete ticket;
    }

    return 0;
}

