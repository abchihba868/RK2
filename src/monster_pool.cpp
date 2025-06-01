#include "../include/monster_pool.h"

template <typename MonsterType>
MonsterType const& MonsterPool::GetImpl_(
    std::map<typename MonsterType::IntrinsicState, MonsterType>& pool,
    typename MonsterType::IntrinsicState const& state) {
    auto iter = pool.find(state);
    if (iter == std::end(pool)) {
        iter = pool.insert(std::make_pair(state, MonsterType(state))).first;
    }
    return iter->second;
}

Slime const& MonsterPool::GetSlime(Slime::IntrinsicState const& state) {
    return GetImpl_(slimePool_, state);
}

Goblin const& MonsterPool::GetGoblin(Goblin::IntrinsicState const& state) {
    return GetImpl_(goblinPool_, state);
}

Dragon const& MonsterPool::GetDragon(Dragon::IntrinsicState const& state) {
    return GetImpl_(dragonPool_, state);
}
