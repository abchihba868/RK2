#include "../include/monster_pool.h"
#include <gtest/gtest.h>

TEST(MonsterPoolTest, GetSameSlime) {
    MonsterPool pool;
    auto& slime1 = pool.GetSlime({5, 2});
    auto& slime2 = pool.GetSlime({5, 2});
    EXPECT_EQ(&slime1, &slime2);
}

TEST(MonsterPoolTest, GetDifferentGoblins) {
    MonsterPool pool;
    auto& goblin1 = pool.GetGoblin({3, 4});
    auto& goblin2 = pool.GetGoblin({3, 5});
    EXPECT_NE(&goblin1, &goblin2);
}
