// option.h
// This file declares the Option class to represent gear lines, runes, enchants etc
// Also included is the Rune class used to represent runes
// And a bunch of constant options, the OPTION_TYPE and RUNE_OPTIONS enums

#ifndef OPTION_H
#define OPTION_H

// OPTION_TYPE enum
enum OPTION_TYPE{
	OPTION_NONE,
	OPTION_ATK,
	OPTION_SPD,
	OPTION_CRIT,
	OPTION_CDMG,
	OPTION_MPATK,
	OPTION_MPSEC,
	OPTION_PEN,
	OPTION_LIFESTEAL,
	OPTION_ACC,
	OPTION_DEBUFF_ACC,
	OPTION_HP,
	OPTION_CCRES,
	OPTION_BLOCK,
	OPTION_PBLOCK,
	OPTION_MBLOCK,
	OPTION_CRIT_RES,
	OPTION_P_CRIT_RES,
	OPTION_M_CRIT_RES,
	OPTION_DEF,
	OPTION_PDEF,
	OPTION_MDEF,
	OPTION_DODGE,
	OPTION_PDODGE,
	OPTION_MDODGE,
	// exclusive to runes, enchants, UTs
	OPTION_BLOCK_DEF,
	OPTION_P_BLOCK_DEF,
	OPTION_M_BLOCK_DEF,
	OPTION_HEAL_RATE,
	OPTION_HEAL_OUTPUT,
	OPTION_TOUGH,
	OPTION_PTOUGH,
	OPTION_MTOUGH,
	OPTION_MPDMG,
	OPTION_TOTAL
};

// RUNE_OPTIONS enum
enum RUNE_OPTIONS{
	RUNE_NORMAL,
	RUNE_VELK,
	RUNE_OPTIONS_TOTAL
};

class Option{
public:
	Option(int type = OPTION_NONE, double value = 0.0);
	~Option();
	// setter functions
	void changeOption(int newType, double newValue);
	void changeValue(double newValue);

	// getter functions
	int getOptionType();
	double getOptionValue();
private:
	int optionType;
	double optionValue;
};

class Rune{
public:
	Rune(Option option1 = Option(), bool isitVelk = false, Option option2 = Option());
	~Rune();
private:
	Option runeOptions[RUNE_OPTIONS_TOTAL];
	bool isVelk;
};

// weapon runes (triangular) and their Velk half editions
const Option RUNE_ATK = Option(OPTION_ATK, 20.0);
const Option RUNE_VELK_ATK = Option(OPTION_ATK, 11.0);
const Option RUNE_PEN = Option(OPTION_PEN, 200.0);
const Option RUNE_VELK_PEN = Option(OPTION_PEN, 110.0);
const Option RUNE_VELK_TOUGH = Option(OPTION_TOUGH, 55.0);
const Option RUNE_PTOUGH = Option(OPTION_PTOUGH, 200.0);
const Option RUNE_VELK_PTOUGH = Option(OPTION_PTOUGH, 110.0);
const Option RUNE_MTOUGH = Option(OPTION_MTOUGH, 200.0);
const Option RUNE_VELK_MTOUGH = Option(OPTION_MTOUGH, 110.0);
const Option RUNE_LIFESTEAL = Option(OPTION_LIFESTEAL, 200.0);
const Option RUNE_VELK_LIFESTEAL = Option(OPTION_LIFESTEAL, 110.0);
const Option RUNE_MPATK = Option(OPTION_MPATK, 400.0);
const Option RUNE_VELK_MPATK = Option(OPTION_MPATK, 220.0);

#endif // OPTION_H