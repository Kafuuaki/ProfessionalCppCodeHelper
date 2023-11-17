#include "Game.h"

GameBoard::GameBoard(size_t width, size_t height) : m_width{ width }, m_height{ height } {

    m_cells.resize(m_width);
    for (auto& column : m_cells) {
        column.resize(m_height);
    }
}

GameBoard::GameBoard(const GameBoard& src) : GameBoard{ src.m_width, src.m_height } {
    // The ctor-initializer of this constructor delegates first to the
    // non-copy constructor to allocate the proper amount of memory.
    // The next step is to copy the data.
    for (size_t i{ 0 }; i < m_width; i++) {
        for (size_t j{ 0 }; j < m_height; j++) {
            if (src.m_cells[i][j])
                m_cells[i][j] = src.m_cells[i][j]->clone();
        }
    }
}

// GameBoard::~GameBoard() noexcept = default;

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= m_width || x < 0) {
        // throw std::out_of_range { fmt::format("{} must be less than {}.", x, m_width) };
        throw std::out_of_range{ "x is out of range" };
    }
    if (y >= m_height || y < 0) {
        // throw std::out_of_range { fmt::format("{} must be less than {}.", y, m_height) };
        throw std::out_of_range{ "y is out of range" };
    }
}
void GameBoard::swap(GameBoard& other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}
void swap(GameBoard& first, GameBoard& second) noexcept
{
    first.swap(second);
}
GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
    // Copy-and-swap idiom
    GameBoard temp{ rhs }; // Do all the work in a temporary instance.
    swap(temp);
    // Commit the work with only non-throwing operations.
    return *this;
}
const std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) const {
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) {
    return const_cast<std::unique_ptr<GamePiece>&>(std::as_const(*this).at(x, y));
}

ChessBoard::ChessBoard(size_t width, size_t height) :chess_width{ width }, chess_height{ height } {

    chess_cells.resize(chess_width); // Resize the outer vector

    for (auto& column : chess_cells) {
        column.resize(chess_height); // Resize each inner vector
        for (auto& cell : column) {
            cell = std::make_unique<ChessPiece>(); // Initialize each cell with a new ChessPiece
        }
    }
}

std::unique_ptr<ChessPiece>& ChessBoard::at(size_t x, size_t y) {
    return chess_cells[x][y];
}

void ChessBoard::display() const {

    std::cout << "ChessBoard::display()" << std::endl;
    std::cout << "chess_width: " << chess_width << std::endl;
    std::cout << "size of chess_cells: " << chess_cells.size() << std::endl;


    for (size_t i{ 0 }; i < chess_width; i++) {
        for (size_t j{ 0 }; j < chess_height; j++) {
            if (chess_cells[i][j]->side) {
                std::cout << "X";
            }
            else {
                std::cout << "O";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // ChessBoard chessBoard { 8, 8 };

    ChessBoard chessBoard(8, 8);

    auto pawn{ std::make_unique<ChessPiece>() };
    chessBoard.at(0, 0) = std::move(pawn);

    // auto pawn { std::make_unique<ChessPiece>() };
    // chessBoard.at(0, 0) = std::move(pawn);
    // chessBoard.at(0, 1) = std::make_unique<ChessPiece>();
    // chessBoard.at(0, 1) = nullptr;

    chessBoard.at(0, 0)->side = 1;
    chessBoard.at(1, 1)->side = 1;
    chessBoard.at(2, 2)->side = 1;
    chessBoard.at(3, 3)->side = 1;
    chessBoard.at(4, 4)->side = 1;

    chessBoard.display();
}