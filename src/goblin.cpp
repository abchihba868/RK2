#include "../include/goblin.h"
#include <iostream>

bool Goblin::IntrinsicState::operator<(IntrinsicState const& state) const {
    if (angerDegree < state.angerDegree) return true;
    if (angerDegree > state.angerDegree) return false;
    return uglinessDegree < state.uglinessDegree;
}

Goblin::Goblin(IntrinsicState const& state) : state_(state) {}

void Goblin::Print(MonsterContext const& context) const {
    std::cout << "----- Goblin -----\n"
              << "HP             : " << context.hp << "\n"
              << "Position       : (" << context.posX << ", " << context.posY << ")\n"
              << "AngerDegree    : " << state_.angerDegree << "\n"
              << "UglinessDegree : " << state_.uglinessDegree << "\n"
              << "------------------\n";
}
