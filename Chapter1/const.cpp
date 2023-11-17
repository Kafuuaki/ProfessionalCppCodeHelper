// the keyword const is short for “constant” and specifies that something remains unchanged. 
// The compiler enforces this requirement by marking any attempt to change it as an error.


#include <iostream>

using namespace std;

//  In C++, programmers are encouraged to avoid #define in favor of using const to define constants


// const as a Qualifier for a Type
// const with Pointers, read from right to left
// const to Protect Parameters, cast a non-const variable to a const variable
// const keyword is to mark class methods as const, mark all read-only methods as const. 

// void mysteryFunction(const std::string* someString) {
//     *someString = "Test"; // Will not compile }
// }


//  constant expressions, which are expressions evaluated at compile time.
// In some circumstances, constant expressions are a requirement.

// constexpr function is allowed to call other constexpr functions
// but is not allowed to call any non - constexpr functions

// constexpt does not guarantee that the function will be evaluated at compile time
// C++20 consteval keyword to turn a function into a so-called immediate function

constexpr int getArraySize() { return 32; }

// constexpr constuctor
class Rect {
public:
    constexpr Rect(size_t width, size_t height)
        : m_width{ width }, m_height{ height } {}
constexpr size_t getArea() const { return m_width * m_height; } private:
    size_t m_width{ 0 }, m_height{ 0 };
};


// consteval double inchToMm(double inch) { return inch * 25.4; }

// constexpr double const_inch{ 6.0 };
// constexpr double mm1{ inchToMm(const_inch) }; // at compile time


class AirlineTicket {
public:
    double calculatePriceInDollars() const;
    std::string getPassengerName() const;
    void setPassengerName(std::string name);
    int getNumberOfMiles() const;
    void setNumberOfMiles(int miles);
    bool hasEliteSuperRewardsStatus() const;
void setHasEliteSuperRewardsStatus(bool status); private:
    std::string m_passengerName{ "Unknown Passenger" }; int m_numberOfMiles{ 0 };
    bool m_hasEliteSuperRewardsStatus{ false };
};
// string AirlineTicket::getPassengerName() const
// {
//     return m_passengerName;
// }



int main() {

    const int versionNumberMajor{ 2 };
    const int versionNumberMinor{ 1 };
    const std::string productName{ "Super Hyper Net Modulator" };
    const double PI{ 3.141592653589793238462 };


    // avoiding ip array (the value being pointed to is const) been modified


    // ip is a pointer to int const
    // const int* ip;
    // ip = new int[10];
    // ip[4] = 5; // DOES NOT COMPILE!

    // which is semantically equivalent to:

    // ip is a pointer to const int
    // int const* ip;
    // ip = new int[10];
    // ip[4] = 5; // DOES NOT COMPILE!


    // ip is a const pointer to int
    int* const ip{ new int[10] };
    ip[4] = 5;



    // const int* const ip{ nullptr };
    // which is semantically equivalent to:
    // int const* const ip{ nullptr };

    int newArr[getArraySize()];
}