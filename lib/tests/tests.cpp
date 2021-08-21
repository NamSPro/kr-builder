// tests.cpp
// This file implements test suites declared in tests.h

#include <cstdio>
#include "tests.h"

void test(){
	Hero kara(CLASS_MECHANIC);
	printf("Base ATK: %f\n", kara.getBaseStat(OPTION_ATK));

	Gear heavenshatterer(CLASS_MECHANIC);
	heavenshatterer.changeGearCondition(GEAR_UNIQUE);
	heavenshatterer.changeGearType(GEAR_WEAPON);
	heavenshatterer.changeStarLevel(STAR_5STAR);
	for(int it = 0; it < 3; it++) heavenshatterer.changeRune(it, RUNE_ATK);
	heavenshatterer.changeSoulActivationStatus();
	heavenshatterer.changeSoulAdvLevel(2);
	heavenshatterer.changeSoulEtherLevel(20);
	heavenshatterer.changeSoulAtkRollValue(68.7);
	heavenshatterer.changeSoulAtkBonusValue(16.2);
	heavenshatterer.changeSoulHpBonusValue(5.9);
	printf("ATK boost from UW: %f\nATK boost from SW: %f\n", heavenshatterer.getStatBoost(), heavenshatterer.getSoulAtkStat());
	kara.changeGear(GEAR_WEAPON, heavenshatterer);
	printf("ATK with UW: %f\n", kara.getStat(OPTION_ATK));
	return;
}