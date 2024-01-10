#include "Location.h"
#include "Event.h"
#include "TicketManager.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <data_filename>\n";
        return 1;
    }
    std::vector<int> seatsperrow = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Location footballStadium("nume", 1000, 10, 10, seatsperrow);
    Event footballMatch("Football Match", "2023-01-01", "15:00");

    TicketManager ticketManager(footballStadium, footballMatch);

    ticketManager.loadTicketsFromFile(argv[1]);

    int choice;
    do {
        ticketManager.displayMenu();
        std::cin >> choice;
        ticketManager.processUserChoice(choice);
    } while (choice != 6);

    ticketManager.saveTicketsToFile(argv[1]);

    return 0;
}
