#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
#include "Player.h"
using namespace std;
class ChessBoard
{
public:
	friend void GameStart();            //���п��������޸�����
	ChessBoard(Player Red, Player Black);
	void Fill(Player Red, Player Black);//��ȡ������ҳ��ϵ�����
	void Show();                        //��ʾ��ǰ����
private:
	vector<vector<string>> Board = vector<vector<string>>(10, vector<string>(9, "++"));
	vector<vector<int>> Color = vector<vector<int>>(10, vector<int>(9, -1));
};