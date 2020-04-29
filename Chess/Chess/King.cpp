#include "Chess.h"
int King::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "黑" : "红";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move.....";
	int count = 30;
	while (--count)
	{
		PreRow = CurRow;
		PreCol = CurCol;
		int Direction = rand() % 4;//01表示上下，23表示左右
		if (Direction == 0)
			CurRow -= 1;
		else if (Direction == 1)
			CurRow += 1;
		else if (Direction == 2)
			CurCol -= 1;
		else if (Direction == 3)
			CurCol += 1;
		else
			cout << "Direction error!" << endl;
		if (((CurRow >= 0 && CurRow <= 2) || (CurRow >= 7 && CurRow <= 9)) && CurCol >= 3 && CurCol <= 5)
			;
		else 
		{
			CurRow = PreRow;
			CurCol = PreCol;
			continue;//超界，重试
		}
		if (Color[CurRow][CurCol] == this->Color)
		{
			CurRow = PreRow;
			CurCol = PreCol;
			continue;//是友军
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