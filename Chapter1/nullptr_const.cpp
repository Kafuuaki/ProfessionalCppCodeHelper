#include <iostream>
using namespace std;

// https://en.cppreference.com/w/cpp/types/NULL
// The macro NULL is an implementation-defined null pointer constant, an integer literal with value zero, or a prvalue of type std::nullptr_t
// nullptr is a keyword that represents a real null pointer. It is a prvalue of type std::nullptr_t. There exist implicit conversions from nullptr to null pointer value of any pointer type and any pointer to member type. Similar conversions exist for any null pointer constant, which includes values of type std::nullptr_t and the macro NULL.

void func(int i) { cout << "func(int)" << endl; }

int main() {


    // NULL might be 0 here, so func(int) is called
    func(NULL);

    // nullptr generates a compiler error
    // func(nullptr);

    return 0;
}