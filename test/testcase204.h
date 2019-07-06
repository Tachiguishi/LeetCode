#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class CountPrimes204: public ::testing::TestWithParam<TwoInt>{

};

TEST_P(CountPrimes204, test1){
	TwoInt args = GetParam();
	Solution sol;
	int res = sol.countPrimes(args.int1);
	EXPECT_EQ(res, args.int2) << "input: " << args.int1;
}

INSTANTIATE_TEST_SUITE_P(leetcode, CountPrimes204,
	::testing::Values(TwoInt(10, 4),
		TwoInt(9999, 1229),
		TwoInt(999999, 78498)
	));
