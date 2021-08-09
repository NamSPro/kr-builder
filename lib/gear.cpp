// gear.cpp
// This file implements functions declared in gear.h

#include <cstdio>
#include "gear.h"

Gear::Gear(){
	gearType = GEAR_NONE;
	accessoryType = ACCESSORY_NONE;
	gearCondition = GEAR_UNTIERED;
	starLevel = STAR_0STAR;
	statBoost = 100; // hardcoded for testing
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

int Gear::getGearType(){
	return gearType;
}

int Gear::getAccessoryType(){
	return accessoryType;
}

int Gear::getStatBoost(){
	return statBoost;
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