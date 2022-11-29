
#include <vector>
using namespace std;
vector<vector<int>> Map5 = {
		{99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 113, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 99, 201, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 201, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,99, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 301},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 301},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 99, 201,99 , 99,99 , 99, 99, 99, 99, 99, 99, 99, 99,99, 99, 99, 0, 0, 99,201, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 99, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 99, 201, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 301},
		{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 301},
		{99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 ,99, 99, 99, 99, 99 ,99}
};

vector<vector<int>> Box_Quiz_Map5_1 = {
	{99, -1, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
	{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99},
	{99, 100, 0, 0, 0, 100, 100, 0, 0, 0, 0, 0, 99},
	{99, 0, 0, 100, 0, 0, 0, 0, 0, 0, 100, 0, 99},
	{99, 0, 0, 0, 100, 0, 0, 100, 0, 0, 100, 0, 99},
	{99, 0, 100, 0, 0, 0, 100, 0, 100, 0, 100, 0, 99},
	{99, 0, 0, 0, 0, 0, 0, 100, 0, 100, 100, 0, 99},
	{99, 0, 0, 0, 100, 0, 0, 100, 0, 0, 0, 0, 99},
	{99, 100, 0, 0, 0, 100, 0, 0, 100, 0, 0, 0, 99},
	{99, 0, 0, 0, 100, 0, 0, 0, 0, 100, 0, 0, 99},
	{99, 0, 100, 0, 0, 0, 100, 0, 0,100, 0, 0, 99},
	{99, 100, 0, 0, 100, 100, 100, 0, 0, 100, 0, 0, 99},
	{99,0, 0, 0, 0, 0, 0, 100, 0, 0, 101, 0, 99},
	{99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
};

vector<vector<int>> Map5_2_Upper = {
	{99, -1, 99, 99,99, 99,99, 99,99,99,99,99, 99, 99,99, 99,99,99,99, 99,99, 99, 99,99, 99},
	{99, 0, 0, 0, 0, 0, 0, 0, 0, 0,99, 0,0, 99,0,0, 99, 0,0,99,0,0,0,0, 99},
	{99, 0, 0, 0, 0, 0, 0, 0, 0, 0,99, 0, 0,99,0, 0,99, 0,0,99,0,0,0, 0, 99},
	{99, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,99,99, 99, 99,99,99,99, 99,99,99,99,99,99, 99},
	{99, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0, 0, 0,0,0,0, 0,0,0,0,0,0, 99},
	{99, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0, 0, 0,0,0,0, 0,0,0,0,0,0, 99},
	{99, 0, 99, 99, 99, 99, 99,99, 99, 0, 0,0, 0,0,0,0,0, 0,0,0,0,0,0,0, 99},
	{99, 0, 99, 0, 0, 99, 0,0, 99,0 , 0,0, 0,0,0, 0,0,0,0,0,0,0,0,0, 99},
	{99, 0, 99, 0, 0, 99, 0,0, 99, 0, 0,0, 0,0,0, 0,0,0,0,0,0,0,0,0, 99},
	{99, 99, 99, 99, 99, 99, 99,99, 99,99, 99,99, 99,99,99,99,99,99,99,99,99,99, 99, 99, 99},
};

vector<vector<int>> Map5_2_Bottom = {
	{99, 99, 99, 99,99, 99,99, 99,99,99,99,99, 99, 99,99, 99,99,99,99, 99,99, 99, 99,99, 99},
	{99, 0, 99, 0, 0, 99, 0, 0, 99, 0,0, 0,0, 0,0,0, 0, 0,0,0,0,0,0,0, 99},
	{99, 0, 99, 0, 0, 99, 0, 0, 99, 0,0, 0, 0,0,0, 0,0, 0,0,0,0,0,0, 0, 99},
	{99, 0, 99, 99, 99, 99, 99, 99, 99, 0,0,0,0, 0, 0,0,0,0, 0,0,0,0,0,0, 99},
	{99, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0, 0, 0,0,0,0, 0,0,0,0,0,0, 99},
	{99, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0, 0, 0,0,0,0, 0,0,0,0,0,0, 99},
	{99, 0, 0, 0, 0, 0, 0,0, 0, 0, 99,99, 99,99,99,99,99, 99,99,99,99,99,99,99, 99},
	{99, 0, 0, 0, 0, 0, 0,0, 0,0 ,99,0, 0,99,0, 0,99,0,0,99,0,0,0,0, 99},
	{99, 0, 0, 0, 0, 0, 0,0, 0, 0, 99,0, 0,99,0, 0,99,0,0,99,0,0,0,0, 99},
	{99, -1, 99, 99, 99, 99, 99,99, 99,99, 99,99, 99,99,99,99,99,99,99,99,99,99, 99, 99, 99},
};

vector<vector<int>> Map5_4 = {
	{99, -1, 99, 99, 99, 99, 99, 99, 99, 99, 99,99,99,99, 99, 99,99},
	{99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0, 99},
	{99, 100, 0, 0, 0, 100, 100, 0, 0, 0, 0,0,0,0,0, 0, 99},
	{99, 0, 0, 100, 0, 0, 0, 0, 0, 0, 100, 0,0,0,0,0, 99},
	{99, 0, 0, 0, 100, 0, 0, 100, 0, 0, 100, 0,0,0,0,0, 99},
	{99, 0, 100, 0, 0, 0, 100, 0, 100, 0, 100, 0,0,0,0,0, 99},
	{99, 0, 0, 0, 0, 0, 0, 100, 0, 100, 100, 0,0,0,0,0, 99},
	{99, 0, 0, 0, 100, 0, 0, 100, 0, 0, 0, 0,0,0,0,0, 99},
	{99, 100, 0, 0, 0, 100, 0, 0, 100, 0, 0, 0,0,0,0,0, 99},
	{99, 0, 0, 0, 100, 0, 0, 0, 0, 100, 0, 0, 0,0,0,0,99},
	{99, 0, 100, 0, 0, 0, 100, 0, 0,100, 0, 0, 0,0,0,0,99},
	{99, 100, 0, 0, 100, 100, 100, 0, 0, 100, 0, 0,0,0,0,0, 99},
	{99,0, 0, 0, 0, 0, 0, 100, 0, 0, 101, 0,0,0,0,0, 99},
	{99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,99,99,99,99, 99, 99},
};