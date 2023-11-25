// Event.h
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

class Event
{
    std::string name;
    std::string date;
    std::string time;

    Event();
    Event(const std::string& name, const std::string& date, const std::string& time);

    //Accessor methods
    std::string getName() const;
    std::string getDate() const;
    std::string getTime() const;

    //Other generic methods
    void displayInfo() const;

    //Rule of 3
    Event(const Event& other);
    Event& operator=(const Event& other);
    ~Event();

    //Overload operators
    friend std::ostream& operator<<(std::ostream& out, const Event& event);
    friend std::istream& operator>>(std::istream& in, Event& event);
    explicit operator bool() const;
    bool operator<(const Event& other) const;
    bool operator>(const Event& other) const;
    bool operator<=(const Event& other) const;
    bool operator>=(const Event& other) const;
    bool operator==(const Event& other) const;

    void copyFrom(const Event& other);
    void clear();
};

#endif // EVENT_H
