#pragma once
#include "Chess.h"
#include <iostream>
#include <vector>
using namespace std;
class Player
{
public:
	Player(int Color);    //��ʼ����ң�0����ڣ�1�����
	void Choose(int & MoveID, vector<vector<int>> & Color, vector<vector<string>> & Board, int & status); 
	void Refresh(const vector<vector<int>> & Color);
	vector<Chess *> Chesses;//���漺����16������
private:
	int Color;            //��ɫ���ɸı�
};