#ifndef LAB2_TRAIN_H
#define LAB2_TRAIN_H

#include <string>
#include <ostream>

using namespace std;

class Train {
private:
    string destination;
    int number;
    int hours;
    int minute;
public:
    Train(string  destination, int number, int hours, int minute);

    const string &getDestination() const;

    void setDestination(const string &destination);

    void setNumber(int number);

    void setHours(int hours);

    void setMinute(int minute);

    bool operator==(const Train &rhs) const;

    friend ostream &operator<<(ostream &os, const Train &train);

    bool operator<(const Train &rhs) const;

    bool operator>(const Train &rhs) const;

    bool operator<=(const Train &rhs) const;

    bool operator>=(const Train &rhs) const;

    bool operator!=(const Train &rhs) const;

    int getNumber() const;

};


#endif //LAB2_TRAIN_H
