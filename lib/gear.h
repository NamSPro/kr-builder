// gear.h
// This file declares a Gear class for equipments

#ifndef GEAR_H
#define GEAR_H

#include "option.h"

// gear enums
// GEAR_TYPE denotes position, ACCESSORY_TYPE denotes accessory type, and GEAR_CONDITION denotes tier
enum GEAR_TYPE{
	GEAR_NONE,
	GEAR_WEAPON,
	GEAR_ARMOR,
	GEAR_SECONDARY,
	GEAR_TREASURE,
	GEAR_ACCESSORY,
	GEAR_ORB,
	GEAR_ARTIFACT,
	GEAR_TYPE_TOTAL
};

enum ACCESSORY_TYPE{
	ACCESSORY_NONE,
	ACCESSORY_EARRINGS,
	ACCESSORY_BRACELET,
	ACCESSORY_NECKLACE,
	ACCESSORY_RING
};

enum GEAR_CONDITION{
	GEAR_UNTIERED,
	GEAR_TIER6,
	GEAR_TIER7,
	GEAR_TIER8,
	GEAR_UNIQUE,
	GEAR_TM,
	GEAR_TM_RECLAIMED,
	GEAR_CONDITION_TOTAL
};

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

// STAR_LEVEL enum
enum STAR_LEVEL{
	STAR_0STAR,
	STAR_1STAR,
	STAR_2STAR,
	STAR_3STAR,
	STAR_4STAR,
	STAR_5STAR,
	GEAR_STAR_TOTAL
};

// HERO_CLASS enum
enum HERO_CLASS{
	CLASS_NONE,
	CLASS_KNIGHT,
	CLASS_WARRIOR,
	CLASS_ARCHER,
	CLASS_ASSASSIN,
	CLASS_MECHANIC,
	CLASS_WIZARD,
	CLASS_PRIEST,
	HERO_CLASS_TOTAL
};

const int GEAR_OPTIONS_TOTAL = 4;
const int GEAR_RUNES_TOTAL = 3;
const int GEAR_ENCHANTS_TOTAL = 3;

class Gear{
public:
	Gear();
	~Gear();
	// setter functions
	void changeGearType(int newType, int newAccessoryType = ACCESSORY_NONE);
	bool changeOption(int position, Option newOption);
	bool changeOption(int position, int newOption, double newValue);
	bool changeOptionValue(int position, double newValue);
	bool changeRune(int position, Rune newRune);
	bool changeEnchant(int position, Option newOption);
	bool changeEnchant(int position, int newOption, double newValue);

	// getter functions
	int getGearType();
	int getAccessoryType();
	int getStatBoost();
	Option getOption(int position);
	Rune getRune(int position);
	Option getEnchant(int position);
private:
	// denotes the position and accessory type
	// generally accessoryType should be ACCESSORY_NONE unless gearType is GEAR_ACCESSORY
	int gearType, accessoryType;

	// GEAR_TIER(number), GEAR_UNIQUE or GEAR_TM/GEAR_TM_RECLAIMED
	int gearCondition;
	int starLevel;

	// this represents flat stats
	int statBoost;

	// this represents gear options
	Option gearOptions[GEAR_OPTIONS_TOTAL];

	// this represents runes (from 1 of a single stat rune on armors, upto 3 Velk runes on weapon)
	Rune gearRunes[GEAR_RUNES_TOTAL];

	// this represents enchantments (from 1 of traditional gear to 3 of TM)
	Option gearEnchants[GEAR_ENCHANTS_TOTAL];
};

#endif // GEAR_H