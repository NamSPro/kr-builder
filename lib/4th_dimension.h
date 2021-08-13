// 4th_dimension.h (tentative name)
// This file includes the flat stats of gears

#ifndef FOURTH_DIMENSION_H
#define FOURTH_DIMENSION_H

// gear enums
// GEAR_TYPE denotes position, ACCESSORY_TYPE denotes accessory type, and GEAR_CONDITION denotes tier
enum GEAR_TYPE{
	GEAR_NONE,
	GEAR_WEAPON,
	GEAR_ARMOR,
	GEAR_SECONDARY,
	GEAR_ORB,
	GEAR_ACCESSORY,
	GEAR_TREASURE,
	GEAR_ARTIFACT,
	GEAR_TYPE_TOTAL
};

enum ACCESSORY_TYPE{
	ACCESSORY_NONE,
	ACCESSORY_EARRINGS,
	ACCESSORY_BRACELET,
	ACCESSORY_RING,
	ACCESSORY_TOTAL,
	ACCESSORY_NECKLACE = 2
};

enum GEAR_CONDITION{
	GEAR_UNTIERED,
	GEAR_TIER6,
	GEAR_TIER7,
	GEAR_TIER8,
	GEAR_TM,
	GEAR_TM_RECLAIMED,
	GEAR_UNIQUE,
	GEAR_CONDITION_TOTAL
};

// STAR_LEVEL enum
enum STAR_LEVEL{
	STAR_0STAR,
	STAR_1STAR,
	STAR_2STAR,
	STAR_3STAR,
	STAR_4STAR,
	STAR_5STAR,
	GEAR_STAR_TOTAL
};

// HERO_CLASS enum
enum HERO_CLASS{
	CLASS_NONE,
	CLASS_KNIGHT,
	CLASS_WARRIOR,
	CLASS_ASSASSIN,
	CLASS_ARCHER,
	CLASS_MECHANIC,
	CLASS_WIZARD,
	CLASS_PRIEST,
	HERO_CLASS_TOTAL
};

const double UW_STATS[HERO_CLASS_TOTAL][GEAR_STAR_TOTAL] = {
	{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // CLASS_NONE
	{45106.0, 49616.0, 58637.0, 72169.0, 90210.0, 112763.0}, // CLASS_KNIGHT
	{51120.0, 56231.0, 66456.0, 81791.0, 102238.0, 127798.0}, // CLASS_WARRIOR
	{56209.0, 61829.0, 73071.0, 89933.0, 112416.0, 140520.0}, // CLASS_ASSASSIN
	{63264.0, 69589.0, 82243.0, 101221.0, 126526.0, 158157.0}, // CLASS_ARCHER
	{57712.0, 63483.0, 75026.0, 92339.0, 115423.0, 144278.0}, // CLASS_MECHANIC
	{58985.0, 64882.0, 76680.0, 94374.0, 117967.0, 147459.0}, // CLASS_WIZARD
	{58985.0, 64882.0, 76680.0, 94374.0, 117967.0, 147459.0} // CLASS_PRIEST
};
const double UT_STATS[GEAR_STAR_TOTAL] = {1596066.0, 1755649.0, 2074871.0, 2553676.0, 3192064.0, 3990076.0};

// orbs have the same stats as ring accessory
const double GEAR_BASE_STATS[GEAR_CONDITION_TOTAL - 1][HERO_CLASS_TOTAL][GEAR_TYPE_TOTAL - 3][GEAR_STAR_TOTAL] = {
	// fuckkkkkkkkkkkkkkkkkkkkkk
	{ // GEAR_UNTIERED
		{ // CLASS_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_KNIGHT
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_WARRIOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_ASSASSIN
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_ARCHER
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_MECHANIC
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_WIZARD
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_PRIEST
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		}
	},
	{ // GEAR_TIER6
		{ // CLASS_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_KNIGHT
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{13756.0, 15132.0, 16508.0, 17883.0, 19259.0, 20635.0}, // GEAR_WEAPON
			{9148.0, 10063.0, 11436.0, 13265.0, 15552.0, 18297.0}, // GEAR_ARMOR
			{9148.0, 10063.0, 11436.0, 13265.0, 15552.0, 18297.0} // GEAR_SECONDARY
		},
		{ // CLASS_WARRIOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{15584.0, 17142.0, 18700.0, 20259.0, 21817.0, 23376.0}, // GEAR_WEAPON
			{9148.0, 10063.0, 11436.0, 13265.0, 15552.0, 18297.0}, // GEAR_ARMOR
			{9148.0, 10063.0, 11436.0, 13265.0, 15552.0, 18297.0} // GEAR_SECONDARY
		},
		{ // CLASS_ASSASSIN
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{17116.0, 18828.0, 20540.0, 22251.0, 23963.0, 25675.0}, // GEAR_WEAPON
			{6099.0, 6709.0, 7624.0, 8843.0, 10368.0, 12198.0}, // GEAR_ARMOR
			{3052.0, 3358.0, 3816.0, 4426.0, 5189.0, 6105.0} // GEAR_SECONDARY
		},
		{ // CLASS_ARCHER
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{19318.0, 21250.0, 23182.0, 25113.0, 27045.0, 28977.0}, // GEAR_WEAPON
			{6099.0, 6709.0, 7624.0, 8843.0, 10368.0, 12198.0}, // GEAR_ARMOR
			{3052.0, 3358.0, 3816.0, 4426.0, 5189.0, 6105.0} // GEAR_SECONDARY
		},
		{ // CLASS_MECHANIC
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{17619.0, 19381.0, 21143.0, 22904.0, 24666.0, 26428.0}, // GEAR_WEAPON
			{6099.0, 6709.0, 7624.0, 8843.0, 10368.0, 12198.0}, // GEAR_ARMOR
			{3052.0, 3358.0, 3816.0, 4426.0, 5189.0, 6105.0} // GEAR_SECONDARY
		},
		{ // CLASS_WIZARD
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{17961.0, 19757.0, 21553.0, 23350.0, 25146.0, 26942.0}, // GEAR_WEAPON
			{3052.0, 3358.0, 3816.0, 4426.0, 5189.0, 6105.0}, // GEAR_ARMOR
			{6099.0, 6709.0, 7624.0, 8843.0, 10368.0, 12198.0} // GEAR_SECONDARY
		},
		{ // CLASS_PRIEST
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{17961.0, 19757.0, 21553.0, 23350.0, 25146.0, 26942.0}, // GEAR_WEAPON
			{3052.0, 3358.0, 3816.0, 4426.0, 5189.0, 6105.0}, // GEAR_ARMOR
			{6099.0, 6709.0, 7624.0, 8843.0, 10368.0, 12198.0} // GEAR_SECONDARY
		}
	},
	{ // GEAR_TIER7
		{ // CLASS_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_KNIGHT
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{20480.0, 22528.0, 24576.0, 26624.0, 28672.0, 30720.0}, // GEAR_WEAPON
			{13625.0, 14988.0, 17032.0, 19757.0, 23163.0, 27251.0}, // GEAR_ARMOR
			{13625.0, 14988.0, 17032.0, 19757.0, 23163.0, 27251.0} // GEAR_SECONDARY
		},
		{ // CLASS_WARRIOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{23216.0, 25537.0, 27859.0, 30180.0, 32502.0, 34824.0}, // GEAR_WEAPON
			{13625.0, 14988.0, 17032.0, 19757.0, 23163.0, 27251.0}, // GEAR_ARMOR
			{13625.0, 14988.0, 17032.0, 19757.0, 23163.0, 27251.0} // GEAR_SECONDARY
		},
		{ // CLASS_ASSASSIN
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{25478.0, 28026.0, 30574.0, 33121.0, 35669.0, 38217.0}, // GEAR_WEAPON
			{9091.0, 10000.0, 11364.0, 13182.0, 15455.0, 18182.0}, // GEAR_ARMOR
			{4547.0, 5001.0, 5684.0, 6593.0, 7730.0, 9094.0} // GEAR_SECONDARY
		},
		{ // CLASS_ARCHER
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{28758.0, 31634.0, 34510.0, 37385.0, 40261.0, 43137.0}, // GEAR_WEAPON
			{9091.0, 10000.0, 11364.0, 13182.0, 15455.0, 18182.0}, // GEAR_ARMOR
			{4547.0, 5001.0, 5684.0, 6593.0, 7730.0, 9094.0} // GEAR_SECONDARY
		},
		{ // CLASS_MECHANIC
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{26240.0, 28864.0, 31488.0, 34112.0, 36736.0, 39360.0}, // GEAR_WEAPON
			{9091.0, 10000.0, 11364.0, 13182.0, 15455.0, 18182.0}, // GEAR_ARMOR
			{4547.0, 5001.0, 5684.0, 6593.0, 7730.0, 9094.0} // GEAR_SECONDARY
		},
		{ // CLASS_WIZARD
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{26739.0, 29413.0, 32087.0, 34760.0, 37434.0, 40108.0}, // GEAR_WEAPON
			{4547.0, 5001.0, 5684.0, 6593.0, 7730.0, 9094.0}, // GEAR_ARMOR
			{9091.0, 10000.0, 11364.0, 13182.0, 15455.0, 18182.0} // GEAR_SECONDARY
		},
		{ // CLASS_PRIEST
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{26739.0, 29413.0, 32087.0, 34760.0, 37434.0, 40108.0}, // GEAR_WEAPON
			{4547.0, 5001.0, 5684.0, 6593.0, 7730.0, 9094.0}, // GEAR_ARMOR
			{9091.0, 10000.0, 11364.0, 13182.0, 15455.0, 18182.0} // GEAR_SECONDARY
		}
	},
	{ // GEAR_TIER8
		{ // CLASS_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_KNIGHT
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{25580.0, 28138.0, 30696.0, 33255.0, 35813.0, 38371.0}, // GEAR_WEAPON
			{17052.0, 18758.0, 21316.0, 24726.0, 28989.0, 34105.0}, // GEAR_ARMOR
			{17052.0, 18758.0, 21316.0, 24726.0, 28989.0, 34105.0} // GEAR_SECONDARY
		},
		{ // CLASS_WARRIOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{29059.0, 31965.0, 34871.0, 37776.0, 40682.0, 43588.0}, // GEAR_WEAPON
			{17052.0, 18758.0, 21316.0, 24726.0, 28989.0, 34105.0}, // GEAR_ARMOR
			{17052.0, 18758.0, 21316.0, 24726.0, 28989.0, 34105.0} // GEAR_SECONDARY
		},
		{ // CLASS_ASSASSIN
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{31900.0, 35090.0, 38280.0, 41471.0, 44661.0, 47851.0}, // GEAR_WEAPON
			{11369.0, 12506.0, 14212.0, 16485.0, 19328.0, 22739.0}, // GEAR_ARMOR
			{5686.0, 6255.0, 7108.0, 8245.0, 9666.0, 11372.0} // GEAR_SECONDARY
		},
		{ // CLASS_ARCHER
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{36006.0, 39607.0, 43207.0, 46808.0, 50408.0, 54009.0}, // GEAR_WEAPON
			{11369.0, 12506.0, 14212.0, 16485.0, 19328.0, 22739.0}, // GEAR_ARMOR
			{5686.0, 6255.0, 7108.0, 8245.0, 9666.0, 11372.0} // GEAR_SECONDARY
		},
		{ // CLASS_MECHANIC
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{32851.0, 36136.0, 39421.0, 42706.0, 45991.0, 49276.0}, // GEAR_WEAPON
			{11369.0, 12506.0, 14212.0, 16485.0, 19328.0, 22739.0}, // GEAR_ARMOR
			{5686.0, 6255.0, 7108.0, 8245.0, 9666.0, 11372.0} // GEAR_SECONDARY
		},
		{ // CLASS_WIZARD
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{33478.0, 36826.0, 40174.0, 43521.0, 46869.0, 50217.0}, // GEAR_WEAPON
			{5686.0, 6255.0, 7108.0, 8245.0, 9666.0, 11372.0}, // GEAR_ARMOR
			{11369.0, 12506.0, 14212.0, 16485.0, 19328.0, 22739.0} // GEAR_SECONDARY
		},
		{ // CLASS_PRIEST
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{33478.0, 36826.0, 40174.0, 43521.0, 46869.0, 50217.0}, // GEAR_WEAPON
			{5686.0, 6255.0, 7108.0, 8245.0, 9666.0, 11372.0}, // GEAR_ARMOR
			{11369.0, 12506.0, 14212.0, 16485.0, 19328.0, 22739.0} // GEAR_SECONDARY
		}
	},
	{ // GEAR_TM
		{ // CLASS_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_KNIGHT
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{40928.0, 42974.0, 45020.0, 47067.0, 49113.0, 51160.0}, // GEAR_ARMOR
			{40928.0, 42974.0, 45020.0, 47067.0, 49113.0, 51160.0} // GEAR_SECONDARY
		},
		{ // CLASS_WARRIOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{40928.0, 42974.0, 45020.0, 47067.0, 49113.0, 51160.0}, // GEAR_ARMOR
			{40928.0, 42974.0, 45020.0, 47067.0, 49113.0, 51160.0} // GEAR_SECONDARY
		},
		{ // CLASS_ASSASSIN
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{27283.0, 28647.0, 30011.0, 31375.0, 32739.0, 34104.0}, // GEAR_ARMOR
			{13644.0, 14327.0, 15009.0, 15691.0, 16373.0, 17056.0} // GEAR_SECONDARY
		},
		{ // CLASS_ARCHER
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{27283.0, 28647.0, 30011.0, 31375.0, 32739.0, 34104.0}, // GEAR_ARMOR
			{13644.0, 14327.0, 15009.0, 15691.0, 16373.0, 17056.0} // GEAR_SECONDARY
		},
		{ // CLASS_MECHANIC
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{27283.0, 28647.0, 30011.0, 31375.0, 32739.0, 34104.0}, // GEAR_ARMOR
			{13644.0, 14327.0, 15009.0, 15691.0, 16373.0, 17056.0} // GEAR_SECONDARY
		},
		{ // CLASS_WIZARD
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{13644.0, 14327.0, 15009.0, 15691.0, 16373.0, 17056.0}, // GEAR_ARMOR
			{27283.0, 28647.0, 30011.0, 31375.0, 32739.0, 34104.0} // GEAR_SECONDARY
		},
		{ // CLASS_PRIEST
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{13644.0, 14327.0, 15009.0, 15691.0, 16373.0, 17056.0}, // GEAR_ARMOR
			{27283.0, 28647.0, 30011.0, 31375.0, 32739.0, 34104.0} // GEAR_SECONDARY
		}
	},
	{ // GEAR_TM_RECLAIMED
		{ // CLASS_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_ARMOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // GEAR_SECONDARY
		},
		{ // CLASS_KNIGHT
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{53718.0, 56403.0, 59089.0, 61775.0, 64461.0, 67147.0}, // GEAR_ARMOR
			{53718.0, 56403.0, 59089.0, 61775.0, 64461.0, 67147.0} // GEAR_SECONDARY
		},
		{ // CLASS_WARRIOR
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{53718.0, 56403.0, 59089.0, 61775.0, 64461.0, 67147.0}, // GEAR_ARMOR
			{53718.0, 56403.0, 59089.0, 61775.0, 64461.0, 67147.0} // GEAR_SECONDARY
		},
		{ // CLASS_ASSASSIN
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{35809.0, 37599.0, 39390.0, 41180.0, 42971.0, 44761.0}, // GEAR_ARMOR
			{17908.0, 18804.0, 19699.0, 20595.0, 21490.0, 22386.0} // GEAR_SECONDARY
		},
		{ // CLASS_ARCHER
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{35809.0, 37599.0, 39390.0, 41180.0, 42971.0, 44761.0}, // GEAR_ARMOR
			{17908.0, 18804.0, 19699.0, 20595.0, 21490.0, 22386.0} // GEAR_SECONDARY
		},
		{ // CLASS_MECHANIC
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{35809.0, 37599.0, 39390.0, 41180.0, 42971.0, 44761.0}, // GEAR_ARMOR
			{17908.0, 18804.0, 19699.0, 20595.0, 21490.0, 22386.0} // GEAR_SECONDARY
		},
		{ // CLASS_WIZARD
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{17908.0, 18804.0, 19699.0, 20595.0, 21490.0, 22386.0}, // GEAR_ARMOR
			{35809.0, 37599.0, 39390.0, 41180.0, 42971.0, 44761.0} // GEAR_SECONDARY
		},
		{ // CLASS_PRIEST
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_NONE
			{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // GEAR_WEAPON
			{17908.0, 18804.0, 19699.0, 20595.0, 21490.0, 22386.0}, // GEAR_ARMOR
			{35809.0, 37599.0, 39390.0, 41180.0, 42971.0, 44761.0} // GEAR_SECONDARY
		}
	}
};

// bracelet = necklace
const double GEAR_ACCESSORY_STATS[GEAR_CONDITION_TOTAL][ACCESSORY_TOTAL][GEAR_STAR_TOTAL] = {
	{ // GEAR_UNTIERED
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // ACCESSORY_NONE
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // ACCESSORY_EARRINGS
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // ACCESSORY_BRACELET/NECKLACE
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0} // ACCESSORY_RING/GEAR_ORB
	},
	{ // GEAR_TIER6
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // ACCESSORY_NONE
		{8860.0, 9746.0, 10632.0, 11519.0, 12405.0, 13291.0}, // ACCESSORY_EARRINGS
		{6377.0, 7015.0, 7972.0, 9247.0, 10841.0, 12755.0}, // ACCESSORY_BRACELET/NECKLACE
		{281113.0, 309224.0, 337336.0, 365447.0, 393559.0, 421670.0} // ACCESSORY_RING/GEAR_ORB
	},
	{ // GEAR_TIER7
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // ACCESSORY_NONE
		{12617.0, 13879.0, 15141.0, 16402.0, 17664.0, 18926.0}, // ACCESSORY_EARRINGS
		{9091.0, 10000.0, 11364.0, 13182.0, 15455.0, 18182.0}, // ACCESSORY_BRACELET/NECKLACE
		{580102.0, 638112.0, 696122.0, 754133.0, 812143.0, 870153.0} // ACCESSORY_RING/GEAR_ORB
	},
	{ // GEAR_TIER8
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // ACCESSORY_NONE
		{15801.0, 17381.0, 18961.0, 20542.0, 22122.0, 23702.0}, // ACCESSORY_EARRINGS
		{11369.0, 12506.0, 14212.0, 16485.0, 19328.0, 22739.0}, // ACCESSORY_BRACELET/NECKLACE
		{726278.0, 798906.0, 871534.0, 944161.0, 1016789.0, 1089417.0} // ACCESSORY_RING/GEAR_ORB
	},
	{ // GEAR_TM
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // ACCESSORY_NONE
		{28440.0, 29862.0, 31284.0, 32706.0, 34128.0, 35550.0}, // ACCESSORY_EARRINGS
		{27283.0, 28647.0, 30011.0, 31375.0, 32739.0, 34104.0}, // ACCESSORY_BRACELET/NECKLACE
		{1307299.0, 1372664.0, 1438029.0, 1503394.0, 1568759.0, 1634124.0} // ACCESSORY_RING/GEAR_ORB
	},
	{ // GEAR_TM_RECLAIMED
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // ACCESSORY_NONE
		{37327.0, 39193.0, 41060.0, 42926.0, 44793.0, 46659.0}, // ACCESSORY_EARRINGS
		{35809.0, 37599.0, 39390.0, 41180.0, 42971.0, 44761.0}, // ACCESSORY_BRACELET/NECKLACE
		{1715830.0, 1801621.0, 1887413.0, 1973204.0, 2058996.0, 2144787.0} // ACCESSORY_RING/GEAR_ORB
	}
};

#endif // FOURTH_DIMENSION_H