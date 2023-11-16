#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

#include <fmt/core.h>
#include <iostream>

#include "GamePiece.hpp"

class TicTacToePiece : public GamePiece {
public:
  std::unique_ptr<GamePiece> clone() const override {
    // Call the copy constructor to copy this instance
    return std::make_unique<TicTacToePiece>(*this);
  }
};

// Gameboard object
class GameBoard {
public:
  // rule of five
  explicit GameBoard(size_t width = DefaultWidth,
                     size_t height = DefaultHeight);
  virtual ~GameBoard() = default;
  GameBoard &operator=(const GameBoard &rhs);

  GameBoard(const GameBoard &src);

  // move constructor and move assignment operator
  GameBoard(GameBoard &&src) = default;
  GameBoard &operator=(GameBoard &&src) = default;

  // at() provides bounds checking
  // override the function to return a reference to a GamePiece
  std::unique_ptr<GamePiece> &at(size_t x, size_t y);

  // const version of at() for const GameBoard objects
  // returns a const reference to a const GamePiece
  const std::unique_ptr<GamePiece> &at(size_t x, size_t y) const;
  size_t getHeight() const { return m_height; }
  size_t getWidth() const { return m_width; }

  void display() const;

  static const size_t DefaultWidth{10};
  static const size_t DefaultHeight{10};

  void swap(GameBoard &other) noexcept;

private:
  void verifyCoordinate(size_t x, size_t y) const;

  // we store game pieces as pointers to GamePiece objects
  std::vector<std::vector<std::unique_ptr<GamePiece>>> m_cells;
  size_t m_width{0}, m_height{0};
};

class ChessBoard : public GameBoard {
public:
  explicit ChessBoard(size_t width = DefaultWidth,
                      size_t height = DefaultHeight);
  virtual ~ChessBoard() = default;
  ChessBoard &operator=(const ChessBoard &rhs);

  std::unique_ptr<ChessPiece> &at(size_t x, size_t y);

  ChessBoard(const ChessBoard &src);

  // move constructor and move assignment operator

  // T&& auto&& universal reference, perfect forwarding
  // ChessBoard&& rvalue reference
  ChessBoard(ChessBoard &&src) = default;
  ChessBoard &operator=(ChessBoard &&src) = default;

  void display() const;

  static const size_t DefaultWidth{8};
  static const size_t DefaultHeight{8};

private:
  std::vector<std::vector<std::unique_ptr<ChessPiece>>> chess_cells;
  size_t chess_width{0}, chess_height{0};
};