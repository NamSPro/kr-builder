// gear.cpp
// This file implements functions declared in gear.h

#include <cstdio>
#include "gear.h"

Gear::Gear(int heroClass){
	equippableClass = heroClass;
	gearType = GEAR_NONE;
	accessoryType = ACCESSORY_NONE;
	gearCondition = GEAR_UNTIERED;
	starLevel = STAR_0STAR;
	return;
}

Gear::~Gear(){
	return;
}

void Gear::changeGearType(int newType, int newAccessoryType){
	gearType = newType;
	accessoryType = newAccessoryType;
	return;
}

void Gear::changeAccessoryType(int newAccessoryType){
	changeGearType(GEAR_ACCESSORY, newAccessoryType);
	return;
}

void Gear::changeGearCondition(int newCondition){
	gearCondition = newCondition;
	return;
}

void Gear::changeStarLevel(int newStarLevel){
	starLevel = newStarLevel;
	return;
}

bool Gear::changeOption(int position, Option newOption){
	if((gearCondition == GEAR_TM || gearType == GEAR_TREASURE) && position > 1){
		printf("Invalid option number to be changed!\n");
		return false;
	}
	if(gearCondition == GEAR_UNIQUE && (gearType == GEAR_WEAPON || gearType == GEAR_ARTIFACT)){
		printf("UWs and artifacts cannot have additional options!\n");
		return false;
		}
	gearOptions[position] = newOption;
	return true;
}

bool Gear::changeOption(int position, int newOption, double newValue){
	return changeOption(position, Option(newOption, newValue));
};

bool Gear::changeOptionValue(int position, double newValue){
	return changeOption(position, gearOptions[position].getOptionType(), newValue);
}

bool Gear::changeRune(int position, Rune newRune){
	if(gearType != GEAR_WEAPON && gearType != GEAR_ARMOR && gearType != GEAR_SECONDARY){
		printf("Gears on the right cannot have runes!\n");
		return false;
	}
	if(gearCondition != GEAR_UNIQUE && position > 0){
		printf("Non-UWs cant have more than one rune!\n");
		return false;
	}
	gearRunes[position] = newRune;
	return true;
}

bool Gear::changeEnchant(int position, Option newOption){
	if(gearCondition == GEAR_UNIQUE){
		printf("Unique gears cannot have enchants!\n");
		return false;
	}
	if(gearCondition != GEAR_TM && position > 0){
		printf("Normal gears cannot have more than one enchant option!\n");
		return false;
	}
	gearEnchants[position] = newOption;
	return true;
}

bool Gear::changeEnchant(int position, int newOption, double newValue){
	return changeEnchant(position, Option(newOption, newValue));
}

bool Gear::changeEnchantValue(int position, double newValue){
	return changeEnchant(position, gearEnchants[position].getOptionType(), newValue);
}

void Gear::changeSoulActivationStatus(){
	uwSoul.changeActivationStatus();
	return;
}

void Gear::changeSoulAdvLevel(int newLevel){
	uwSoul.changeAdvLevel(newLevel);
	return;
}

void Gear::changeSoulEtherLevel(int newEtherLevel){
	uwSoul.changeEtherLevel(newEtherLevel);
	return;
}

void Gear::changeSoulAtkRollValue(double newValue){
	uwSoul.changeAtkRollValue(newValue);
	return;
}

void Gear::changeSoulAtkBonusValue(double newValue){
	uwSoul.changeAtkBonusValue(newValue);
	return;
}

void Gear::changeSoulHpBonusValue(double newValue){
	uwSoul.changeHpBonusValue(newValue);
}

int Gear::getGearType(){
	return gearType;
}

int Gear::getAccessoryType(){
	return accessoryType;
}

double Gear::getStatBoost(){
	if(gearCondition == GEAR_UNIQUE){
		if(gearType == GEAR_WEAPON) return UW_STATS[equippableClass][starLevel];
		else return UT_STATS[starLevel];
	}
	if(gearType == GEAR_ACCESSORY){
		return GEAR_ACCESSORY_STATS[gearCondition][accessoryType][starLevel];
	}
	if(gearType == GEAR_ORB){
		return GEAR_ACCESSORY_STATS[gearCondition][ACCESSORY_RING][starLevel];
	}
	return GEAR_BASE_STATS[gearCondition][equippableClass][gearType][starLevel];
}

int Gear::getCondition(){
	return gearCondition;
}

int Gear::getStarLevel(){
	return starLevel;
}

Option Gear::getOption(int position){
	return gearOptions[position];
}

Rune Gear::getRune(int position){
	return gearRunes[position];
}

Option Gear::getEnchant(int position){
	return gearEnchants[position];
}

bool Gear::getSoulActivationStatus(){
	return uwSoul.getActivationStatus();
}

int Gear::getSoulAdvLevel(){
	return uwSoul.getAdvLevel();
}

int Gear::getSoulEtherLevel(){
	return uwSoul.getEtherLevel();
}

double Gear::getSoulAtkStat(){
	return uwSoul.getAtkStat(equippableClass);
}

double Gear::getSoulHpStat(){
	return uwSoul.getHpStat();
}

double Gear::getSoulAtkRollValue(){
	return uwSoul.getAtkRollValue();
}

double Gear::getSoulHpRollValue(){
	return uwSoul.getHpRollValue();
}

double Gear::getSoulAtkBonusValue(){
	return uwSoul.getAtkBonusValue();
}

double Gear::getSoulHpBonusValue(){
	return uwSoul.getHpBonusValue();
}