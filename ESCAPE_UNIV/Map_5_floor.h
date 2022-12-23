#include"Quize_Tool.hpp"

using namespace std;
vector<vector<int>>Map5={
{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	99,	99,	99,	99,	255,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	254,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	304,430,99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	304,430,99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99},
{99,	99,	99,	99,	99,	251,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,0,	0,	0,	99,	252,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	553,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	220,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	360,560,99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99},
{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0}
};	


vector<vector<int>>Box_Quiz_Map5_1 = {
{99,	99,	250,250,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	100,0,	100,0,	0,	0,	0,	0,	0,	100,0,	100,0,	100,100,0,	100,0,	0,	0,	100,0,	100,0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	100,0,	0,	0,	100,100,0,	0,	0,	0,	0,	0,	0,	100,0,	100,0,	100,0,	0,	0,	0,	0,	0,	100,0,	100,0,	100,100,0,	100,0,	0,	0,	100,0,	100,0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,100,	0,	0,100,	100,0,	100,0,	0,	0,	0,	0,	0,	100,100,100,0,	100,100,0,	100,0,	100,0,	0,	0,	100,0,	100,0,	0,	0,	100,99},
{99,	0,	0,	0,	0,	0,	100,0,	0,	100,0,	0,	0,	0,	100,0,	100,0,	100,0,	100,0,	0,	0,	0,	0,	0,	100,0,	100,0,	100,100,0,	100,0,	0,	0,	100,0,	100,0,	0,	0,	0,	99},
{99,	0,	0,	0,	100,0,	0,	0,	100,0,	100,0,	0,	0,	100,0,	100,100,100,0,	100,0,	0,	0,	0,	0,	0,	100,100,100,0,	0,	100,100,100,0,	0,	0,	100,100,0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	100,0,	0,	100,0,	0,	0,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	100,0,	0,	0,	100,0,	0,	100,0,	0,	0,	0,	0,	0,	100,0,	0,	100,0,	0,	0,	100,100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	100,0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	100,0,	0,	0,	0,	100,0,	100,0,	0,	0,	100,0,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	99},
{99,	0,	0,	0,	100,0,	0,	0,	100,0,	0,	100,0,	0,	0,	0,	0,	100,100,100,100,0,	0,	100,0,	0,	100,0,	0,	100,0,	100,0,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	100,0,	99},
{99,	0,	0,	100,0,	0,	100,100,100,0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	0,	100,0,	100,0,	100,0,	0,	100,0,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	100,100,0,	100,0,	100,0,	0,	0,	100,0,	100,0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	100,0,	0,	0,	0,	100,0,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	100,0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	0,	100,0,	0,	100,0,	0,	0,	0,	100,0,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	100,99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	0,	0,	100,0,	0,	0,	0,	100,0,	0,	0,	0,	0,	100,0,	0,	0,	100,0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	0,	100,0,	0,	100,0,	0,	0,	0,	100,0,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	100,100,100,0,	0,	100,0,	0,	0,	0,	100,0,	0,	0,	0,	0,	100,0,	0,	0,	100,100,99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	114,0,	100,0,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	99},
{99,	99,99, 99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99}
};

vector<vector<int>>Map5_2_Upper={
{99,	250,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},	
{99,	0,	0,	0,	0,	0,	0,	0,	0,	118,	99,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	99},	
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	99},	
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},	
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},	
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},	
{99,	0,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},	
{99,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},	
{99,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},	
{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},	
};

vector<vector<int>>Map5_2_Bottom={
{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},	
{99,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},	
{99,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},	
{99,	0,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},	
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},	
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	115,0,	0,	0,	99},	
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},	
{99,	220,99,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	99},
{99,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	99},
{99,	550,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
};

vector<vector<int>>Map5_3={
{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,				99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	101,99,	99,	0,	99,	99,0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99},
{99,	0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99,	99,	100,99,	99,0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99,	99,	100,99,	99,	100,99,	99,	0,	99},
{99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,	100,99,	99,	0,	99,	99,	0,	99},
{99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99},
{99,	0,	0,	0,	100,	100,	0,	100,0,	0,	0,	0,	0,	0,	100,	0,	100,0,	0,	0,	0,	0,	100,0,	0,	100,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	100,	0,	0,	0,	100,100,	0,	0,	0,	0,	100,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	100,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99},
{99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99},
{99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99},
{99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,	0,	0,	100,0,	0,	0,	0,	99},
{99,	0,	0,	0,	100,0,	0,	0,	0,	0,	100,	0,	0,	0,	0,	100,0,	0,	100,100,0,	0,	0,	0,	0,	0,	0,	100,	0,	100,0,	0,	100,0,	0,	0,	0,	0,	100,0,	0,	100,0,	0,	99},
{99,	0,	99,	99,	100,99,	99,	0,	99,	99,	0,	99,	99,100,	99,	99,	0,	99,	99,	100,99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99},
{99,	100,99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,100,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99},
{99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,100,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99},
{99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,100,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	0,	99,	99,	100,99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	100,	0,	100,	0,	0,	100,0,	100,	0,	0,	100,	0,	0,	0,	0,	0,	0,	100,0,	0,	100,0,	0,	100,0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	100,100,	0,	100,	0,	0,	100,	0,	0,	0,	0,	100,0,	0,	0,	100,100,100,0,	0,	100,0,	0,	100,0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	0,	100,	0,	100,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	100,100,100,100,0,	0,	100,0,	0,	100,0,	0,	99},
{99,	250,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,99,				99},
};

vector<vector<int>>Map5_4 = {
{99,	99, 99,	99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	100,0,	100,0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	100,0,	100,0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	100,0,	100,0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	100,0,	100,0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	100,100,100,0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,100,100,0,	100,100,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	100,0,	100,0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	100,0,	100,0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	100,100,100,0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,100,100,0,	100,0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,100,0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	100,0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	120,0,	0,	100,0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	100,100,100,100,100,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,0,	0,	100,0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,100,0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99},
{99,	250,99, 99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99},
};