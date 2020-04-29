#pragma once
#include "Chess.h"
#include <iostream>
#include <vector>
using namespace std;
class Player
{
public:
	Player(int Color);    //初始化玩家，0代表黑，1代表红
	void Choose(int & MoveID, vector<vector<int>> & Color, vector<vector<string>> & Board, int & status); 
	void Refresh(const vector<vector<int>> & Color);
	vector<Chess *> Chesses;//保存己方的16个棋子
private:
	int Color;            //颜色不可改变
};