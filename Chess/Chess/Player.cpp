#include "Player.h"
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
Player::Player(int Color)
{
	this->Color = Color;
	if (0 == Color)
	{
		Chesses.push_back(new King(0, "将", 0, 0, 4, 0));
		Chesses.push_back(new Advisor(1, "士", 0, 0, 3, 1));
		Chesses.push_back(new Advisor(1, "士", 0, 0, 5, 2));
		Chesses.push_back(new Elephant(2, "象", 0, 0, 2, 3));
		Chesses.push_back(new Elephant(2, "象", 0, 0, 6, 4));
		Chesses.push_back(new Horse(3, "马", 0, 0, 1, 5));
		Chesses.push_back(new Horse(3, "马", 0, 0, 7, 6));
		Chesses.push_back(new Chariot(4, "车", 0, 0, 0, 7));
		Chesses.push_back(new Chariot(4, "车", 0, 0, 8, 8));
		Chesses.push_back(new Cannon(5, "炮", 0, 2, 1, 9));
		Chesses.push_back(new Cannon(5, "炮", 0, 2, 7, 10));
		Chesses.push_back(new Pawn(6, "卒", 0, 3, 0, 11));
		Chesses.push_back(new Pawn(6, "卒", 0, 3, 2, 12));
		Chesses.push_back(new Pawn(6, "卒", 0, 3, 4, 13));
		Chesses.push_back(new Pawn(6, "卒", 0, 3, 6, 14));
		Chesses.push_back(new Pawn(6, "卒", 0, 3, 8, 15));
	}
	else
	{
		Chesses.push_back(new King(0, "帅", 1, 9, 4, 0));
		Chesses.push_back(new Advisor(1, "仕", 1, 9, 3, 1));
		Chesses.push_back(new Advisor(1, "仕", 1, 9, 5, 2));
		Chesses.push_back(new Elephant(2, "相", 1, 9, 2, 3));
		Chesses.push_back(new Elephant(2, "相", 1, 9, 6, 4));
		Chesses.push_back(new Horse(3, "馬", 1, 9, 1, 5));
		Chesses.push_back(new Horse(3, "馬", 1, 9, 7, 6));
		Chesses.push_back(new Chariot(4, "車", 1, 9, 0, 7));
		Chesses.push_back(new Chariot(4, "車", 1, 9, 8, 8));
		Chesses.push_back(new Cannon(5, "砲", 1, 7, 1, 9));
		Chesses.push_back(new Cannon(5, "砲", 1, 7, 7, 10));
		Chesses.push_back(new Pawn(6, "兵", 1, 6, 0, 11));
		Chesses.push_back(new Pawn(6, "兵", 1, 6, 2, 12));
		Chesses.push_back(new Pawn(6, "兵", 1, 6, 4, 13));
		Chesses.push_back(new Pawn(6, "兵", 1, 6, 6, 14));
		Chesses.push_back(new Pawn(6, "兵", 1, 6, 8, 15));
	}
}

void Player::Choose(int & MoveID, vector<vector<int>> & Color, vector<vector<string>> & Board, int & error)//MoveID用于回传给Judge，让裁判知道哪个棋子进行了移动，裁判才能通知棋盘，棋盘进行更改
{
	string curplayer = this->Color ? "红" : "黑";
	vector<int> Lives;
	for (auto chess : Chesses)
	{
		if (chess->Live)
			Lives.push_back(chess->vecID);
	}
	int HowManyLives = Lives.size();

	srand((unsigned)time(NULL));
	MoveID = Lives[rand() % HowManyLives];

	int r = this->Chesses[MoveID]->GetCurRow();
	int c = this->Chesses[MoveID]->GetCurCol(); 
	cout << "Player "<<curplayer<<" is controlling Chess ID " << MoveID << " , It's a "<<Chesses[MoveID] -> GetNAME()<<endl<<endl;
	Chess * a = Chesses[MoveID];
	if (MoveID == 0)
		a = (King *)a;
	else if (MoveID == 1 || MoveID == 2)
		a = (Advisor *)a;
	else if (MoveID == 3 || MoveID == 4)
		a = (Elephant *)a;
	else if (MoveID == 5 || MoveID == 6)
		a = (Horse *)a;
	else if (MoveID == 7 || MoveID == 8)
		a = (Chariot *)a;
	else if (MoveID == 9 || MoveID == 10)
		a = (Cannon *)a;
	else if (MoveID >= 11 && MoveID <= 15)
		a = (Pawn *)a;
	error = a -> Move(Color, Board);
}

void Player::Refresh(const vector<vector<int>> & Color)
{
	string curplayer = this->Color ? "红" : "黑";
	cout << curplayer<<" Dead List: ";
	for (auto chess : Chesses)
	{
		int row = chess->GetCurRow();
		int col = chess->GetCurCol();
		if (this->Color != Color[row][col])
		{
			chess -> Live = 0;
			cout << chess->GetNAME() << " ,vecID = " << chess->vecID << " ; ";
		}
	}
	cout << endl << endl;
}

