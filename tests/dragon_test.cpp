#include "../include/dragon.h"
#include <gtest/gtest.h>

TEST(DragonTest, PrintOutput) {
    Dragon::IntrinsicState state{10, 12};
    Dragon dragon(state);
    MonsterContext context{200, 5, 5};
    
    testing::internal::CaptureStdout();
    dragon.Print(context);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Dragon") != std::string::npos);
    EXPECT_TRUE(output.find("200") != std::string::npos);
    EXPECT_TRUE(output.find("10") != std::string::npos);
    EXPECT_TRUE(output.find("12") != std::string::npos);
}
