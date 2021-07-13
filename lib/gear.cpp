// gear.cpp
// This file implements functions declared in gear.h

#include <cstdio>
#include "gear.h"

Gear::Gear(){
    gearType = GEAR_NONE;
    accessoryType = ACCESSORY_NONE;
    gearCondition = GEAR_UNTIERED;
    isReclaimed = false;
    starLevel = STAR_0STAR;
    return;
}

Gear::~Gear(){
    return;
}

bool Gear::changeOption(int position, Option newOption){
    if((gearCondition == GEAR_TM || gearType == GEAR_TREASURE) && position > 1){
        printf("Invalid option to be changed!\n");
        return false;
    }
    if(gearCondition == GEAR_UNIQUE && (gearType == GEAR_WEAPON || gearType == GEAR_ARTIFACT)){
        printf("UWs and artifacts cannot have additional options!\n");
        return false;
    }
    gearOptions[position] = newOption;
    return true;
};

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