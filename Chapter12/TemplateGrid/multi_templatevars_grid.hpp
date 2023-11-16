#include <cstddef>
#include <iostream>
#include <optional>

// non-type template parameters
template <typename T, size_t WIDTH = 10, size_t HEIGHT = 10> class Grid {
public:
  Grid() = default;
  virtual ~Grid() = default;
  // Explicitly default a copy constructor and assignment operator.
  Grid(const Grid &src) = default;
  Grid &operator=(const Grid &rhs) = default;
  template <typename E, size_t WIDTH2, size_t HEIGHT2>
  Grid(const Grid<E, WIDTH2, HEIGHT2> &src);
  template <typename E, size_t WIDTH2, size_t HEIGHT2>
  Grid &operator=(const Grid<E, WIDTH2, HEIGHT2> &rhs);
  void swap(Grid &other) noexcept;
  std::optional<T> &at(size_t x, size_t y);
  const std::optional<T> &at(size_t x, size_t y) const;
  size_t getHeight() const { return HEIGHT; }
  size_t getWidth() const { return WIDTH; }

private:
  void verifyCoordinate(size_t x, size_t y) const;
  std::optional<T> m_cells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2> &src) {
  for (size_t i{0}; i < WIDTH; i++) {
    for (size_t j{0}; j < HEIGHT; j++) {
      if (i < WIDTH2 && j < HEIGHT2) {
        m_cells[i][j] = src.at(i, j);
      } else {
        m_cells[i][j].reset();
      }
    }
  }
}

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::swap(Grid &other) noexcept {
  std::swap(m_cells, other.m_cells);
}
template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT> &
Grid<T, WIDTH, HEIGHT>::operator=(const Grid<E, WIDTH2, HEIGHT2> &rhs) {
  // Copy-and-swap idiom
  Grid<T, WIDTH, HEIGHT> temp{rhs}; // Do all the work in a temp instance.
  swap(temp); // Commit the work with only non-throwing operations.
  return *this;
}

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const {
  if (x >= WIDTH) {
    throw std::out_of_range{std::format("{} must be less than {}.", x, WIDTH)};
  }
  if (y >= HEIGHT) {
    throw std::out_of_range{std::format("{} must be less than {}.", y, HEIGHT)};
  }
}

// Grid<int, 10, 10> myGrid;
// Grid<int, 10, 10> anotherGrid;
// myGrid.at(2, 3) = 42;
// anotherGrid = myGrid;
// cout << anotherGrid.at(2, 3).value_or(0);

// you must use const to specify the size of the array,
//     since it is non - type template parameter

//         const size_t height{10};
// Grid<int, 10, height> testGrid; // Compiles and works\

// or constexpr constexpr size_t getHeight() { return 10; }
// ... Grid<double, 2, getHeight()> myDoubleGrid

//     export module grid : string;
// import : main;

// why it also influence int template <> class Grid<const char *> {
// public:
//   explicit Grid(size_t width = DefaultWidth, size_t height =
//   DefaultHeight); virtual ~Grid() = default;
//   // Explicitly default a copy constructor and assignment operator.
//   Grid(const Grid &src) = default;
//   Grid &operator=(const Grid &rhs) = default;
//   // Explicitly default a move constructor and assignment operator.
//   Grid(Grid &&src) = default;
//   Grid &operator=(Grid &&rhs) = default;
//   std::optional<std::string> &at(size_t x, size_t y);
//   const std::optional<std::string> &at(size_t x, size_t y) const;
//   size_t getHeight() const { return m_height; }
//   size_t getWidth() const { return m_width; }
//   static const size_t DefaultWidth{10};
//   static const size_t DefaultHeight{10};

// private:
//   void verifyCoordinate(size_t x, size_t y) const;
//   std::vector<std::vector<std::optional<std::string>>> m_cells;
//   size_t m_width{0}, m_height{0};
// };

// Grid<const char *>::Grid(size_t width, size_t height)
//     : m_width{width}, m_height{height} {
//   m_cells.resize(m_width);
//   for (auto &column : m_cells) {
//     column.resize(m_height);
//   }
// }
// void Grid<const char *>::verifyCoordinate(size_t x, size_t y) const {
//   if (x >= m_width) {
//     throw std::out_of_range{
//         std::format("{} must be less than {}.", x, m_width)};
//   }
//   if (y >= m_height) {
//     throw std::out_of_range{
//         std::format("{} must be less than {}.", y, m_height)};
//   }
// }
// const std::optional<std::string> &Grid<const char *>::at(size_t x,
//                                                          size_t y) const
//                                                          {
//   verifyCoordinate(x, y);
//   return m_cells[x][y];
// }
// std::optional<std::string> &Grid<const char *>::at(size_t x, size_t y) {
//   return const_cast<std::optional<std::string> &>(
//       std::as_const(*this).at(x, y));
// }