#include <charconv>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>

using namespace std;

class SpreadsheetCell {
public:
  // with default, the compiler will generate a default constructor for you
  SpreadsheetCell() = default;

  // https : // en.cppreference.com/w/cpp/language/converting_constructor
  // explicit constructor, prevent implicit conversion from the type in
  // parameter to the class type
  explicit SpreadsheetCell(double initialValue);
  explicit SpreadsheetCell(std::string_view initialValue);

  ~SpreadsheetCell() = default;

  // copy constructor take a const reference as parameters
  // SpreadsheetCell(const SpreadsheetCell &src);
  // NOTE If a class has data members that have a deleted copy constructor, then
  // the copy constructor for the class is automatically deleted as well.

  SpreadsheetCell &operator=(const SpreadsheetCell &rhs) noexcept;

  // with delete, the compiler will not generate a default constructor for you
  // SpreadsheetCell() = delete;

  void setValue(double value);
  double getValue() const;
  void setString(std::string_view value);
  std::string getString() const;

private:
  std::string doubleToString(double value) const;
  double stringToDouble(std::string_view value) const;
  double m_value{0};
};

// class SpreadShell {
// public:
//   void setValue(int value);
//   double getValue() const;

// private:
//   double value{0};
// };

struct Point {
  double x;
  double y;
};

class EvenSequence {
public:
  EvenSequence() = default;
  EvenSequence(initializer_list<double> args) {
    if (args.size() % 2 != 0) {
      throw invalid_argument{"initializer_list should "
                             "contain even number of elements."};
    }

    // m_sequence.reserve(args.size());
    // for (const auto &value : args) {
    //   m_sequence.push_back(value);
    // }

    m_sequence.assign(args);
  }

  void dump() const {
    for (const auto &value : m_sequence) {
      cout << value << ", ";
    }
    cout << endl;
  }

private:
  vector<double> m_sequence;
};

// this class allow implicit conversion from int to MyClass
// class MyClass {
// public:
//   MyClass(int) {}
//   MyClass(int, int) {}
// };

// void process(const MyClass &c) {}

// int main() {
//   process(1);
//   process({1});
//   process({1, 2});
// }

// class MyClass {
// public:
//   explicit MyClass(int) {}
//   explicit MyClass(int, int) {}
// };

// process(MyClass{ 1 }); process(MyClass{ 1, 2 });