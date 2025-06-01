#include "../include/dragon.h"

bool Dragon::IntrinsicState::operator<(IntrinsicState const& state) const {
    if (height < state.height) return true;
    if (height > state.height) return false;
    return firePower < state.firePower;
}

Dragon::Dragon(IntrinsicState const& state) : state_(state) {}

void Dragon::Print(MonsterContext const& context) const {
    std::cout << "----- Dragon -----\n"
              << "HP        : " << context.hp << "\n"
              << "Position  : (" << context.posX << ", " << context.posY << ")\n"
              << "Height    : " << state_.height << "\n"
              << "FirePower : " << state_.firePower << "\n"
              << "------------------\n";
}
