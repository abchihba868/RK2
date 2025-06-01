#pragma once

struct MonsterContext {
    int hp;
    int posX, posY;
};

class Monster {
public:
    virtual ~Monster() = default;
    virtual void Print(MonsterContext const& context) const = 0;

private:
    IntrinsicState state_;
};
