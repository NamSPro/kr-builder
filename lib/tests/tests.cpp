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

	Gear mainArmor(CLASS_MECHANIC);
	mainArmor.changeGearCondition(GEAR_TM_RECLAIMED);
	mainArmor.changeGearType(GEAR_ARMOR);
	mainArmor.changeGearSet(GEAR_SET_GALGORIA);
	mainArmor.changeStarLevel(STAR_5STAR);
	for(int i = 0; i < 2; i++) mainArmor.changeOption(i, Option(OPTION_ATK, 16.0));
	mainArmor.changeRune(0, Rune(RUNE_VELK_ATK, true, RUNE_VELK_CDMG));
	mainArmor.changeEnchant(0, Option(OPTION_ATK, 4.0));
	mainArmor.changeEnchant(1, Option(OPTION_CDMG, 8.0));
	kara.changeGear(GEAR_ARMOR, mainArmor);
	mainArmor.changeGearType(GEAR_SECONDARY);
	kara.changeGear(GEAR_SECONDARY, mainArmor);
	mainArmor.changeRune(0, Rune());
	mainArmor.changeGearType(GEAR_ORB);
	kara.changeGear(GEAR_ORB, mainArmor);
	mainArmor.changeEnchantValue(0, 8.0);
	mainArmor.changeEnchantValue(1, 0.0);
	mainArmor.changeGearType(GEAR_ACCESSORY, ACCESSORY_EARRINGS);
	kara.changeGear(GEAR_ACCESSORY, mainArmor);
	kara.printSheet();

	Gear ut2(CLASS_MECHANIC);
	ut2.changeGearCondition(GEAR_UNIQUE);
	ut2.changeGearType(GEAR_TREASURE);
	ut2.changeStarLevel(STAR_5STAR);
	ut2.changeOption(0, Option(OPTION_ATK, 14.0));
	ut2.changeOption(1, Option(OPTION_CDMG, 22.0));
	kara.changeTreasure(0, ut2);
	ut2.changeOption(1, Option(OPTION_CDMG, 24.0));
	kara.changeTreasure(1, ut2);
	ut2.changeOption(1, Option(OPTION_SPD, 120.0));
	kara.changeTreasure(2, ut2);
	ut2.changeOption(1, Option(OPTION_SPD, 110.0));
	kara.changeTreasure(3, ut2);
	kara.printSheet();
	return;
}