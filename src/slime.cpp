#include "../include/slime.h"

bool Slime::IntrinsicState::operator<(IntrinsicState const& state) const {
    if (viscosity < state.viscosity) return true;
    if (viscosity > state.viscosity) return false;
    return transparency < state.transparency;
}

Slime::Slime(IntrinsicState const& state) : state_(state) {}

void Slime::Print(MonsterContext const& context) const {
    std::cout << "----- Slime -----\n"
              << "HP           : " << context.hp << "\n"
              << "Position     : (" << context.posX << ", " << context.posY << ")\n"
              << "Viscosity    : " << state_.viscosity << "\n"
              << "Transparency : " << state_.transparency << "\n"
              << "-----------------\n";
}
