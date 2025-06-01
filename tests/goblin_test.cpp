#include "../include/goblin.h"
#include <gtest/gtest.h>

TEST(GoblinTest, PrintOutput) {
    Goblin::IntrinsicState state{7, 5};
    Goblin goblin(state);
    MonsterContext context{80, 2, 3};
    
    testing::internal::CaptureStdout();
    goblin.Print(context);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Goblin") != std::string::npos);
    EXPECT_TRUE(output.find("80") != std::string::npos);
    EXPECT_TRUE(output.find("7") != std::string::npos);
    EXPECT_TRUE(output.find("5") != std::string::npos);
}
