cmake_minimum_required(VERSION 3.14)
project(S21Matrix)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Werror -Wextra -pedantic -g)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

ADD_LIBRARY(s21_matrix_oop STATIC
  ./lib/constructors.cc
  ./lib/operations.cc
  ./lib/operators.cc
  ./lib/other.cc
  ./lib/helpers.cc)

SET_TARGET_PROPERTIES(s21_matrix_oop PROPERTIES PREFIX "")

add_executable(
  S21MAtrix.test
  ./tests/test.cc
  ./tests/test_helpers.cc
)
target_link_libraries(
  S21MAtrix.test
  s21_matrix_oop
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(S21MAtrix.test)
