#include "templateGrid.hpp"
#include <iostream>
#include <memory>

struct SpreadsheetCell {
  SpreadsheetCell() = default;
  SpreadsheetCell(double initialValue) : m_value{initialValue} {}

  double m_value;
};

int main() {

  Grid<int> myIntGrid; // Declares a grid that stores ints,
  // using default arguments for the constructor.
  Grid<double> myDoubleGrid{11, 11}; // Declares an 11x11 Grid of doubles.
  myIntGrid.at(0, 0) = 10;
  // we use value or method for the optional
  int x{myIntGrid.at(0, 0).value_or(0)};
  std::cout << x << std::endl;
  Grid<int> grid2{myIntGrid}; // Copy constructor
  Grid<int> anotherIntGrid;
  anotherIntGrid = grid2;
  // Assignment operator

  Grid<SpreadsheetCell> mySpreadsheet;
  SpreadsheetCell myCell{1.234};
  mySpreadsheet.at(3, 4) = myCell;

  //   std::cout << mySpreadsheet.at(3, 4)->m_value << std::endl;

  // mySpreadsheet.display();

  std::unique_ptr<Grid<int>> myGridOnFreeStore{
      std::make_unique<Grid<int>>(2, 2)}; // 2x2 Grid on free store.
  myGridOnFreeStore->at(0, 0) = 10;
  int x_2{myGridOnFreeStore->at(0, 0).value_or(0)};

  return 0;
}
