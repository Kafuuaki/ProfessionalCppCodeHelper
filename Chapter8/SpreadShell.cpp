#include "SpreadShell.hpp"

// void SpreadsheetCell::setValue(double value) { m_value = value; }
// double SpreadsheetCell::getValue() const { return m_value; }

// SpreadsheetCell::SpreadsheetCell() = default;

SpreadsheetCell::SpreadsheetCell(double initialValue) : m_value(initialValue) {}

void SpreadsheetCell::setValue(double value) { m_value = value; }
double SpreadsheetCell::getValue() const { return m_value; }
void SpreadsheetCell::setString(string_view value) {
  m_value = stringToDouble(value);
}

// delegating constructor, call the other constructor
SpreadsheetCell::SpreadsheetCell(string_view initialValue)
    : SpreadsheetCell(stringToDouble(initialValue)) {}

string SpreadsheetCell::getString() const { return doubleToString(m_value); }
string SpreadsheetCell::doubleToString(double value) const {
  return to_string(value);
}

SpreadsheetCell &
SpreadsheetCell::operator=(const SpreadsheetCell &rhs) noexcept {
  if (this == &rhs) {
    return *this;
  }

  m_value = rhs.m_value;
  return *this;
}

double SpreadsheetCell::stringToDouble(string_view value) const {
  //   double number{0};

  //   //   this function is deleted?
  //   //   from_chars(value.data(), value.data() + value.size(), number);

  //   //   number = strtod(value.data(), nullptr);

  //   return number;

  char *end;
  double number = std::strtod(value.data(), &end);

  //   // Optionally, check if the whole string was converted
  if (end != value.data() + value.size()) {
    // Handle error: the whole string was not converted
    // For example, set number to a default value or throw an exception
  }

  return number;
}

// why gcc comiler can't find this function?
// double SpreadsheetCell::stringToDouble(std::string_view value) const {
//   double number = 0;
//   auto [ptr, ec] =
//     //   std::from_chars(value.data(), value.data() + value.size(),
//     number);

//   if (ec == std::errc::invalid_argument ||
//       ec == std::errc::result_out_of_range) {
//     // Handle error: invalid input or out of range
//     // For example, set number to a default value or throw an exception
//   }

//   return number;
// }
