#include "../include/slime.h"
#include <gtest/gtest.h>

TEST(SlimeTest, PrintOutput) {
    Slime::IntrinsicState state{5, 2};
    Slime slime(state);
    MonsterContext context{100, 1, 1};
    
    testing::internal::CaptureStdout();
    slime.Print(context);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Slime") != std::string::npos);
    EXPECT_TRUE(output.find("100") != std::string::npos);
    EXPECT_TRUE(output.find("5") != std::string::npos);
    EXPECT_TRUE(output.find("2") != std::string::npos);
}
