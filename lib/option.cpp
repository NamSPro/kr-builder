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

void Option::changeOption(int newType, double newValue){
    optionType = newType;
    optionValue = newValue;
    return;
}

void Option::changeValue(double newValue){
    optionValue = newValue;
    return;
}

int Option::getOptionType(){
    return optionType;
}

double Option::getOptionValue(){
    return optionValue;
}

Rune::Rune(Option option1, bool isitVelk, Option option2){
    runeOptions[RUNE_NORMAL] = option1;
    isVelk = isitVelk;
    if(isVelk) runeOptions[RUNE_VELK] = option2;
    return;
}

Rune::~Rune(){
    return;
}