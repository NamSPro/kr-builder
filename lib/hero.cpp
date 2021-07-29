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
    for(int it = GEAR_WEAPON; it < GEAR_TOTAL; it++){
        if(it == GEAR_ARTIFACT || heroGears[it].getGearType() == GEAR_NONE) continue; // again, hardcoded
        if(heroGears[it].getGearType() == GEAR_WEAPON || heroGears[it].getAccessoryType() == ACCESSORY_EARRINGS){
            double currentAtk = heroTempSheet[OPTION_ATK].getOptionValue();
            heroTempSheet[OPTION_ATK].changeValue(currentAtk + heroGears[it].getStatBoost());
        }
        for(int optionCount = 0; optionCount < GEAR_OPTIONS_TOTAL; optionCount++){
            Option currentOption = heroGears[it].getOption(optionCount);
            if(currentOption.getOptionType() == OPTION_NONE){
                continue;
            }
            int currentOptionType = currentOption.getOptionType();
            double currentValue = heroSheet[currentOptionType].getOptionValue();
            heroSheet[currentOptionType].changeValue(currentValue + currentOption.getOptionValue());
        }
    }
    // dividing the general defensive lines (DEF, TOUGH, DODGE...) to their specific counterparts
    // getting the final numbers
    for(int option = OPTION_ATK; option < OPTION_TOTAL; option++){
        // continue if general option or divide here then continue
        if(option == OPTION_ATK || option == OPTION_HP || option == OPTION_PDEF || option == OPTION_MDEF){
            double flatValue = heroTempSheet[option].getOptionValue();
            double multiplier = heroSheet[option].getOptionValue() / 100.0;
            heroSheet[option].changeValue(flatValue * (1.0 + multiplier));
            continue;
        }
		else{
			heroSheet[option].changeValue(actualStat(option, heroSheet[option].getOptionValue()));
		}
    }
    return;
}