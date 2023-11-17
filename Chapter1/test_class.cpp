#include "class.hpp"
#include <iostream>

using namespace std;

int main() {
    AirlineTicket myTicket;
    myTicket.setPassengerName("Sherman T. Socketwrench"); myTicket.setNumberOfMiles(700);
    double cost{ myTicket.calculatePriceInDollars() };
    cout << cost << endl;

    return 0;
}

