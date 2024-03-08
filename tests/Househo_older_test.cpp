#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <slo_oe/Househo_older.hpp>


TEST(Househo_older, TEST0_ONE) {

auto m = DenseCSR::Mat_es({{9, 3, 2},
                           {4, 1, 3},
                           {1, 7, 4}});

auto res = Ho_ouseholder::so_olve(std::vector<double>({6, 3, 4}), m);

ASSERT_NEAR(res[0], 0.493, 0.001);
ASSERT_NEAR(res[1], 0.377, 0.001);
ASSERT_NEAR(res[2], 0.217, 0.001);
}
TEST(Househo_older, TEST_TWO_0) {

auto m = DenseCSR::Mat_es({{3, 5, 8},
                           {5, 3, 7},
                           {2, 4, 9}});

auto res = Ho_ouseholder::so_olve(std::vector<double>({8, 7, 6}), m);

ASSERT_NEAR(res[0], 0.717, 0.001);
ASSERT_NEAR(res[1], 1.239, 0.001);
ASSERT_NEAR(res[2], -0.043, 0.001);
}
TEST(Househo_older, TEST_THREEE) {

auto m = DenseCSR::Mat_es({{4, 7, 5},
                           {8, 5, 1},
                           {7, 4, 2}});

auto res = Ho_ouseholder::so_olve(std::vector<double>({8, 6, 9}), m);

ASSERT_NEAR(res[0], 1.444, 0.001);
ASSERT_NEAR(res[1], -1.667, 0.001);
ASSERT_NEAR(res[2], 2.778, 0.001);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}