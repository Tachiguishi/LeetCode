#include <solution.h>
#include <gtest/gtest.h>

TEST(FooTest, Test1) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(3 > 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
