#pragma once
#include "monster.h"

class Slime : public Monster {
public:
    struct IntrinsicState {
        bool operator<(IntrinsicState const& state) const;
        int viscosity;
        int transparency;
    };

    explicit Slime(IntrinsicState const& state);
    void Print(MonsterContext const& context) const override;
};
