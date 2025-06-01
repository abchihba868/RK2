#pragma once
#include "slime.h"
#include "goblin.h"
#include "dragon.h"
#include <map>

class MonsterPool {
public:
    Slime const& GetSlime(Slime::IntrinsicState const& state);
    Goblin const& GetGoblin(Goblin::IntrinsicState const& state);
    Dragon const& GetDragon(Dragon::IntrinsicState const& state);

private:
    template <typename MonsterType>
    MonsterType const& GetImpl_(
        std::map<typename MonsterType::IntrinsicState, MonsterType>& pool,
        typename MonsterType::IntrinsicState const& state);

    std::map<Slime::IntrinsicState, Slime> slimePool_;
    std::map<Goblin::IntrinsicState, Goblin> goblinPool_;
    std::map<Dragon::IntrinsicState, Dragon> dragonPool_;
};
