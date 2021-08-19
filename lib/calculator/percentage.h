// percentage.h
// This file declares functions used in cap calculations
// Also included are constants related to caps
// Credit to duckness for his implementation (duckness/NotCleo/krmath/krmath.py) that I'm copying off of

#ifndef PERCENTAGE_H
#define PERCENTAGE_H

#include "option.h"

enum CAP_VALUES{
	CAP_2ND_UPPER,
	CAP_1ST_UPPER,
	CAP_2ND_LOWER,
	CAP_1ST_LOWER,
	CAP_TOTAL
};

enum ABSOLUTE_CAP_VALUES{
	CAP_MAX,
	CAP_MIN,
	CAP_ABS_TOTAL
};

const double CAP_GRID[OPTION_TOTAL][CAP_TOTAL] = { // X1 through 4
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{2400.0, 1600.0, -10000.0, 500.0}, // OPTION_SPD
	{2000.0, 1500.0, -500.0, 0.0}, // OPTION_CRIT
	{0.0, 0.0, 0.0, 0.0},
	{2400.0, 1200.0, -500.0, 0.0}, // OPTION_MPATK
	{0.0, 0.0, 0.0, 0.0},
	{1000.0, 450.0, -500.0, 0.0}, // OPTION_PEN
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_LIFESTEAL
	{2000.0, 1500.0, -2.0, 1.0}, // OPTION_ACC
	{900.0, 450.0, -500.0, 0.0}, // OPTION_DEBUFF_ACC
	{0.0, 0.0, 0.0, 0.0},
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_CCRES
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_BLOCK
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_PBLOCK
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_MBLOCK
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_CRIT_RES
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_P_CRIT_RES
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_M_CRIT_RES
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_DODGE
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_PDODGE
	{1000.0, 500.0, -500.0, 0.0}, // OPTION_MDODGE
	{775.0, 225.0, -2.0, -1.0}, // OPTION_BLOCK_DEF
	{775.0, 225.0, -2.0, -1.0}, // OPTION_P_BLOCK_DEF
	{775.0, 225.0, -2.0, -1.0}, // OPTION_M_BLOCK_DEF
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{1000.0, 450.0, -500.0, 0.0}, // OPTION_TOUGH
	{1000.0, 450.0, -500.0, 0.0}, // OPTION_PTOUGH
	{1000.0, 450.0, -500.0, 0.0}, // OPTION_MTOUGH
	{0.0, 0.0, 0.0, 0.0}
};
// sorry duckness, it seems that I've yet to understand what were you doing
const double CAP_ABSOLUTE_GRID[OPTION_TOTAL][CAP_ABS_TOTAL] = { // MaxK and MinK
	{0.0, 0.0},
	{0.0, 0.0},
	{2500.0, 250.0}, // OPTION_SPD
	{2000.0, 0.0}, // OPTION_CRIT
	{0.0, 0.0},
	{2300.0, 0.0}, // OPTION_MPATK
	{0.0, 0.0},
	{900.0, 0.0}, // OPTION_PEN
	{1000.0, 0.0}, // OPTION_LIFESTEAL
	{2000.0, -920.0}, // OPTION_ACC
	{900.0, 0.0}, // OPTION_DEBUFF_ACC
	{0.0, 0.0},
	{1000.0, 0.0}, // OPTION_CCRES
	{1000.0, 0.0}, // OPTION_BLOCK
	{1000.0, 0.0}, // OPTION_PBLOCK
	{1000.0, 0.0}, // OPTION_MBLOCK
	{1000.0, 0.0}, // OPTION_CRIT_RES
	{1000.0, 0.0}, // OPTION_P_CRIT_RES
	{1000.0, 0.0}, // OPTION_M_CRIT_RES
	{0.0, 0.0},
	{0.0, 0.0},
	{0.0, 0.0},
	{1000.0, 0.0}, // OPTION_DODGE
	{1000.0, 0.0}, // OPTION_PDODGE
	{1000.0, 0.0}, // OPTION_MDODGE
	{450.0, -920.0}, // OPTION_BLOCK_DEF
	{450.0, -920.0}, // OPTION_P_BLOCK_DEF
	{450.0, -920.0}, // OPTION_M_BLOCK_DEF
	{0.0, 0.0},
	{0.0, 0.0},
	{900.0, 0.0}, // OPTION_TOUGH
	{900.0, 0.0}, // OPTION_PTOUGH
	{900.0, 0.0}, // OPTION_MTOUGH
	{0.0, 0.0}
};
const double CAP_A_GRID[OPTION_TOTAL][CAP_TOTAL] = { // A1 through 4
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{1.0, 500.0, 0.0, 1.0}, // OPTION_SPD
	{1.0, 500.0, 0.0, 0.0}, // OPTION_CRIT
	{0.0, 0.0, 0.0, 0.0},
	{1.0, 500.0, 0.0, 0.0}, // OPTION_MPATK
	{0.0, 0.0, 0.0, 0.0},
	{2.0, 409.0, 0.0, 0.0}, // OPTION_PEN
	{3.0, 500.0, 0.0, 0.0}, // OPTION_LIFESTEAL
	{1.0, 500.0, 3.0, 0.0}, // OPTION_ACC
	{1000000.0, 1000.0, 0.0, 0.0}, // OPTION_DEBUFF_ACC
	{0.0, 0.0, 0.0, 0.0},
	{1000000.0, 1000.0, 0.0, 0.0}, // OPTION_CCRES
	{3.0, 500.0, 0.0, 0.0}, // OPTION_BLOCK
	{3.0, 500.0, 0.0, 0.0}, // OPTION_PBLOCK
	{3.0, 500.0, 0.0, 0.0}, // OPTION_MBLOCK
	{3.0, 500.0, 0.0, 0.0}, // OPTION_CRIT_RES
	{3.0, 500.0, 0.0, 0.0}, // OPTION_P_CRIT_RES
	{3.0, 500.0, 0.0, 0.0}, // OPTION_M_CRIT_RES
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{3.0, 500.0, 0.0, 0.0}, // OPTION_DODGE
	{3.0, 500.0, 0.0, 0.0}, // OPTION_PDODGE
	{3.0, 500.0, 0.0, 0.0}, // OPTION_MDODGE
	{3.0, 204.0, 3.0, 0.0}, // OPTION_BLOCK_DEF
	{3.0, 204.0, 3.0, 0.0}, // OPTION_P_BLOCK_DEF
	{3.0, 204.0, 3.0, 0.0}, // OPTION_M_BLOCK_DEF
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{2.0, 409.0, 0.0, 0.0}, // OPTION_TOUGH
	{2.0, 409.0, 0.0, 0.0}, // OPTION_PTOUGH
	{2.0, 409.0, 0.0, 0.0}, // OPTION_MTOUGH
	{0.0, 0.0, 0.0, 0.0}
};
const double CAP_B_GRID[OPTION_TOTAL][CAP_TOTAL] = { // B1 through 4
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{-733.0, 800.0, 0.0, -1500.0}, // OPTION_SPD
	{1500.0, 750.0, 0.0, 0.0}, // OPTION_CRIT
	{0.0, 0.0, 0.0, 0.0},
	{-900.0, 600.0, 0.0, 0.0}, // OPTION_MPATK
	{0.0, 0.0, 0.0, 0.0},
	{1000.0, 266.0, 0.0, 0.0}, // OPTION_PEN
	{0.0, 250.0, 0.0, 0.0}, // OPTION_LIFESTEAL
	{1500.0, 750.0, -938.0, 0.0}, // OPTION_ACC
	{1000000.0, 0.0, 0.0, 0.0}, // OPTION_DEBUFF_ACC
	{0.0, 0.0, 0.0, 0.0},
	{1000000.0, 0.0, 0.0, 0.0}, // OPTION_CCRES
	{0.0, 250.0, 0.0, 0.0}, // OPTION_BLOCK
	{0.0, 250.0, 0.0, 0.0}, // OPTION_PBLOCK
	{0.0, 250.0, 0.0, 0.0}, // OPTION_MBLOCK
	{0.0, 250.0, 0.0, 0.0}, // OPTION_CRIT_RES
	{0.0, 250.0, 0.0, 0.0}, // OPTION_P_CRIT_RES
	{0.0, 250.0, 0.0, 0.0}, // OPTION_M_CRIT_RES
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 250.0, 0.0, 0.0}, // OPTION_DODGE
	{0.0, 250.0, 0.0, 0.0}, // OPTION_PDODGE
	{0.0, 250.0, 0.0, 0.0}, // OPTION_MDODGE
	{1500.0, 179.0, -938.0, 0.0}, // OPTION_BLOCK_DEF
	{1500.0, 179.0, -938.0, 0.0}, // OPTION_P_BLOCK_DEF
	{1500.0, 179.0, -938.0, 0.0}, // OPTION_M_BLOCK_DEF
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{1000.0, 266.0, 0.0, 0.0}, // OPTION_TOUGH
	{1000.0, 266.0, 0.0, 0.0}, // OPTION_PTOUGH
	{1000.0, 266.0, 0.0, 0.0}, // OPTION_MTOUGH
	{0.0, 0.0, 0.0, 0.0}
};
const double PERCENTAGE_DIVIDEND = 1000000.0;

double actualStat(int statType, double value);

double attenuate(double x, double k, double a, double b);

double attenuateInverse(double x, double k, double a, double b);

#endif // PERCENTAGE_H