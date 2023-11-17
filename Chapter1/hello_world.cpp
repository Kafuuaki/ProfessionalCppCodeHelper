// helloworld.cpp
// import<iostream>;
// #include <fmt/core.h>
// #include <fmt/format.h>
// #include <fmt/ranges.h>
#include <iostream>
#include <limits>
#include <array>
#include <utility>
#include <optional>
#include <initializer_list>

using namespace std;

// problem today
// enum class, old style, c++ 20
// fmt library format

// this file covers the following topics:
// 1. namespace, namespace alias
// 2. main function args, either empty or argc, argv
// 3. uniform initialization, zero initialization
// 4. limit library
// 5. castings
// 6. enum class
// 7. swithch branch
// 8. logical operator, only gives true or false
// 9. function and overloading function
// 10. c style array, std::size
// 11. std::array, std::array::size
// 12. std::pair, which is in utility
// 13. std::optional, value, value_or
// 14. Structured bindings, declare multiple variables that are initialized with elements from, for example, an array, struct, or pair.
// 15. do while loop, c++20 for range loop with initializer


namespace world::subworld::subsubworld {
  std::string str =
    "this is subsubworld with compat namespace, which is available in C++17";
}

namespace ssw = world::subworld::subsubworld;

int addNumbers(int number1, int number2) {
  std::cout << "Entering function {}" << __func__ << std::endl;
  return number1 + number2;
}

double addNumbers(double number1, double number2) {
  std::cout << "Entering function {}" << __func__ << std::endl;
  return number1 + number2;
}

int func(int i1, [[maybe_unused]] int i2) {
  return 42;
}

std::optional<int> getData(bool b) {
  if (b) {
    return 42;
  }
  else {
    return {};
  }
}

// initilizer_list is a template class
int makeSum(std::initializer_list<int> list) {
  int sum{ 0 };
  for (auto& e : list) {
    sum += e;
  }
  return sum;
}



int main(int argc, char* argv[]) {
  std::cout << "Hello, World!" << std::endl;

  // argc is the number of arguments, argv is the array of arguments
  // argv[0] is the name of the program, but it might be empty, dont rely on it
  std::cout << "argc: " << argc << std::endl;
  std::cout << argv[0] << std::endl;

  std::cout << world::subworld::subsubworld::str << std::endl;

  std::cout << "using namespace ssw(namespace alias)" << ssw::str << std::endl;

  int uniform_initialization{ 1 };
  std::cout << "uniform_initialization: " << uniform_initialization << std::endl;

  int zero_initilizer{};
  std::cout << "zero initilizer " << zero_initilizer << std::endl;

  // std::cout << std::format("There are {} ways I love you.", 219) <<
  // std::endl;

  // std::cout << fmt::format("There are {} ways I love you.", 219) << std::endl;

  std::cout << "max int: " << std::numeric_limits<int>::max() << std::endl;
  std::cout << "min int: " << std::numeric_limits<int>::min() << std::endl;
  std::cout << "lowest int: " << std::numeric_limits<int>::lowest() << std::endl;



  float myFloat{ 3.14f };
  int i1{ (int)myFloat };
  // this method is seldom used
  int i2{ int(myFloat) };
  int i3{ static_cast<int>(myFloat) };
  // method 1 // method 2 // method 3

  enum class PieceType { King, Queen, Rook, Pawn };

  PieceType piece = PieceType::King;


  enum class PieceType_2 {
    King = 1, Queen, Rook = 10, Pawn
  };

  // If you do not assign a value to an enumeration member,
  //  the compiler automatically assigns it a value that is the previous enumeration member incremented by 1.


// Even though enumeration values are internally represented by integer values,
//  they are not automati- cally converted to integer
  // std::cout << PieceType_2::Queen << std::endl;


  // c++20 using enum declaration
  // using enum PieceType; PieceType piece{ King };
  // using PieceType::King; PieceType piece { King }; piece = PieceType::Queen;

  switch (piece)
  {
  case PieceType::King:
    /* code */
    std::cout << "we take piece type king" << std::endl;
    break;

  case PieceType::Queen:
    std::cout << "we take piece type queen" << std::endl;
    break;

  default:
    break;
  }

  std::cout << ((1 > 2) ? "yes" : "no");

  addNumbers(1, 2);

  std::cout << func(1, 2) << std::endl;


  int arr[3]{ 2 };
  std::cout << std::size(arr) << std::endl;
  std::cout << sizeof(arr) / sizeof(arr[0]) << std::endl;

  std::array<int, 3> arr1{ 8, 9, 10 };

  std::cout << arr1.size() << std::endl;

  std::cout << "optional: " << getData(true).value() << std::endl;

  std::optional<int> opt = getData(false);

  std::cout << "optional: " << opt.value_or(0) << std::endl;

  std::array values{ 1, 2, 3 };
  auto [x, y, z] = values;

  std::cout << x << y << z << std::endl;

  struct Point { double m_x, m_y, m_z; };
  Point point;
  point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
  auto [x_1, y_1, z_1] { point };

  std::cout << x_1 << y_1 << z_1 << std::endl;

  pair myPair{ "hello", 5 };
  auto [theString, theInt] { myPair };

  int i{ 100 }; do {
    std::cout << "This is silly." << std::endl;
    ++i;
  } while (i < 5);

  for (std::array arr{ 1, 2, 3, 4 }; int i : arr) { std::cout << i << std::endl; }

  std::cout << "Hello, World!" << std::endl;

  std::cout << makeSum({ 1, 2, 3, 4, 5 }) << std::endl;




  return 0;
}