#pragma once
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> Init_Data_Map(int width, int height);
void Plus_Line_Row( vector<vector<int>> mapid, int row_index, int row_start_point, int len_line);
void Plus_Line_Col(vector<vector<int>> mapid, int col_index, int col_start_point, int len_line);
void Plus_Point_Object(vector<vector<int>> mapid, int col_index, int row_index, int object);
