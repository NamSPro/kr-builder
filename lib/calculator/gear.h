// gear.h
// This file declares a Gear class for equipments

#ifndef GEAR_H
#define GEAR_H

#include "option.h"
#include "4th_dimension.h"
#include "soul_weapon.h"

enum GEAR_SET{
	GEAR_SET_NONE,
	GEAR_RED,
	GEAR_ICE,
	GEAR_POISON,
	GEAR_BLACK,
	GEAR_LAVA,
	GEAR_LEGEND,
	GEAR_DL,
	GEAR_SUPPRESS,
	GEAR_PROTECT,
	GEAR_MANTI,
	GEAR_TM_AMP,
	GEAR_GALGORIA,
	GEAR_SIEGFRIED,
	GEAR_ASCALON,
	GEAR_SET_TOTAL
};

const int GEAR_OPTIONS_TOTAL = 4;
const int GEAR_RUNES_TOTAL = 3;
const int GEAR_ENCHANTS_TOTAL = 3;

class Gear{
public:
	Gear(int heroClass = CLASS_NONE);
	~Gear();

	// setter functions
	// these should not be called during gear tinkering
	void changeGearType(int newType, int newAccessoryType = ACCESSORY_NONE);
	void changeAccessoryType(int newAccessoryType);
	void changeGearCondition(int newCondition);
	void changeGearSet(int newSet);
	
	// these can be called during tinkering
	void changeStarLevel(int newStarLevel);
	bool changeOption(int position, Option newOption);
	bool changeOption(int position, int newOption, double newValue);
	bool changeOptionValue(int position, double newValue);
	bool changeRune(int position, Rune newRune);
	bool changeEnchant(int position, Option newOption);
	bool changeEnchant(int position, int newOption, double newValue);
	bool changeEnchantValue(int position, double newValue);

	// SW
	void changeSoulActivationStatus();
	void changeSoulAdvLevel(int newLevel);
	void changeSoulEtherLevel(int newEtherLevel);
	void changeSoulAtkRollValue(double newValue); // HP roll is always 100% - this
	void changeSoulAtkBonusValue(double newValue);
	void changeSoulHpBonusValue(double newValue);

	// getter functions
	// generic
	int getGearType();
	int getAccessoryType();
	int getGearSet();
	double getStatBoost();
	int getCondition();
	int getStarLevel();
	Option getOption(int position);
	Rune getRune(int position);
	Option getEnchant(int position);

	// SW
	bool getSoulActivationStatus();
	int getSoulAdvLevel();
	int getSoulEtherLevel();
	double getSoulAtkStat();
	double getSoulHpStat();
	double getSoulAtkRollValue();
	double getSoulHpRollValue();
	double getSoulAtkBonusValue();
	double getSoulHpBonusValue();

private:
	// denotes the class this gear is intended for
	int equippableClass;

	// denotes the position and accessory type
	// generally accessoryType should be ACCESSORY_NONE unless gearType is GEAR_ACCESSORY
	int gearType, accessoryType;

	// GEAR_TIER(number), GEAR_UNIQUE or GEAR_TM/GEAR_TM_RECLAIMED
	int gearCondition, gearSet;
	int starLevel;

	// this represents gear options
	Option gearOptions[GEAR_OPTIONS_TOTAL];

	// this represents runes (from 1 of a single stat rune on armors, upto 3 Velk runes on weapon)
	Rune gearRunes[GEAR_RUNES_TOTAL];

	// this represents enchantments (from 1 of traditional gear to 3 of TM)
	Option gearEnchants[GEAR_ENCHANTS_TOTAL];

	// this is self explanatory
	SoulWeapon uwSoul;
};

#endif // GEAR_H