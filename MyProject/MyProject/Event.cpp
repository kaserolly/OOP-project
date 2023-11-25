// Event.cpp
#include "Event.h"

Event::Event() : name(""), date(""), time("") {}

Event::Event(const std::string& name, const std::string& date, const std::string& time)
    : name(name), date(date), time(time) {}

std::string Event::getName() const
{
    return name;
}

std::string Event::getDate() const
{
    return date;
}

std::string Event::getTime() const
{
    return time;
}

void Event::displayInfo() const
{
    std::cout << "Event: " << name << "\nDate: " << date << "\nTime: " << time << "\n";
}

Event::Event(const Event& other)
{
    copyFrom(other);
}

Event& Event::operator=(const Event& other)
{
    if (this != &other)
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

Event::~Event()
{
    clear();
}

std::ostream& operator<<(std::ostream& out, const Event& event)
{
    out << "Event: " << event.getName() << "\nDate: " << event.getDate() << "\nTime: " << event.getTime() << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Event& event)
{
    std::cout << "Enter event name: ";
    in >> event.name;
    std::cout << "Enter event date: ";
    in >> event.date;
    std::cout << "Enter event time: ";
    in >> event.time;
    return in;
}

Event::operator bool() const
{
    // Implement explicit cast to bool based on relevant fields
    return !name.empty() && !date.empty() && !time.empty();
}

bool Event::operator<(const Event& other) const
{
    // Implement less than operator based on relevant fields
    if (date != other.date)
    {
        return date < other.date;
    }
    else if (time != other.time)
    {
        return time < other.time;
    }
    else
    {
        return name < other.name;
    }
}

bool Event::operator>(const Event& other) const
{
    // Implement greater than operator based on relevant fields
    if (date != other.date)
    {
        return date > other.date;
    }
    else if (time != other.time)
    {
        return time > other.time;
    }
    else
    {
        return name > other.name;
    }
}

bool Event::operator<=(const Event& other) const
{
    // Implement less than or equal to operator based on relevant fields
    return !(*this > other);
}

bool Event::operator>=(const Event& other) const
{
    // Implement greater than or equal to operator based on relevant fields
    return !(*this < other);
}

bool Event::operator==(const Event& other) const
{
    // Implement equality operator based on relevant fields
    return name == other.name && date == other.date && time == other.time;
}

void Event::copyFrom(const Event& other)
{
    name = other.name;
    date = other.date;
    time = other.time;
}
