// soul_weapon.h
// This file deals with everything SW

// Included is my thoughts on it
// if on 50/50 you have a atk and b hp, of a (x'%)x/y(y'%) distribution,
// you should have 2ax(1+x'%) atk and 2by(1+y'%) hp

#ifndef SOUL_WEAPON_H
#define SOUL_WEAPON_H

#include "4th_dimension.h"

enum SW_CLASS_DIVISION{
	SW_MECHANIC, 
	SW_ASSASSIN,
	SW_KNIGHT,
	SW_TOTAL,
	SW_ARCHER = SW_MECHANIC,
	SW_WIZARD = SW_MECHANIC,
	SW_PRIEST = SW_MECHANIC,
	SW_WARRIOR = SW_ASSASSIN,
};

const int ETHER_LEVELS = 21;
const int CLASS_SW_MAP[HERO_CLASS_TOTAL] = {0, SW_KNIGHT, SW_WARRIOR, SW_ASSASSIN, SW_ARCHER, SW_MECHANIC, SW_WIZARD, SW_PRIEST};
const double SW_ATK[ETHER_LEVELS][SW_TOTAL] = {
	{4500.0, 4000.0, 3500.0}, // ether 0
	{4500.0, 4000.0, 3500.0}, // ether 1
	{4500.0, 4000.0, 3500.0}, // ether 2
	{4500.0, 4000.0, 3500.0}, // ether 3
	{4500.0, 4000.0, 3500.0}, // ether 4
	{4500.0, 4000.0, 3500.0}, // ether 5
	{4500.0, 4000.0, 3500.0}, // ether 6
	{4500.0, 4000.0, 3500.0}, // ether 7
	{4500.0, 4000.0, 3500.0}, // ether 8
	{4500.0, 4000.0, 3500.0}, // ether 9
	{4500.0, 4000.0, 3500.0}, // ether 10
	{4500.0, 4000.0, 3500.0}, // ether 11
	{4500.0, 4000.0, 3500.0}, // ether 12
	{4500.0, 4000.0, 3500.0}, // ether 13
	{4500.0, 4000.0, 3500.0}, // ether 14
	{4500.0, 4000.0, 3500.0}, // ether 15
	{4500.0, 4000.0, 3500.0}, // ether 16
	{4500.0, 4000.0, 3500.0}, // ether 17
	{4500.0, 4000.0, 3500.0}, // ether 18
	{4500.0, 4000.0, 3500.0}, // ether 19
	{32085.0, 28520.0, 24955.0} // ether 20
};
const double SW_HP[ETHER_LEVELS] = {
	125000.0, // ether 0
	125000.0, 125000.0, 125000.0, 125000.0, 125000.0, // ether 1-5
	125000.0, 125000.0, 125000.0, 125000.0, 125000.0, // ether 6-10
	125000.0, 125000.0, 125000.0, 125000.0, 125000.0, // ether 11-15
	125000.0, 125000.0, 125000.0, 125000.0, 891250.0 // ether 16-20
};

class SoulWeapon{
public:
	SoulWeapon();
	~SoulWeapon();

	// setter functions
	void changeActivationStatus();
	void changeAdvLevel(int newLevel);
	void changeEtherLevel(int newEtherLevel);
	void changeAtkRollValue(double newValue); // HP roll is always 100% - this
	void changeAtkBonusValue(double newValue);
	void changeHpBonusValue(double newValue);

	// getter functions
	bool getActivationStatus();
	int getAdvLevel();
	int getEtherLevel();
	double getAtkStat(int heroClass);
	double getHpStat();
	double getAtkRollValue();
	double getHpRollValue();
	double getAtkBonusValue();
	double getHpBonusValue();

private:
	bool activationStatus;
	int advLevel, etherLevel;
	double atkRoll, atkBonus;
	double hpBonus; // ghost variable hpRoll = 100.0 - atkRoll
};

#endif // SOUL_WEAPON_H