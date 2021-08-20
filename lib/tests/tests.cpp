// tests.cpp
// This file implements test suites declared in tests.h

#include <cstdio>
#include "tests.h"

void test(){
	freopen("test_output.txt", "w", stdout);
	Hero kara(CLASS_MECHANIC);
	printf("Base ATK: %f\n", kara.getBaseStat(OPTION_ATK));

	Gear heavenshatterer(CLASS_MECHANIC);
	heavenshatterer.changeGearCondition(GEAR_UNIQUE);
	heavenshatterer.changeGearType(GEAR_WEAPON);
	kara.changeGear(GEAR_WEAPON, heavenshatterer);
	printf("ATK with 0* UW: %f\n", kara.getStat(OPTION_ATK));

	Gear manti(CLASS_MECHANIC);
	manti.changeGearCondition(GEAR_TIER8);
	manti.changeGearType(GEAR_ACCESSORY);
	manti.changeAccessoryType(ACCESSORY_EARRINGS);
	kara.changeGear(GEAR_ACCESSORY, manti);
	printf("ATK with 0* UW and manti earrings: %f\n", kara.getStat(OPTION_ATK));

	Rune pureAtk = Rune(RUNE_ATK);
	heavenshatterer.changeRune(0, pureAtk);
	kara.changeGear(GEAR_WEAPON, heavenshatterer);
	printf("ATK with 1 ATK rune: %f\n", kara.getStat(OPTION_ATK));
	return;
}
// remember to delete when prod is up