// hero.cpp
// This file implements functions declared in hero.h

#include <algorithm>
#include <cstdio>
#include "hero.h"
#include "percentage.h"

Hero::Hero(int heroClass){
	switch (heroClass){
		case CLASS_NONE:{
			break;
		}
		default:{
			*this = Hero(HERO_BASE_TEMPLATES[heroClass]);
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


double Hero::getStat(int option){
	return heroSheet[option].getOptionValue();
}

double Hero::getBaseStat(int option){
	return heroBaseSheet[option].getOptionValue();
}


Hero::Hero(std::map <int, double> options){
	for(auto it = options.begin(); it != options.end(); it++){
		heroBaseSheet[it->first].changeOption(it->first, it->second);
	}
	return;
}

void Hero::updateInfo(){
	Option heroTempSheet[OPTION_TOTAL];
	for(int option = OPTION_ATK; option < OPTION_TOTAL; option++){
		heroTempSheet[option] = heroBaseSheet[option];
		heroSheet[option] = Option();
	}
	// finding the modifiers
	for(int it = GEAR_WEAPON; it < GEAR_TYPE_TOTAL; it++){
		if(it == GEAR_ARTIFACT || heroGears[it].getGearType() == GEAR_NONE) continue; // again, hardcoded

		if(heroGears[it].getGearType() == GEAR_WEAPON || heroGears[it].getAccessoryType() == ACCESSORY_EARRINGS){
			heroTempSheet[OPTION_ATK].modifyValue(heroGears[it].getStatBoost());
		}
		if(heroGears[it].getGearType() == GEAR_ARMOR || heroGears[it].getAccessoryType() == ACCESSORY_BRACELET){
			heroTempSheet[OPTION_PDEF].modifyValue(heroGears[it].getStatBoost());
		}
		if(heroGears[it].getGearType() == GEAR_SECONDARY || heroGears[it].getAccessoryType() == ACCESSORY_NECKLACE){
			heroTempSheet[OPTION_MDEF].modifyValue(heroGears[it].getStatBoost());
		}
		if(heroGears[it].getGearType() == GEAR_ORB || heroGears[it].getAccessoryType() == ACCESSORY_RING){
			heroTempSheet[OPTION_HP].modifyValue(heroGears[it].getStatBoost());
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

	// dividing the general defensive lines (DEF, TOUGH, DODGE...) to their specific counterparts
	// and getting the final numbers
	for(int option = OPTION_ATK; option < OPTION_TOTAL; option++){
		if(option == OPTION_BLOCK || option == OPTION_CRIT_RES || option == OPTION_DEF || option == OPTION_DODGE || option == OPTION_BLOCK_DEF || option == OPTION_TOUGH){
			double valueToAdd = heroSheet[option].getOptionValue();
			heroSheet[option + 1].modifyValue(valueToAdd); // general defensive +1 always equal phys part
			heroSheet[option + 2].modifyValue(valueToAdd); // general defensive +2 always equal mag part
			heroSheet[option].changeValue(0.0);
			continue;
		}
		if(option == OPTION_ATK || option == OPTION_HP || option == OPTION_PDEF || option == OPTION_MDEF){
			double flatValue = heroTempSheet[option].getOptionValue();
			double multiplier = heroSheet[option].getOptionValue() / 100.0;
			heroSheet[option].changeValue(flatValue * (1.0 + multiplier));
		}
		else{
			heroSheet[option].changeValue(actualStat(option, heroSheet[option].getOptionValue()));
		}
	}
	return;
}