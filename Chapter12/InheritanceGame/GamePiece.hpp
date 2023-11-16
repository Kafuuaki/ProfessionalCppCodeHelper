#include <memory>

// To construct a GameBoard, we need to GamePiece and the board to store pieces

// base game piece class

// why we say this method can not store primitive types?

class GamePiece {
public:
  virtual ~GamePiece() = default;
  virtual std::unique_ptr<GamePiece> clone() const = 0;
};

// CRTP
// curiously recurring template pattern
// https://en.cppreference.com/w/cpp/language/crtp

// derived chess piece class
class ChessPiece : public GamePiece {
public:
  std::unique_ptr<GamePiece> clone() const override {
    return std::make_unique<ChessPiece>(*this);
  }

  // private:
  // chess piece implementation

  // call side, we must use the ChessPiece not
  bool side;
};
