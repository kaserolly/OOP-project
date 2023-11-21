#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <ctime>

class Event {
private:
    std::string name;
    std::string date;
    std::string time;
    static int eventCount;  // Static field to count the number of events
    int eventId;            // Unique ID for each event

public:
    Event();
    Event(const std::string& name, const std::string& date, const std::string& time);

    // Accessor methods
    std::string getName() const;
    std::string getDate() const;
    std::string getTime() const;
    int getEventId() const;

    // Other generic methods
    static int getEventCount(); // Static method to get the total number of events
    void displayEventInfo() const;
};

// Overloaded operators
std::ostream& operator<<(std::ostream& os, const Event& event);
std::istream& operator>>(std::istream& is, Event& event);

#endif // EVENT_H
