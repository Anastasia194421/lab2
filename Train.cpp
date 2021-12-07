#include <iostream>
#include "Train.h"

Train::Train(string  destination, int number, int hours, int minute) : destination(std::move(destination)),
                                                                      number(number),
                                                                      hours(hours), minute(minute) {
    std::cout << "Constructor Train" << std::endl;
}

Train::Train(const Train& train) {
    cout << "Constructor copy" << endl;
    this->hours = train.hours;
    this->minute = train.minute;
    this->number = train.number;
    this->destination = train.destination;
}

const string &Train::getDestination() const {
    return destination;
}

int Train::getNumber() const {
    return number;
}

void Train::setDestination(const string &destination) {
    Train::destination = destination;
}

void Train::setNumber(int number) {
    Train::number = number;
}

void Train::setHours(int hours) {
    Train::hours = hours;
}

void Train::setMinute(int minute) {
    Train::minute = minute;
}

bool Train::operator==(const Train &rhs) const {
    return destination == rhs.destination &&
           number == rhs.number &&
           hours == rhs.hours &&
           minute == rhs.minute;
}

bool Train::operator!=(const Train &rhs) const {
    return !(rhs == *this);
}

bool Train::operator<(const Train &rhs) const {
    if (hours < rhs.hours)
        return true;
    if (rhs.hours < hours)
        return false;
    return minute < rhs.minute;
}

bool Train::operator>(const Train &rhs) const {
    return rhs < *this;
}

bool Train::operator<=(const Train &rhs) const {
    return !(rhs < *this);
}

bool Train::operator>=(const Train &rhs) const {
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const Train &train) {
    os << train.destination << " #" << train.number << " ";
    if (train.hours < 10) {
        os << "0";
    }
    os << train.hours << ":";
    if (train.minute < 10) {
            os << "0";
    }
    os << train.minute;
    return os;
}

Train::Train() {
    number = 0;
    hours = 0;
    minute = 0;
    cout << "Constructor Train" << endl;
}
