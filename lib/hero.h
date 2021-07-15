// hero.h
// This file declares the Hero class, the one that actually gets displayed
// Also included is a bunch of template for different classes

#ifndef HERO_H
#define HERO_H

#include <map>
#include "gear.h"

// HERO_CLASS enum
enum HERO_CLASS{
    CLASS_NONE,
    CLASS_KNIGHT,
    CLASS_WARRIOR,
    CLASS_ARCHER,
    CLASS_ASSASSIN,
    CLASS_MECHANIC,
    CLASS_WIZARD,
    CLASS_PRIEST,
    CLASS_TOTAL
};

const std::map <int, double> HERO_BASE_TEMPLATES[CLASS_TOTAL] = {
    {},
    {{OPTION_HP, 1706672.0}, {OPTION_ATK, 19792.0}, {OPTION_PDEF, 8792.0}, {OPTION_MDEF, 6840.0}},
    {{OPTION_HP, 1449520.0}, {OPTION_ATK, 22488.0}, {OPTION_PDEF, 7328.0}, {OPTION_MDEF, 8792.0}},
    {{OPTION_HP, 1066728.0}, {OPTION_ATK, 27864.0}, {OPTION_PDEF, 5376.0}, {OPTION_MDEF, 4392.0}},
    {{OPTION_HP, 1384992.0}, {OPTION_ATK, 24688.0}, {OPTION_PDEF, 7816.0}, {OPTION_MDEF, 6840.0}},
    {{OPTION_HP, 1157176.0}, {OPTION_ATK, 25416.0}, {OPTION_PDEF, 5376.0}, {OPTION_MDEF, 4392.0}},
    {{OPTION_HP, 985328.0}, {OPTION_ATK, 29328.0}, {OPTION_PDEF, 3904.0}, {OPTION_MDEF, 5864.0}},
    {{OPTION_HP, 1104864.0}, {OPTION_ATK, 23216.0}, {OPTION_PDEF, 4888.0}, {OPTION_MDEF, 6104.0}}
};

class Hero{
public:
    Hero(int heroClass = CLASS_NONE);
    Hero(std::map <int, double> options);
    ~Hero();
    // entire piece update and point update 
    bool changeGear(int position, Gear newGear);
    bool changeGearOption(int position, int optionPosition, Option newOption);
    bool changeGearOption(int position, int optionPosition, int newOption, double newValue);
    // bool updateGearRune(int position, int runePosition, Rune newRune);
    // bool updateGearEnchant(int position, int enchantPosition, Option newOption);
    // called whenever an update takes place
    void updateInfo();
    // getter functions
    double getStat(int option);
    double getBaseStat(int option);
private:
    Gear heroGears[GEAR_TOTAL];
    Option heroSheet[OPTION_TOTAL];
    Option heroBaseSheet[OPTION_TOTAL];
};

#endif // HERO_H