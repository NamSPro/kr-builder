// hero.cpp
// This file implements functions declared in hero.h

#include <algorithm>
#include <cstdio>
#include <cmath>
#include "hero.h"
#include "percentage.h"

Hero::Hero(int heroClass){
	switch (heroClass){
		case CLASS_NONE:{
			break;
		}
		default:{
			*this = Hero(heroClass, HERO_BASE_TEMPLATES[heroClass]);
			break;
		}
	}
	return;
}

Hero::~Hero(){
	return;
}

bool Hero::changeGear(int position, Gear newGear){
	if(position != newGear.getGearType()){
		printf("Invalid gear position to equip!");
		return false;
	}
	heroGears[position] = newGear;
	updateInfo();
	return true;
}

void Hero::changeTreasure(int position, Gear newTreasure){
	heroTreasures[position] = newTreasure;
	updateInfo();
	return;
}

void Hero::changeGearStarLevel(int position, int newStarLevel){
	heroGears[position].changeStarLevel(newStarLevel);
	updateInfo();
	return;
}

bool Hero::changeGearOption(int position, int optionPosition, Option newOption){
	bool success = heroGears[position].changeOption(optionPosition, newOption);
	if(success) updateInfo();
	return success;
}

bool Hero::changeGearOption(int position, int optionPosition, int newOption, double newValue){
	bool success = heroGears[position].changeOption(optionPosition, newOption, newValue);
	if(success) updateInfo();
	return success;
}

bool Hero::changeGearOptionValue(int position, int optionPosition, double newValue){
	bool success = heroGears[position].changeOptionValue(optionPosition, newValue);
	if(success) updateInfo();
	return success;
}

bool Hero::changeGearRune(int position, int runePosition, Rune newRune){
	bool success = heroGears[position].changeRune(runePosition, newRune);
	if(success) updateInfo();
	return success;
}

bool Hero::changeGearEnchant(int position, int enchantPosition, Option newOption){
	bool success = heroGears[position].changeEnchant(enchantPosition, newOption);
	if(success) updateInfo();
	return success;
}

bool Hero::changeGearEnchant(int position, int enchantPosition, int newOption, double newValue){
	bool success = heroGears[position].changeEnchant(enchantPosition, newOption, newValue);
	if(success) updateInfo();
	return success;
}

bool Hero::changeGearEnchantValue(int position, int enchantPosition, double newValue){
	bool success = heroGears[position].changeEnchantValue(enchantPosition, newValue);
	if(success) updateInfo();
	return success;
}

int Hero::getStat(int option){
	return std::floor(heroSheet[option].getOptionValue());
}

int Hero::getFlatStat(int option){
	return std::floor(heroFlatSheet[option].getOptionValue());
}

double Hero::getBaseStat(int option){
	return heroBaseSheet[option].getOptionValue();
}

void Hero::printSheet(){
	updateInfo();

	// basic stats
	printf("Max HP: %d\nATK: %d\n", getStat(OPTION_HP), getStat(OPTION_ATK));
	printf("PDEF: %d\nMDEF: %d\n", getStat(OPTION_PDEF), getStat(OPTION_MDEF));

	// additional stats, offensive series
	printf("Crit: %d | %d\%\n", getFlatStat(OPTION_CRIT), getStat(OPTION_CRIT));
	printf("Crit DMG: %d\%\n", getFlatStat(OPTION_CDMG));
}

Hero::Hero(int heroClass, std::map <int, double> options){
	for(auto it = options.begin(); it != options.end(); it++){
		heroBaseSheet[it->first].changeOption(it->first, it->second);
		heroSheet[it->first].changeOption(it->first, it->second);
	}
	for(int it = GEAR_WEAPON; it < GEAR_TYPE_TOTAL; it++){
		heroGears[it] = Gear(heroClass);
	}
	return;
}

void Hero::updateInfo(){
	for(int option = OPTION_ATK; option < OPTION_TOTAL; option++){
		heroFlatSheet[option] = heroBaseSheet[option];
		heroSheet[option] = Option();
	}
	int setCount[GEAR_SET_TOTAL];
	for(int set = GEAR_SET_NONE; set < GEAR_SET_TOTAL; set++){
		setCount[set] = 0;
	}
	// finding the modifiers
	for(int it = GEAR_WEAPON; it < GEAR_TYPE_TOTAL - 1; it++){
		if(it == GEAR_ARTIFACT || heroGears[it].getGearType() == GEAR_NONE) continue; // again, hardcoded

		setCount[heroGears[it].getGearSet()]++;
		if(heroGears[it].getGearType() == GEAR_WEAPON || heroGears[it].getAccessoryType() == ACCESSORY_EARRINGS){
			if((heroGears[it].getGearType() == GEAR_WEAPON) && heroGears[it].getSoulActivationStatus()){ // SW calculation
				heroFlatSheet[OPTION_ATK].modifyValue(heroGears[it].getSoulAtkStat());
				heroFlatSheet[OPTION_HP].modifyValue(heroGears[it].getSoulHpStat());
			}
			heroFlatSheet[OPTION_ATK].modifyValue(heroGears[it].getStatBoost());
		}
		if(heroGears[it].getGearType() == GEAR_ARMOR || heroGears[it].getAccessoryType() == ACCESSORY_BRACELET){
			heroFlatSheet[OPTION_PDEF].modifyValue(heroGears[it].getStatBoost());
		}
		if(heroGears[it].getGearType() == GEAR_SECONDARY || heroGears[it].getAccessoryType() == ACCESSORY_NECKLACE){
			heroFlatSheet[OPTION_MDEF].modifyValue(heroGears[it].getStatBoost());
		}
		if(heroGears[it].getGearType() == GEAR_ORB || heroGears[it].getAccessoryType() == ACCESSORY_RING){
			heroFlatSheet[OPTION_HP].modifyValue(heroGears[it].getStatBoost());
		}

		for(int optionCount = 0; optionCount < GEAR_OPTIONS_TOTAL; optionCount++){
			Option currentOption = heroGears[it].getOption(optionCount);
			if(currentOption.getOptionType() == OPTION_NONE){
				continue;
			}
			int currentOptionType = currentOption.getOptionType();
			heroSheet[currentOptionType].modifyValue(currentOption.getOptionValue());
		}

		for(int optionCount = 0; optionCount < GEAR_RUNES_TOTAL; optionCount++){
			Rune currentRune = heroGears[it].getRune(optionCount);
			for(int runeOptionCount = 0; runeOptionCount < RUNE_OPTIONS_TOTAL; runeOptionCount++){
				Option currentOption = currentRune.getRuneOption(runeOptionCount);
				if(currentOption.getOptionType() == OPTION_NONE){
					continue;
				}
				int currentOptionType = currentOption.getOptionType();
				heroSheet[currentOptionType].modifyValue(currentOption.getOptionValue());
			}
		}

		for(int optionCount = 0; optionCount < GEAR_ENCHANTS_TOTAL; optionCount++){
			Option currentOption = heroGears[it].getEnchant(optionCount);
			if(currentOption.getOptionType() == OPTION_NONE){
				continue;
			}
			int currentOptionType = currentOption.getOptionType();
			heroSheet[currentOptionType].modifyValue(currentOption.getOptionValue());
		}
	}

	// UTs
	for(int it = 0; it < TREASURE_COUNT; it++){
		if(heroTreasures[it].getGearType() == GEAR_NONE) continue;
		if(it == 0) heroFlatSheet[OPTION_HP].modifyValue(heroTreasures[it].getStatBoost());
		for(int optionCount = 0; optionCount < 2; optionCount++){
			Option currentOption = heroTreasures[it].getOption(optionCount);
			if(currentOption.getOptionType() == OPTION_NONE){
				continue;
			}
			int currentOptionType = currentOption.getOptionType();
			heroSheet[currentOptionType].modifyValue(currentOption.getOptionValue());
		}
	}

	// start checking set bonuses
	if(setCount[GEAR_SET_RED] >= 2){
		if(setCount[GEAR_SET_RED] >= 4) heroSheet[OPTION_CRIT].modifyValue(130.0);
		heroSheet[OPTION_CRIT].modifyValue(100.0);
	}
	if(setCount[GEAR_SET_ICE] >= 2){
		if(setCount[GEAR_SET_ICE] >= 4) heroSheet[OPTION_HP].modifyValue(13.0);
		heroSheet[OPTION_HP].modifyValue(10.0);
	}
	if(setCount[GEAR_SET_POISON] >= 2){
		if(setCount[GEAR_SET_POISON] >= 4) heroSheet[OPTION_CRIT_RES].modifyValue(130.0);
		heroSheet[OPTION_CRIT_RES].modifyValue(100.0);
	}
	if(setCount[GEAR_SET_BLACK] >= 2){
		if(setCount[GEAR_SET_BLACK] >= 4) heroSheet[OPTION_MPATK].modifyValue(260.0);
		heroSheet[OPTION_MPATK].modifyValue(200.0);
	}
	if(setCount[GEAR_SET_LAVA] >= 2){
		if(setCount[GEAR_SET_LAVA] >= 4) heroSheet[OPTION_CDMG].modifyValue(26.0);
		heroSheet[OPTION_CDMG].modifyValue(20.0);
	}
	if(setCount[GEAR_SET_LEGEND] >= 2){
		if(setCount[GEAR_SET_LEGEND] >= 4) heroSheet[OPTION_DEBUFF_ACC].modifyValue(130.0);
		heroSheet[OPTION_DEBUFF_ACC].modifyValue(100.0);
	}
	if(setCount[GEAR_SET_SUPPRESS] >= 2){
		if(setCount[GEAR_SET_SUPPRESS] >= 4) ;// DMG dealt to Heroes +13%
		// DMG dealt to Heroes +7%
	}
	if(setCount[GEAR_SET_PROTECT] >= 2){
		if(setCount[GEAR_SET_PROTECT] >= 4) ;// DMG taken from Heroes -11%
		// DMG taken from Heroes -6%
	}
	if(setCount[GEAR_SET_DL] >= 2){
		// DL set realistically targets everyone, but that's for later
		if(setCount[GEAR_SET_DL] >= 4) heroSheet[OPTION_CDMG].modifyValue(8.0);
		heroSheet[OPTION_CDMG].modifyValue(5.0);
	}
	if(setCount[GEAR_SET_MANTI] >= 2){
		if(setCount[GEAR_SET_MANTI] >= 4) ;
	}
	// every set below needs more code to be effectively implemented
	// end checking set bonuses

	// dividing the general defensive lines (DEF, TOUGH, DODGE...) to their specific counterparts
	// and getting the final numbers
	for(int option = OPTION_ATK; option < OPTION_TOTAL; option++){
		if(option == OPTION_ATK || option == OPTION_HP || option == OPTION_PDEF || option == OPTION_MDEF){
			double flatValue = heroFlatSheet[option].getOptionValue();
			double multiplier = heroSheet[option].getOptionValue() / 100.0;
			heroSheet[option].changeValue(std::floor(flatValue * (1.0 + multiplier)));
		}
		else{
			heroSheet[option].modifyValue(heroFlatSheet[option].getOptionValue());
			heroFlatSheet[option].changeValue(heroSheet[option].getOptionValue());
			if(option == OPTION_BLOCK || option == OPTION_CRIT_RES || option == OPTION_DEF || option == OPTION_DODGE || option == OPTION_BLOCK_DEF || option == OPTION_TOUGH){
				double valueToAdd = heroSheet[option].getOptionValue();
				heroSheet[option + 1].modifyValue(valueToAdd); // general defensive +1 always equal phys part
				heroSheet[option + 2].modifyValue(valueToAdd); // general defensive +2 always equal mag part
				heroSheet[option].changeValue(0.0);
				continue;
			}
			heroSheet[option].changeValue(actualStat(option, heroSheet[option].getOptionValue()));
		}
	}
	return;
}