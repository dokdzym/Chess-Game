#include "Chess.h"
int Cannon::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "黑" : "红";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move.....";
	int count = 30;
	while (--count)
	{
		PreRow = CurRow;
		PreCol = CurCol;
		//中间代码用于列出可能的移动位置
		//炮往上下左右四个方向，寻找前两个在同一排上的棋子，如果该方向上找到的个数小于2，continue；如果第二个棋子是敌方，改变row和col
		int Direction = rand() % 4;//01表示上下，23表示左右
		int NO;
		if (Direction == 0)
		{
			NO = 0;
			int i = CurRow - 1;
			while(i >= 0)
			{
				if (Color[i][CurCol] != -1)
					++ NO;
				if (NO == 2)
					CurRow = i;
				-- i;
			}
		}
		else if (Direction == 1)
		{
			NO = 0;
			int i = CurRow + 1;
			while (i <= 9)
			{
				if (Color[i][CurCol] != -1)
					++ NO;
				if (NO == 2)
					CurRow = i;
				++ i;
			}
		}
		else if (Direction == 2)
		{
			NO = 0;
			int i = CurCol - 1;
			while (i >= 0)
			{
				if (Color[CurRow][i] != -1)
					++ NO;
				if (NO == 2)
					CurCol = i;
				-- i;
			}
		}
		else if (Direction == 3)
		{
			NO = 0;
			int i = CurCol + 1;
			while (i <= 8)
			{
				if (Color[CurRow][i] != -1)
					++NO;
				if (NO == 2)
					CurCol = i;
				++ i;
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
		if (Color[CurRow][CurCol] == 1 - this -> Color)//吃掉一个棋子
		{
			Color[CurRow][CurCol] = this -> Color;//新位置置为棋子颜色
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