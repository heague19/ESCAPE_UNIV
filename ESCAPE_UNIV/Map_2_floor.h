#pragma once
#include <vector>
using namespace std;
vector<vector<int>> Map2 = {
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	301,450,99},
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	301,450,99},
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	304,430,99},
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	304,430,99},
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99 },
  {99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0 },
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0}
};