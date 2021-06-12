#include "tests/spreadsheet_test.hpp"

#include "tests/select_contains_test.hpp"
#include "tests/select_and_test.hpp"
#include "tests/select_not_test.hpp"
#include "tests/select_or_test.hpp"

#include "gtest/gtest.h"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
