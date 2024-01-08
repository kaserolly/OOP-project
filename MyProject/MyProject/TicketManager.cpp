#include "TicketManager.h"
#include <iostream>
#include <fstream>

TicketManager::TicketManager(const Location& location, const Event& event)
    : location(location), event(event) {}

void TicketManager::generateTickets(int numTickets, const std::string& category) {
    for (int i = 0; i < numTickets; ++i) {
        Ticket newTicket(event.getName());
        newTicket.generateTicketId();
        // Add category information to the ticket ID
        newTicket.generateTicketId();
        newTicket.generateTicketId(category);
        issuedTickets.push_back(newTicket);
    }
}

void TicketManager::displayTickets() const {
    std::cout << "Issued Tickets:\n";
    for (const auto& ticket : issuedTickets) {
        std::cout << "Ticket ID: " << ticket.getTicketId() << "\n";
    }
}

bool TicketManager::validateTicket(const std::string& ticketId) const {
    for (const auto& ticket : issuedTickets) {
        if (ticket.getTicketId() == ticketId) {
            std::cout << "Ticket is valid.\n";
            return true;
        }
    }
    std::cout << "Invalid ticket.\n";
    return false;
}

void TicketManager::saveTicketsToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary | std::ios::out);
    if (file.is_open()) {
        for (const auto& ticket : issuedTickets) {
            file.write(reinterpret_cast<const char*>(&ticket), sizeof(Ticket));
        }
        file.close();
        std::cout << "Tickets saved to file.\n";
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void TicketManager::loadTicketsFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::in);
    if (file.is_open()) {
        Ticket loadedTicket;
        while (file.read(reinterpret_cast<char*>(&loadedTicket), sizeof(Ticket))) {
            issuedTickets.push_back(loadedTicket);
        }
        file.close();
        std::cout << "Tickets loaded from file.\n";
    } else {
        std::cerr << "Unable to open file for reading.\n";
    }
}

void TicketManager::displayMenu() const {
    std::cout << "1. Generate Tickets\n";
    std::cout << "2. Display Issued Tickets\n";
    std::cout << "3. Validate Ticket\n";
    std::cout << "4. Save Tickets to File\n";
    std::cout << "5. Load Tickets from File\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void TicketManager::processUserChoice(int choice) {
    switch (choice) {
        case 1: {
            int numTickets;
            std::string category;
            std::cout << "Enter the number of tickets to generate: ";
            std::cin >> numTickets;
            std::cout << "Enter the category of tickets (e.g., VIP, Normal): ";
            std::cin >> category;
            generateTickets(numTickets, category);
            break;
        }
        case 2:
            displayTickets();
            break;
        case 3: {
            std::string ticketId;
            std::cout << "Enter the ticket ID to validate: ";
            std::cin >> ticketId;
            validateTicket(ticketId);
            break;
        }
        case 4: {
            std::string filename;
            std::cout << "Enter the filename to save tickets: ";
            std::cin >> filename;
            saveTicketsToFile(filename);
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Enter the filename to load tickets: ";
            std::cin >> filename;
            loadTicketsFromFile(filename);
            break;
        }
        case 6:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}
