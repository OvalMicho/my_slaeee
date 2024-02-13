#include <gtest/gtest.h>
#include "srcfunc.hpp"
#include <vector>
using namespace std;

TEST(ThreeD, TEST_1)
{
int N = 4;
vector<vector<double>> matA = {{3,21,0,0},
                               {6,8,2,0},
                               {0,4,3,1},
                               {0,0,3,2}};
vector<double> matD{4,7,3,6};

vector<double> matRes = FuncThreeD(N, matA, matD);

ASSERT_NEAR(matRes[0], 1.15537, 1e-3);
ASSERT_NEAR(matRes[1], 0.0254237, 1e-3);
ASSERT_NEAR(matRes[2], -0.0677966, 1e-3);
ASSERT_NEAR(matRes[3], 3.10169, 1e-3);
}

TEST(ThreeD, TEST_2)
{
int N = 4;
vector<vector<double>> matA = {{46,3,0,0},
                               {6.7,1.2,3.2,0},
                               {0,1.3,3,1},
                               {0,0,3,2}};
vector<double> matD{4,5.1,5,5};

vector<double> matRes = FuncThreeD(N, matA, matD);

ASSERT_NEAR(matRes[0], 0.0604859, 1e-3);
ASSERT_NEAR(matRes[1], 0.405883, 1e-3);
ASSERT_NEAR(matRes[2], 1.3149, 1e-3);
ASSERT_NEAR(matRes[3], 0.527648, 1e-3);
}


TEST(ThreeD, TEST_3)
{
int N = 4;
vector<vector<double>> matA = {{3,21,0,0},
                               {6,8,2,0},
                               {0,4,3,1},
                               {0,0,3,2}};
vector<double> matD{4,7,3,6};

vector<double> matRes = FuncThreeD(N, matA, matD);

ASSERT_NEAR(matRes[0], 1.15537, 1e-3);
ASSERT_NEAR(matRes[1], 0.0254237, 1e-3);
ASSERT_NEAR(matRes[2], -0.0677966, 1e-3);
ASSERT_NEAR(matRes[3], 3.10169, 1e-3);
}

