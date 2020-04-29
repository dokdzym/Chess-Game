#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;
class Player;//前向声明
class Chess{
public:
	friend Player;     //Player有权访问Chess
	Chess(int ID, string NAME, int Color, int Row, int Col, int vedID);
	string GetNAME();  
	int GetCurRow();   //棋子对棋盘和裁判是封装的，这意味着棋盘和裁判不能修改行  用于Judge.cpp和ChessBoard.cpp
	int GetCurCol();   //棋子对棋盘和裁判是封装的，这意味着棋盘和裁判不能修改列  用于Judge.cpp和ChessBoard.cpp
	int GetvecID();
	int GetLive();     //裁判无权将棋子移入、移出墓地，但可以访问棋子的Live状态
	virtual int Move(vector<vector<int>> & Color, vector<vector<string>> & Board);
protected:
	int Color;
	int ID;
	string NAME;
	int PreRow;
	int PreCol;
	int CurRow;
	int CurCol;
	int vecID;         //同一棋子对应同一个vecID，是Player里Chesses数组的下标
	int Live = 1;
};


class Horse : public Chess
{
public:
	Horse(int ID, string NAME, int Color, int Row, int Col, int vecID) : Chess(ID, NAME, Color, Row, Col, vecID) {};
	int Move(vector<vector<int>> & Color, vector<vector<string>> & Board);
};


class Chariot : public Chess
{
public:
	Chariot(int ID, string NAME, int Color, int Row, int Col, int vecID) : Chess(ID, NAME, Color, Row, Col, vecID) {};
	int Move(vector<vector<int>> & Color, vector<vector<string>> & Board);
}; 


class Advisor : public Chess
{
public:
	Advisor(int ID, string NAME, int Color, int Row, int Col, int vecID) : Chess(ID, NAME, Color, Row, Col, vecID) {};
	int Move(vector<vector<int>> & Color, vector<vector<string>> & Board);
};


class Elephant : public Chess
{
public:
	Elephant(int ID, string NAME, int Color, int Row, int Col, int vecID) : Chess(ID, NAME, Color, Row, Col, vecID) {};
	int Move(vector<vector<int>> & Color, vector<vector<string>> & Board);
};


class King : public Chess
{
public:
	King(int ID, string NAME, int Color, int Row, int Col, int vecID) : Chess(ID, NAME, Color, Row, Col, vecID) {};
	int Move(vector<vector<int>> & Color, vector<vector<string>> & Board);
};


class Pawn : public Chess
{
public:
	Pawn(int ID, string NAME, int Color, int Row, int Col, int vecID) : Chess(ID, NAME, Color, Row, Col, vecID) {};
	int Move(vector<vector<int>> & Color, vector<vector<string>> & Board);
};


class Cannon : public Chess
{
public:
	Cannon(int ID, string NAME, int Color, int Row, int Col, int vecID) : Chess(ID, NAME, Color, Row, Col, vecID) {};
	int Move(vector<vector<int>> & Color, vector<vector<string>> & Board);
};