#include <iostream>
#include <set>
#include <vector>
#include "Train.h"

using namespace std;

vector<Train> findTrains(const string& destination, const multiset<Train>& trains)  {
    vector<Train> trainsNow;
    for(const Train& train: trains) {
        if(train.getDestination() == destination) {
            trainsNow.push_back(train);
        }
    }
    return trainsNow;
}

int main() {
    multiset<Train> trains;
    auto *tr1 = new Train("Moscow", 123, 11, 0);
    auto *tr2 = new Train("Kaliningrad", 124, 12, 0);
    auto *tr3 = new Train("Vladivostok", 555, 13, 0);
    auto *tr4 = new Train("Murmansk", 888, 14, 0);
    auto *tr5 = new Train("Volgograd", 234, 15, 0);
    auto *tr6 = new Train("Samara", 893, 16, 0);
    trains.insert(*tr1);
    trains.insert(*tr2);
    trains.insert(*tr3);
    trains.insert(*tr4);
    trains.insert(*tr5);
    trains.insert(*tr6);
    int in = 1;
    while (in != 0) {
        cout << "Enter number menu: ";
        cin >> in;
        switch (in) {
            case 1: {
                for(const Train& train: trains) {
                    cout << train << endl;
                }
                break;
            }
            case 2: {
                string des;
                int number = 0;
                int hours = 0;
                int minutes = 0;
                cout << "Enter destination: ";
                cin >> des;
                cout << "Enter number train: ";
                cin >> number;
                cout << "Enter hours: ";
                cin >> hours;
                cout << "Enter minutes: ";
                cin >> minutes;
                trains.insert(*(new Train(des,number,hours,minutes)));
                break;
            }
            case 3: {
                cout << "Enter destination: ";
                string des;
                cin >> des;
                vector<Train> v = findTrains(des, trains);
                for(const Train& train: v) {
                    cout << train << endl;
                }
                break;
            }
        }
    }

    return  0;
}


