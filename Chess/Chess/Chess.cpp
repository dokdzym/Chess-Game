#include "Chess.h"
Chess::Chess(int ID, string NAME, int Color, int Row, int Col, int vedID)
{//ID��0����˧��1����ʿ��2������ 3������4��ʾ����5��ʾ�ڣ�6��ʾ��
	this->ID = ID;
	this->NAME = NAME;
	this->Color = Color;
	this->PreRow = Row;
	this->PreCol = Col;
	this->CurRow = Row;
	this->CurCol = Col;
	this->vecID = vedID;
};
string Chess::GetNAME()
{
	return NAME;
}
int Chess::GetCurRow()
{
	return CurRow;
}
int Chess::GetCurCol()
{
	return CurCol;
}

int Chess::GetvecID()
{
	return vecID;
}

int Chess::GetLive()
{
	return Live;
}


int Chess::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	return 0;
}


