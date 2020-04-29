#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;
class Player;//ǰ������
class Chess{
public:
	friend Player;     //Player��Ȩ����Chess
	Chess(int ID, string NAME, int Color, int Row, int Col, int vedID);
	string GetNAME();  
	int GetCurRow();   //���Ӷ����̺Ͳ����Ƿ�װ�ģ�����ζ�����̺Ͳ��в����޸���  ����Judge.cpp��ChessBoard.cpp
	int GetCurCol();   //���Ӷ����̺Ͳ����Ƿ�װ�ģ�����ζ�����̺Ͳ��в����޸���  ����Judge.cpp��ChessBoard.cpp
	int GetvecID();
	int GetLive();     //������Ȩ���������롢�Ƴ�Ĺ�أ������Է������ӵ�Live״̬
	virtual int Move(vector<vector<int>> & Color, vector<vector<string>> & Board);
protected:
	int Color;
	int ID;
	string NAME;
	int PreRow;
	int PreCol;
	int CurRow;
	int CurCol;
	int vecID;         //ͬһ���Ӷ�Ӧͬһ��vecID����Player��Chesses������±�
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