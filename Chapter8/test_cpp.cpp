#include "SpreadShell.hpp"
#include <stdlib.h>

// miss use of default constructor

int main() {

  SpreadsheetCell myCell, anotherCell;
  myCell.setValue(6);
  anotherCell.setString("3.2");
  cout << "cell 1: " << myCell.getValue() << endl;
  cout << "cell 2: " << anotherCell.getValue() << endl;

  //   SpreadsheetCell *myCellp{new SpreadsheetCell{}};
  //   myCellp->setValue(3.7);
  //   cout << "cell 1: " << myCellp->getValue() << " " << myCellp->getString()
  //        << endl;
  //   delete myCellp;
  //   myCellp = nullptr;

  auto myCellp{make_unique<SpreadsheetCell>()};
  // Equivalent to:
  // unique_ptr<SpreadsheetCell> myCellp { new SpreadsheetCell { } };
  myCellp->setValue(3.7);
  cout << "cell 1: " << myCellp->getValue() << " " << myCellp->getString()
       << endl;

  SpreadsheetCell myCell2{5}, anotherCell2{4};

  auto smartCellp3{make_unique<SpreadsheetCell>(4)};
  // ... do something with the cell, no need to delete the smart pointer
  // Or with raw pointers, without smart pointers (not recommended)
  SpreadsheetCell *myCellp3{new SpreadsheetCell{5}};
  // Or
  //   SpreadsheetCell *myCellp{new SpreadsheetCell(5)};
  SpreadsheetCell *anotherCellp{nullptr};
  anotherCellp = new SpreadsheetCell{4};
  // ... do something with the cells
  delete myCellp3;
  myCellp3 = nullptr;
  delete anotherCellp;
  anotherCellp = nullptr;

  SpreadsheetCell aThirdCell{"test"}; // Uses string-arg ctor
  SpreadsheetCell aFourthCell{4.4};
  // Uses double-arg ctor
  auto aFifthCellp{make_unique<SpreadsheetCell>("5.5")}; // string-arg ctor
  cout << "aThirdCell: " << aThirdCell.getValue() << endl;
  cout << "aFourthCell: " << aFourthCell.getValue() << endl;
  cout << "aFifthCellp: " << aFifthCellp->getValue() << endl;

  //
  //   SpreadsheetCell myCell4(); // WRONG, but will compile.
  //   myCell4.setValue(6);
  //   // However, this line will not compile.
  //   cout << "cell 1: " << myCell4.getValue() << endl;

  SpreadsheetCell myCell4{4};
  SpreadsheetCell myCell5{myCell4}; // myCell2 has the same values as myCell1

  EvenSequence p1{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  p1.dump();
  try {
    EvenSequence p2{1.0, 2.0, 3.0};
  } catch (const invalid_argument &e) {
    cout << e.what() << endl;
  }

  //   SpreadsheetCell myCell{4};
  //   myCell = 5;
  //   myCell = "6"sv; // A string_view literal

  //   myCell = anotherCell = aThirdCell;
  //   equivalent to
  //   myCell.operator=(anotherCell.operator=(aThirdCell));

  return 0;
}