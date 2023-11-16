// helloworld.cpp
// import<iostream>;
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <iostream>

namespace world::subworld::subsubworld {
std::string str =
    "this is subsubworld with compat namespace, which is available in C++17";
}

namespace ssw = world::subworld::subsubworld;

int main(int argc, char *argv[]) {
  std::cout << "Hello, World!" << std::endl;

  // argc is the number of arguments, argv is the array of arguments
  // argv[0] is the name of the program, but it might be empty, dont rely on it
  std::cout << "argc: " << argc << std::endl;
  std::cout << argv[0] << std::endl;

  std::cout << world::subworld::subsubworld::str << std::endl;

  std::cout << "using namespace ssw(namespace alias)" << ssw::str << std::endl;

  // std::cout << std::format("There are {} ways I love you.", 219) <<
  // std::endl;

  std::cout << fmt::format("There are {} ways I love you.", 219) << std::endl;

  return 0;
}