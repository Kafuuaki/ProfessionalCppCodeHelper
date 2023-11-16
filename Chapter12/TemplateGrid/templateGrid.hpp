
// we cannot directly compile hpp
#include <iostream>
#include <optional>
#include <stdexcept>
#include <stdio.h>
#include <vector>

// why do we need default, delete, noexcept
// allowing the compiler to generate the default constructor, copy constructor,

// why do we need const on reference, const reference cannot change the value
// can use use forward declration like this?

// template <typename T> class Grid;
// using IntGrid = Grid<int>;

// when do we use noexcept

// the reason of using getWidth

// when would we use module

// the reason of using explicit here:
// we are using a implicit conversion here
// class Point {
// public:
//   int x, y;
//   Point(int x = 0, int y = 0) : x(x), y(y) {}
// };

// int main() { Point p = 1; }

// what should we do if the private property can not be inherited
// we can expose some interface to access the private property, like at, using
// reference allow us to change the value

#define DEAFULT_WIDTH 10
#define DEAFULT_HEIGHT 10

template <typename T> class Grid {
public:
  // explicit ban implicit conversion, only used in constructor, conversion,
  // deduction stop copy initialization Grid g = {1,1}; Grid g{1,1} ok list
  // initialization calling constructor

  explicit Grid(size_t width = DefaultWidth,
    size_t height = DefaultHeight) noexcept;
  virtual ~Grid() = default;
  // Explicitly default a copy constructor and assignment operator.
  // Grid(const Grid &src) = default;

  // std::initializer_list

  // copy constructor
  template <typename E> Grid(const Grid<E>& src);
  // Grid(const Grid &src) = default;

  // noexcept ensure that the function will not throw any exception
  void swap(Grid& other) noexcept;

  // compiler explicitly express it as
  // Grid<T>(const Grid& src) = default;

  // Grid &operator=(const Grid &rhs) = default;

  // copy assignment operator
  template <typename E> Grid& operator=(const Grid<E>& rhs);
  // Explicitly default a move constructor and assignment operator.
  Grid(Grid&& src) = default;
  // Grid &operator=(Grid &&rhs) = default;
  std::optional<T>& at(size_t x, size_t y);

  // const reference cannot change the value
  const std::optional<T>& at(size_t x, size_t y) const;
  size_t getHeight() const { return m_height; }
  size_t getWidth() const { return m_width; }

  void display() const;

  static const size_t DefaultWidth{ DEAFULT_WIDTH };
  static const size_t DefaultHeight{ DEAFULT_HEIGHT };

private:
  void verifyCoordinate(size_t x, size_t y) const;
  std::vector<std::vector<std::optional<T>>> m_cells;
  size_t m_width{ 0 }, m_height{ 0 };
};

template <typename T>
Grid<T>::Grid(size_t width, size_t height) noexcept : m_width{ width }, m_height{ height } {
  m_cells.resize(m_width);
  for (auto& column : m_cells) {
    column.resize(m_height);
  }
}

// we must use getWidth, getHeight, since the type may not the same

// the extra template parameter allow us to use other type of grid to construct
template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E>& src)
  : m_width{ src.getWidth() }, m_height{ src.getHeight() } {
  m_cells.resize(m_width);
  for (auto& column : m_cells) {
    column.resize(m_height);
  }
  for (size_t i{ 0 }; i < m_width; ++i) {
    for (size_t j{ 0 }; j < m_height; ++j) {
      if (src.at(i, j).has_value()) {
        m_cells[i][j] = src.at(i, j).value();
      }
    }
  }
}

template <typename T>
template <typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs) {
  if (this == &rhs) {
    return *this;
  }
  m_width = rhs.getWidth();
  m_height = rhs.getHeight();
  m_cells.resize(m_width);
  for (auto& column : m_cells) {
    column.resize(m_height);
  }
  for (size_t i{ 0 }; i < m_width; ++i) {
    for (size_t j{ 0 }; j < m_height; ++j) {
      if (rhs.at(i, j).has_value()) {
        m_cells[i][j] = rhs.at(i, j).value();
      }
    }
  }
  return *this;
}

template <typename T> void Grid<T>::swap(Grid& other) noexcept {
  using std::swap;
  swap(m_width, other.m_width);
  swap(m_height, other.m_height);
  swap(m_cells, other.m_cells);
}

template <typename T> void Grid<T>::verifyCoordinate(size_t x, size_t y) const {
  if (x >= m_width) {
    // throw std::out_of_range{
    //     std::format("{} must be less than {}.", x, m_width)};

    throw std::out_of_range("a");
  }
  if (y >= m_height) {
    // throw std::out_of_range{
    //     std::format("{} must be less than {}.", y, m_height)};
    throw std::out_of_range("a");
  }
}
template <typename T>
const std::optional<T>& Grid<T>::at(size_t x, size_t y) const {
  verifyCoordinate(x, y);
  return m_cells[x][y];
}
template <typename T> std::optional<T>& Grid<T>::at(size_t x, size_t y) {
  return const_cast<std::optional<T> &>(std::as_const(*this).at(x, y));
}

// template <typename T, size_t WIDTH, size_t HEIGHT>
// template <typename E, size_t WIDTH2, size_t HEIGHT2>
// Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2> &src) {
//   for (size_t i{0}; i < WIDTH; i++) {
//     for (size_t j{0}; j < HEIGHT; j++) {
//       if (i < WIDTH2 && j < HEIGHT2) {
//         m_cells[i][j] = src.at(i, j);
//       } else {
//         m_cells[i][j].reset();
//       }
//     }
//   }
// }

// dislay
template <typename T> void Grid<T>::display() const {
  // for (size_t y{0}; y < m_height; ++y) {
  //   for (size_t x{0}; x < m_width; ++x) {
  //   if (m_cells[x][y].has_value()) {
  //     std::cout << m_cells[x][y].value();
  //   } else {
  //     std::cout << ".";
  //   }
  //     std::cout << m_cells[x][y].value_or(".");
  //   }
  //   std::cout << std::endl;
  // }

  // since the value in grid may not be printable, we omit this part
  // or can we use optioal to handle this problem?
}

// using IntGrid = Grid<int>;
