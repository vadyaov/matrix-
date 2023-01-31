#include <gtest/gtest.h>
#include "../inc/s21_matrix_oop.h"

TEST(DefaultConstructorTest, Default0) {
  S21Matrix DefaultMatrix;
  EXPECT_EQ(DefaultMatrix.getRows(), 1);
  ASSERT_EQ(DefaultMatrix.getCols(), 1);
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

TEST(ParamConstructorTest, NormalParams1) {
  S21Matrix m(2, 2);
  EXPECT_EQ(m.getRows(), 2);
  EXPECT_EQ(m.getCols(), 2);
  EXPECT_EQ(m.size(), 4);
  ASSERT_NE(&m(0, 0), nullptr);
}

TEST(ParamConstructorTest, NormalParams2) {
  S21Matrix m(3, 9);
  EXPECT_EQ(m.getRows(), 3);
  EXPECT_EQ(m.getCols(), 9);
  EXPECT_EQ(m.size(), 27);
  EXPECT_NE(&m(0, 0), nullptr);
}

TEST(ParamConstructorTest, NormalParams3) {
  S21Matrix m {3, 9};
  EXPECT_EQ(m.getRows(), 3);
  EXPECT_EQ(m.getCols(), 9);
  EXPECT_EQ(m.size(), 27);
  EXPECT_NE(&m(0, 0), nullptr);
}

TEST(ParamConstructorTest, Exception1) {
  try {
    S21Matrix bad {0, 3};
    /* FAIL() << "Expected std::invalid_argument"; */
  } catch (std::invalid_argument const& e) {
    EXPECT_EQ(e.what(), std::string("bad size in S21Matrix::S21Matrix(int, int)"));
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
