#pragma once
#include "monster.h"

class Dragon : public Monster {
public:
    struct IntrinsicState {
        bool operator<(IntrinsicState const& state) const;
        int height;
        int firePower;
    };

    explicit Dragon(IntrinsicState const& state);
    void Print(MonsterContext const& context) const override;
};
