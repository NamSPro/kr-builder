// soul_weapon.cpp
// This file implements functions declared in soul_weapon.h

#include <cmath>
#include "soul_weapon.h"

double powmod(int x){
	if(x == 0) return 1.0;
	if(x == 1) return 2.0;
	if(x == 2) return 4.0;
	return 0.0;
}

SoulWeapon::SoulWeapon(){
	activationStatus = false;
	advLevel = etherLevel = 0;
	atkRoll = 50.0;
	atkBonus = hpBonus = 0.0;
	return;
}

SoulWeapon::~SoulWeapon(){
	return;
}

void SoulWeapon::changeActivationStatus(){
	activationStatus = !activationStatus;
	return;
}

void SoulWeapon::changeAdvLevel(int newLevel){
	advLevel = newLevel;
	return;
}

void SoulWeapon::changeEtherLevel(int newEtherLevel){
	etherLevel = newEtherLevel;
	return;
}

void SoulWeapon::changeAtkRollValue(double newValue){
	atkRoll = newValue;
	return;
}

void SoulWeapon::changeAtkBonusValue(double newValue){
	atkBonus = newValue;
	return;
}

void SoulWeapon::changeHpBonusValue(double newValue){
	hpBonus = newValue;
	return;
}

bool SoulWeapon::getActivationStatus(){
	return activationStatus;
}

int SoulWeapon::getAdvLevel(){
	return advLevel;
}

int SoulWeapon::getEtherLevel(){
	return etherLevel;
}

double SoulWeapon::getAtkStat(int heroClass){
	int unrounded = std::round(2.0 * SW_ATK[etherLevel][CLASS_SW_MAP[heroClass]] * powmod(advLevel) * (atkRoll / 100.0)) * (1.0 + atkBonus / 100.0);
	return std::floor(unrounded);
}

double SoulWeapon::getHpStat(){
	return std::round(2.0 * SW_HP[etherLevel] * powmod(advLevel) * ((100.0 - atkRoll) / 100.0)) * (1.0 + hpBonus / 100.0);
}

double SoulWeapon::getAtkRollValue(){
	return atkRoll;
}

double SoulWeapon::getHpRollValue(){
	return 100.0 - getAtkRollValue();
}

double SoulWeapon::getAtkBonusValue(){
	return atkBonus;
}

double SoulWeapon::getHpBonusValue(){
	return hpBonus;
}