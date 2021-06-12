#include "tests/div_test.hpp"
#include "tests/mult_test.hpp"
#include "tests/pow_test.hpp"
#include "tests/add_test.hpp"
#include "tests/sub_test.hpp"



#include "gtest/gtest.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
