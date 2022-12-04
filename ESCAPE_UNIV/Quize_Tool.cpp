#include <vector>
#include "Quize_Tool.hpp"
#include "GameTool.hpp"
using namespace std;

vector<vector<int>>Init_Data_Map(int map_width, int map_height)
{
	
	vector<vector<int>> height;

	for (int  h = 0; h < map_height; h++)
	{
		vector<int> width;
		for (int  w = 0; w < map_width; w++)
		{
			
			if (h == 0 || h == map_height-1)
				width.push_back(99);
			else
			{
				if (w == 0 || w == map_width-1)
					width.push_back(99);
				else
					width.push_back(0);
			}
		}

		height.push_back(width);
	}

	return height;

}

void Plus_Line_Row(vector<vector<int>> mapid,int row_index,int row_start_point,int len_line )
{
	for (int i = row_start_point; i < len_line; i++)
		mapid[row_index][i] = 99;
}

void Plus_Line_Col(vector<vector<int>> mapid, int col_index, int col_start_point, int len_line)
{
	for (int i = col_start_point; i < len_line; i++)
		mapid[i][col_index] = 99;
}

void Plus_Point_Object(vector<vector<int>> mapid, int col_index, int row_index, int object)
{
	mapid[row_index][col_index] = object;
}

