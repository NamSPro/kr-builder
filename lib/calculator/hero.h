// hero.h
// This file declares the Hero class, the one that actually gets displayed
// Also included is a bunch of template for different classes

#ifndef HERO_H
#define HERO_H

#include <map>
#include "gear.h"

const std::map <int, double> HERO_BASE_TEMPLATES[HERO_CLASS_TOTAL] = {
	{},
	{{OPTION_HP, 1706672.0}, {OPTION_ATK, 19792.0}, {OPTION_PDEF, 8792.0}, {OPTION_MDEF, 6840.0}, {OPTION_CRIT, 50.0}, {OPTION_BLOCK, 100.0},
	 {OPTION_TOUGH, 250.0}, {OPTION_SPD, 1000.0}},
	{{OPTION_HP, 1449520.0}, {OPTION_ATK, 22488.0}, {OPTION_PDEF, 7328.0}, {OPTION_MDEF, 8792.0}, {OPTION_CRIT, 150.0}, {OPTION_PEN, 150.0},
	 {OPTION_ACC, 100.0}, {OPTION_DODGE, 100.0}, {OPTION_CCRES, 150.0}, {OPTION_SPD, 1000.0}},
	{{OPTION_HP, 1384992.0}, {OPTION_ATK, 24688.0}, {OPTION_PDEF, 7816.0}, {OPTION_MDEF, 6840.0}, {OPTION_CRIT, 200.0}, {OPTION_CDMG, 30.0},
	 {OPTION_ACC, 100.0}, {OPTION_DODGE, 200.0}, {OPTION_SPD, 1000.0}},
	{{OPTION_HP, 1066728.0}, {OPTION_ATK, 27864.0}, {OPTION_PDEF, 5376.0}, {OPTION_MDEF, 4392.0}, {OPTION_CRIT, 150.0}, {OPTION_PEN, 250.0},
	 {OPTION_ACC, 100.0}, {OPTION_SPD, 1000.0}},
	{{OPTION_HP, 1157176.0}, {OPTION_ATK, 25416.0}, {OPTION_PDEF, 5376.0}, {OPTION_MDEF, 4392.0}, {OPTION_CRIT, 150.0}, {OPTION_CDMG, 50.0},
	 {OPTION_PEN, 100.0}, {OPTION_ACC, 200.0}, {OPTION_SPD, 1000.0}},
	{{OPTION_HP, 985328.0}, {OPTION_ATK, 29328.0}, {OPTION_PDEF, 3904.0}, {OPTION_MDEF, 5864.0}, {OPTION_CRIT, 100.0}, {OPTION_PEN, 150.0},
	 {OPTION_ACC, 100.0}, {OPTION_MDODGE, 200.0}, {OPTION_MBLOCK, 250.0}, {OPTION_SPD, 1000.0}},
	{{OPTION_HP, 1104864.0}, {OPTION_ATK, 23216.0}, {OPTION_PDEF, 4888.0}, {OPTION_MDEF, 6104.0}, {OPTION_CRIT, 100.0}, {OPTION_ACC, 100.0},
	 {OPTION_MBLOCK, 500.0}, {OPTION_M_BLOCK_DEF, 250.0}, {OPTION_MTOUGH, 150.0}, {OPTION_SPD, 1000.0}}
};
const int TREASURE_COUNT = 4;

class Hero{
public:
	Hero(int heroClass = CLASS_NONE);
	~Hero();
	// entire piece update
	// used to load in premade gear
	bool changeGear(int position, Gear newGear);
	void changeTreasure(int position, Gear newTreasure);

	// used to tinker with the loaded gear
	void changeGearStarLevel(int position, int newStarLevel);
	bool changeGearOption(int position, int optionPosition, Option newOption);
	bool changeGearOption(int position, int optionPosition, int newOption, double newValue);
	bool changeGearOptionValue(int position, int optionPosition, double newValue);
	bool changeGearRune(int position, int runePosition, Rune newRune);
	bool changeGearEnchant(int position, int enchantPosition, Option newOption);
	bool changeGearEnchant(int position, int enchantPosition, int newOption, double newValue);
	bool changeGearEnchantValue(int position, int enchantPosition, double newValue);

	// getter functions
	int getStat(int option);
	int getFlatStat(int option);
	double getBaseStat(int option);
	void printSheet();

private:
	Hero(int heroClass, std::map <int, double> options);
	// called whenever an update takes place
	void updateInfo();

	Gear heroGears[GEAR_TYPE_TOTAL];

	// for the most part treasure is similar to gears, but no enchants and runes
	Gear heroTreasures[TREASURE_COUNT]; // the treasure at position 0 will be main treasure

	Option heroSheet[OPTION_TOTAL];
	Option heroFlatSheet[OPTION_TOTAL];
	Option heroBaseSheet[OPTION_TOTAL];
};

#endif // HERO_H