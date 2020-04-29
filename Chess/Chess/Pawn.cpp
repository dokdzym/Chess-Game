#include "Chess.h"
int Pawn::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "黑" : "红";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position "<<CurRow<<", "<<CurCol<<" "<<", Trying to move....." ;
	int count = 30;
	while (--count)
	{
		PreRow = CurRow;
		PreCol = CurCol;
		if (this->Color)//红色，在下方
		{
			if(CurRow > 4)//没有过河	
				-- CurRow;
			else
			{
				int Direction = rand() % 3;//0表示上，12表示左右
				if (Direction == 0)
					CurRow -= 1;  
				else if (Direction == 1)
					CurCol -= 1;
				else if (Direction == 2)
					CurCol += 1;
				else
					cout << "Direction error!" << endl;
			}
		}
		else//黑色，在上方
		{
			if (CurRow < 5)
				++CurRow;
			else
			{
				int Direction = rand() % 3;//0表示上，12表示左右
				if (Direction == 0)
					CurRow += 1;
				else if (Direction == 1)
					CurCol -= 1;
				else if (Direction == 2)
					CurCol += 1;
				else
					cout << "Direction error!" << endl;
			}
		}
		if (CurRow < 0 || CurRow > 9 || CurCol < 0 || CurCol > 8 || Color[CurRow][CurCol] == this->Color)//超界或者该方向是友军
		{
			CurRow = PreRow;
			CurCol = PreCol;
			continue;
		}
		Color[PreRow][PreCol] = -1;//原先位置置空
		Board[PreRow][PreCol] = "++";//原先位置置空
		if (Color[CurRow][CurCol] == 1 - this->Color)//吃掉一个棋子
		{
			Color[CurRow][CurCol] = this->Color;//新位置置为棋子颜色
			Board[CurRow][CurCol] = NAME;//新位置置为棋子颜色
			cout << "to (" << CurRow << ", " << CurCol << ") Successfully!" << endl << endl;
			return 1;//返回1
		}
		Color[CurRow][CurCol] = this->Color;//新位置置为棋子颜色
		Board[CurRow][CurCol] = NAME;//新位置置为棋子颜色
		cout << "to (" << CurRow << ", " << CurCol << ") Successfully!" << endl << endl;
		break;
	}
	if (count <= 0)
	{
		cout << "Failed to move!" << endl << "Player is reconsidering....." << endl << endl;
		Sleep(1000);
		return -1;
	}
	return 0;
}