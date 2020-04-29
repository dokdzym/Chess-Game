#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
#include "Player.h"
using namespace std;
class ChessBoard
{
public:
	friend void GameStart();            //裁判可以任意修改棋盘
	ChessBoard(Player Red, Player Black);
	void Fill(Player Red, Player Black);//读取两个玩家场上的棋子
	void Show();                        //显示当前棋盘
private:
	vector<vector<string>> Board = vector<vector<string>>(10, vector<string>(9, "++"));
	vector<vector<int>> Color = vector<vector<int>>(10, vector<int>(9, -1));
};