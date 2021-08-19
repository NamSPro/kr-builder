// option.h
// This file declares the Option class to represent gear lines, runes, enchants etc
// Also included is the Rune class used to represent runes
// And a bunch of constant options, the OPTION_TYPE and RUNE_OPTIONS enums

#ifndef OPTION_H
#define OPTION_H

#include <string>

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
	void changeValue(double newValue); // change to a specific number
	void modifyValue(double modifier); // add with modifier

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

	// getter functions
	std::string getRuneName();
	Option getRuneOption(int position);
private:
	void findRuneName();
	std::string runeName;
	Option runeOptions[RUNE_OPTIONS_TOTAL];
	bool isVelk;
};

// weapon runes (triangular) and their Velk half editions, option form for easy building
const Option RUNE_ATK = Option(OPTION_ATK, 20.0);
const Option RUNE_VELK_ATK = Option(OPTION_ATK, 11.0);
const Option RUNE_PEN = Option(OPTION_PEN, 200.0);
const Option RUNE_VELK_PEN = Option(OPTION_PEN, 110.0);
const Option RUNE_VELK_TOUGH = Option(OPTION_TOUGH, 55.0);
const Option RUNE_PTOUGH = Option(OPTION_PTOUGH, 200.0);
const Option RUNE_VELK_PTOUGH = Option(OPTION_PTOUGH, 110.0);
const Option RUNE_MTOUGH = Option(OPTION_MTOUGH, 200.0);
const Option RUNE_VELK_MTOUGH = Option(OPTION_MTOUGH, 110.0);
const Option RUNE_VELK_BLOCK_DEF = Option(OPTION_BLOCK_DEF, 55.0);
const Option RUNE_P_BLOCK_DEF = Option(OPTION_P_BLOCK_DEF, 200.0);
const Option RUNE_VELK_P_BLOCK_DEF = Option(OPTION_P_BLOCK_DEF, 110.0);
const Option RUNE_M_BLOCK_DEF = Option(OPTION_M_BLOCK_DEF, 200.0);
const Option RUNE_VELK_M_BLOCK_DEF = Option(OPTION_M_BLOCK_DEF, 110.0);
const Option RUNE_LIFESTEAL = Option(OPTION_LIFESTEAL, 200.0);
const Option RUNE_VELK_LIFESTEAL = Option(OPTION_LIFESTEAL, 110.0);
const Option RUNE_MPATK = Option(OPTION_MPATK, 400.0);
const Option RUNE_VELK_MPATK = Option(OPTION_MPATK, 220.0);

// armor runes (squares) and their Velk half editions
const Option RUNE_CDMG = Option(OPTION_CDMG, 40.0);
const Option RUNE_VELK_CDMG = Option(OPTION_CDMG, 22.0);
const Option RUNE_ACC = Option(OPTION_ACC, 200.0);
const Option RUNE_VELK_ACC = Option(OPTION_ACC, 110.0);
const Option RUNE_VELK_BLOCK = Option(OPTION_BLOCK, 55.0);
const Option RUNE_PBLOCK = Option(OPTION_PBLOCK, 200.0);
const Option RUNE_VELK_PBLOCK = Option(OPTION_PBLOCK, 110.0);
const Option RUNE_MBLOCK = Option(OPTION_MBLOCK, 200.0);
const Option RUNE_VELK_MBLOCK = Option(OPTION_MBLOCK, 110.0);
const Option RUNE_CCRES = Option(OPTION_CCRES, 200.0);
const Option RUNE_VELK_DEF = Option(OPTION_DEF, 11.0);
const Option RUNE_PDEF = Option(OPTION_PDEF, 40.0);
const Option RUNE_VELK_PDEF = Option(OPTION_PDEF, 22.0);
const Option RUNE_MDEF = Option(OPTION_MDEF, 40.0);
const Option RUNE_VELK_MDEF = Option(OPTION_MDEF, 22.0);
const Option RUNE_VELK_CCRES = Option(OPTION_CCRES, 110.0);
const Option RUNE_HP = Option(OPTION_HP, 20.0);
const Option RUNE_VELK_HP = Option(OPTION_HP, 11.0);

// sub armor runes (diamonds?) and their Velk half editions
const Option RUNE_CRIT = Option(OPTION_CRIT, 200.0);
const Option RUNE_VELK_CRIT = Option(OPTION_CRIT, 110.0);
const Option RUNE_VELK_DODGE = Option(OPTION_DODGE, 55.0);
const Option RUNE_PDODGE = Option(OPTION_PDODGE, 200.0);
const Option RUNE_VELK_PDODGE = Option(OPTION_PDODGE, 110.0);
const Option RUNE_MDODGE = Option(OPTION_MDODGE, 200.0);
const Option RUNE_VELK_MDODGE = Option(OPTION_MDODGE, 110.0);
const Option RUNE_MPDMG = Option(OPTION_MPDMG, 60.0);
const Option RUNE_VELK_MPDMG = Option(OPTION_MPDMG, 33.0);

#endif // OPTION_H