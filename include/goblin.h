#pragma once
#include "monster.h"

class Goblin : public Monster {
public:
    struct IntrinsicState {
        bool operator<(IntrinsicState const& state) const;
        int angerDegree;
        int uglinessDegree;
    };

    explicit Goblin(IntrinsicState const& state);
    void Print(MonsterContext const& context) const override;
};
