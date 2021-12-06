#include "Train.h"

Train::Train(const string &destination, int number, int hours, int minute) : destination(destination), number(number),
                                                                             hours(hours), minute(minute) {}

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
    if(train.minute < 10) {
        os << "destination: " << train.destination << " number train: " << train.number << " " << train.hours
           << ":0" << train.minute;
    }

    return os;
}
