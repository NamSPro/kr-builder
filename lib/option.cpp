// option.cpp
// This file implements functions declared in option.h

#include "option.h"

Option::Option(int type, double value){
    optionType = type;
    optionValue = value;
    return;
}

Option::~Option(){
    return;
}

void Option::optionChange(int newType, double newValue){
    optionType = newType;
    optionValue = newValue;
    return;
}

Rune::Rune(Option option1, bool isitVelk, Option option2){
    runeOptions[RUNE_NORMAL] = option1;
    isVelk = isitVelk;
    if(isVelk) runeOptions[RUNE_VELK] = option2;
}

Rune::~Rune(){
    return;
}