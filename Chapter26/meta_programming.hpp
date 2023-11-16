#include <concepts>
#include <vector>

using namespace std;

template <typename Container>
concept ContainerType = requires(Container c) {
    c.resize(1);
    typename Container::value_type;
};


template <typename T, ContainerType Container>
class Grid {
public:
    explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight); virtual ~Grid() = default;
    // Explicitly default a copy constructor and assignment operator.
    Grid(const Grid& src) = default;
    Grid& operator=(const Grid& rhs) = default;
    // Explicitly default a move constructor and assignment operator.
    Grid(Grid&& src) = default;
    Grid& operator=(Grid&& rhs) = default;
    typename Container::value_type& at(size_t x, size_t y);
    const typename Container::value_type& at(size_t x, size_t y) const;
    size_t getHeight() const { return m_height; } size_t getWidth() const { return m_width; }
    static const size_t DefaultWidth{ 10 }; static const size_t DefaultHeight{ 10 };
private:
    void verifyCoordinate(size_t x, size_t y) const;
    std::vector<Container> m_cells;
    size_t m_width{ 0 }, m_height{ 0 };
};