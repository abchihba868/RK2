#include "../include/monster_pool.h"
#include <iostream>
#include <vector>

struct MonsterInfo {
    Monster const& monster;
    MonsterContext context;
};

void PrintMonsterInfo(MonsterInfo const& monsterInfo) {
    monsterInfo.monster.Print(monsterInfo.context);
}

int main() {
    MonsterPool monsterPool;
    std::vector<MonsterInfo> monsterInfoList;
    
    monsterInfoList.push_back({ monsterPool.GetSlime({ 6, 3 }), { 50, 0, 0 } });
    monsterInfoList.push_back({ monsterPool.GetSlime({ 6, 3 }), { 30, 1, 2 } });
    monsterInfoList.push_back({ monsterPool.GetSlime({ 1, 2 }), { 40, 2, -1 } });

    monsterInfoList.push_back({ monsterPool.GetGoblin({ 7, 5 }), { 80, 9, -3 } });
    monsterInfoList.push_back({ monsterPool.GetGoblin({ 5, 8 }), { 70, -5, -3 } });
    monsterInfoList.push_back({ monsterPool.GetGoblin({ 5, 8 }), { 90, 7, 0 } });

    monsterInfoList.push_back({ monsterPool.GetDragon({ 10, 12 }), { 200, 2, 11 } });
    monsterInfoList.push_back({ monsterPool.GetDragon({ 10, 12 }), { 400, 0, 9 } });
    monsterInfoList.push_back({ monsterPool.GetDragon({ 10, 12 }), { 350, 5, 1 } });

    PrintMonsterInfo(monsterInfoList[4]);
    monsterInfoList[4].context.hp -= 10;
    monsterInfoList[4].context.posX += 3;
    monsterInfoList[4].context.posY -= 1;
    PrintMonsterInfo(monsterInfoList[4]);

    PrintMonsterInfo(monsterInfoList[8]);
    monsterInfoList[8].context.hp -= 30;
    monsterInfoList[8].context.posX += 2;
    monsterInfoList[8].context.posY -= 7;
    PrintMonsterInfo(monsterInfoList[8]);
}
