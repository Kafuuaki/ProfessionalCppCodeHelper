#include <iostream>

using namespace std;

class Demo {
public:
    int get() {
        return 10;
    }
};

namespace NS {
    int get() { return 20; }
}

void get() { std::cout << "get in global" << std::endl; }


int main() {
    Demo d;
    cout << d.get() << endl;
    cout << NS::get() << endl;
    // cout << ::get() << endl;
    // cout << get() << endl;

    ::get();

    // prints 5 // prints 20 // prints 10 // prints 10
}