#include "templateGrid.hpp"
#include <gtest/gtest.h>

class GridTest : public ::testing::Test {
protected:
    Grid<const char*> grid;
};

TEST_F(GridTest, DefaultConstructor) {
    EXPECT_EQ(grid.getWidth(), Grid<const char*>::DefaultWidth);
    EXPECT_EQ(grid.getHeight(), Grid<const char*>::DefaultHeight);
}

TEST_F(GridTest, ParameterizedConstructor) {
    Grid<const char*> customGrid(5, 5);
    EXPECT_EQ(customGrid.getWidth(), 5);
    EXPECT_EQ(customGrid.getHeight(), 5);
}

TEST_F(GridTest, ElementAccess) {
    grid.at(3, 3) = "Hello";
    EXPECT_EQ(grid.at(3, 3), std::optional<std::string>("Hello"));
}
