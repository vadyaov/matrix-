#include <gtest/gtest.h>
#include "../matrix_oop.h"

TEST(DefaultConstructorTest, Default0) {
  S21Matrix DefaultMatrix;
  EXPECT_EQ(DefaultMatrix.getRows(), 1);
  ASSERT_EQ(DefaultMatrix.getCols(), 0);
  ASSERT_NE(&DefaultMatrix(0, 0), nullptr);
}

TEST(DefaultConstructorTest, Default1) {
  S21Matrix DefaultMatrix{};
  EXPECT_EQ(DefaultMatrix.getRows(), 1);
  EXPECT_EQ(DefaultMatrix.getCols(), 1);
  ASSERT_NE(&DefaultMatrix(0, 0), nullptr);
}

TEST(DefaultConstructorTest, Default2) {
  S21Matrix DefaultMatrix = {};
  EXPECT_EQ(DefaultMatrix.getRows(), 1);
  ASSERT_EQ(DefaultMatrix.getCols(), 1);
  ASSERT_NE(&DefaultMatrix(0, 0), nullptr);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
