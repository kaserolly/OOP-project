#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

class Event {
public:
    virtual void readCharacteristics() = 0;
    virtual void displayDetails() const = 0;
    virtual ~Event() {}
};

class Ticket {
private:
    int id;

public:
    Ticket() : id(generateUniqueId()) {}

    int getId() const {
        return id;
    }

    virtual void displayDetails() const {
        std::cout << "Ticket ID: " << id << std::endl;
    }

private:
    static int generateUniqueId() {
        return rand() % 10000 + 1;
    }
};

class FootballEvent : public Event {
private:
    int maxSeats;
    // Add other characteristics specific to football events

public:
    void readCharacteristics() override {
        std::cout << "Enter maximum number of seats: ";
        std::cin >> maxSeats;
        // Add input reading for other characteristics
    }

    void displayDetails() const override {
        std::cout << "Football Event Details\n";
        std::cout << "Max Seats: " << maxSeats << std::endl;
        // Display other details
    }
};

class MovieEvent : public Event {
private:
    // Add characteristics specific to movie events

public:
    void readCharacteristics() override {
        // Implement input reading for movie events
    }

    void displayDetails() const override {
        // Implement displaying details for movie events
    }
};

class TheaterEvent : public Event {
private:
    // Add characteristics specific to theater events

public:
    void readCharacteristics() override {
        // Implement input reading for theater events
    }

    void displayDetails() const override {
        // Implement displaying details for theater events
    }
};

class VIPTicket : public Ticket {
public:
    void displayDetails() const override {
        std::cout << "VIP ";
        Ticket::displayDetails();
    }
};

class TicketManager {
private:
    std::vector<Ticket*> tickets;

public:
    void generateTicket(const Event& event, const std::string& category) {
        Ticket* newTicket = nullptr;

        if (category == "VIP") {
            newTicket = new VIPTicket();
        }
        else {
            newTicket = new Ticket();
        }

        tickets.push_back(newTicket);
        std::cout << "Ticket generated successfully!\n";
    }

    bool validateTicket(int ticketId) const {
        for (const Ticket* ticket : tickets) {
            if (ticket->getId() == ticketId) {
                std::cout << "Ticket is valid!\n";
                return true;
            }
        }

        std::cout << "Invalid ticket ID!\n";
        return false;
    }

    void saveTicketsToFile(const std::string& filename) const {
        std::ofstream outFile(filename, std::ios::binary | std::ios::out);

        if (!outFile.is_open()) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        for (const Ticket* ticket : tickets) {
            outFile.write(reinterpret_cast<const char*>(ticket), sizeof(Ticket));
        }

        outFile.close();
        std::cout << "Tickets saved to file.\n";
    }

    void loadTicketsFromFile(const std::string& filename) {
        std::ifstream inFile(filename, std::ios::binary | std::ios::in);

        if (!inFile.is_open()) {
            std::cerr << "Error opening file for reading.\n";
            return;
        }

        Ticket* loadedTicket = new Ticket();

        while (inFile.read(reinterpret_cast<char*>(loadedTicket), sizeof(Ticket))) {
            tickets.push_back(new Ticket(*loadedTicket));
        }

        delete loadedTicket;
        inFile.close();
        std::cout << "Tickets loaded from file.\n";
    }

    ~TicketManager() {
        for (Ticket* ticket : tickets) {
            delete ticket;
        }
    }
};

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned>(time(0)));

    TicketManager ticketManager;

    if (argc > 1) {
        ticketManager.loadTicketsFromFile(argv[1]);
        std::cout << "Tickets loaded from file.\n";
    }

    int choice;
    do {
        std::cout << "1. Football Event\n";
        std::cout << "2. Movie Event\n";
        std::cout << "3. Theater Event\n";
        std::cout << "4. Generate Ticket\n";
        std::cout << "5. Validate Ticket\n";
        std::cout << "6. Save Tickets to File\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            FootballEvent footballEvent;
            footballEvent.readCharacteristics();
            footballEvent.displayDetails();
            break;
        }
        case 2: {
            MovieEvent movieEvent;
            movieEvent.readCharacteristics();
            movieEvent.displayDetails();
            break;
        }
        case 3: {
            TheaterEvent theaterEvent;
            theaterEvent.readCharacteristics();
            theaterEvent.displayDetails();
            break;
        }
        case 4: {
            std::string category;
            std::cout << "Enter ticket category (VIP or Regular): ";
            std::cin >> category;
            ticketManager.generateTicket(VIPTicket, category);
            break;
        }
        case 5: {
            int ticketId;
            std::cout << "Enter ticket ID for validation: ";
            std::cin >> ticketId;
            ticketManager.validateTicket(ticketId);
            break;
        }
        case 6: {
            std::string filename;
            std::cout << "Enter filename to save tickets: ";
            std::cin >> filename;
            ticketManager.saveTicketsToFile(filename);
            break;
        }
        case 7:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
