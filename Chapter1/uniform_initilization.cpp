// A benefit of using uniform initialization is that it prevents narrowing.
// can be used in the constructor initializer to initialize arrays that are members of a class.

// desiganated initializers

struct CircleStruct {
    int x, y;
    double radius;
};

struct Employee {
    char firstInitial; char lastInitial; int employeeNumber; int salary;
};

class CircleClass {
public:CircleClass(int x, int y, double radius)
    : m_x{ x }, m_y{ y }, m_radius{ radius } {}
private:
    int m_x, m_y;double m_radius;
};

int main() {
    CircleStruct myCircle1 = { 10, 10, 2.5 };
    CircleClass myCircle2(10, 10, 2.5);
    Employee anEmployee{ 'J', 'D', 42, 80'000 };

    int e{ }; // Uniform initialization, e will be 0

    // int* myArray = new int[4] { 0, 1, 2, 3 };
    // Uniform initialization can be used to initialize dynamically allocated arrays
    int* myArray = new int[] { 0, 1, 2, 3 };

    Employee newEmployee{
        .firstInitial = 'J',
        .lastInitial = 'D',
        .employeeNumber = 42,
        .salary = 80'000
    };
}