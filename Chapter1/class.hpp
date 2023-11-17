#include <string>

// inclass initialization

class AirlineTicket
{
public:
    AirlineTicket(); ~AirlineTicket() = default;
    double calculatePriceInDollars();
    std::string getPassengerName();
    void setPassengerName(std::string name);
    int getNumberOfMiles();
    void setNumberOfMiles(int miles);
    bool hasEliteSuperRewardsStatus();
void setHasEliteSuperRewardsStatus(bool status); private:
    std::string m_passengerName = { "Unknown Passenger" };
    int m_numberOfMiles{ 0 };
    bool m_hasEliteSuperRewardsStatus{ false };
};