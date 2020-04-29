#include "Chess.h"
int Elephant::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0)? "黑" : "红";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move.....";
	int count = 100;
	while (--count)
	{
		PreRow = CurRow;
		PreCol = CurCol;
		if (CurRow == 0 || CurRow == 5)//此时只能向下移动
		{
			CurRow += 2;
			int Direction = rand() % 2;//2个方向,0向左下，1向右下
			CurCol = (Direction == 0) ? (CurCol - 2) : (CurCol + 2);
		}
		else if (CurRow == 4 || CurRow == 9)//此时只能向上移动
		{
			CurRow -= 2;
			int Direction = rand() % 2;//2个方向,0向左上，1向右上
			CurCol = (Direction == 0) ? (CurCol - 2) : (CurCol + 2);
		}
		else if (CurRow == 2 || CurRow == 7)//在中间，可能的位置有三个
		{
			if (CurCol == 0)   //在左侧
			{
				int Direction = rand() % 2;//2个方向,0向右上，1向右下
				if (Direction == 0)
				{
					CurRow -= 2;
					CurCol += 2;
				}
				else 
				{
					CurRow += 2;
					CurCol += 2;
				}
			}
			if (CurCol == 8)   //在右侧
			{
				//srand((unsigned)time(NULL));
				int Direction = rand() % 2;//2个方向,0向左上，1向左下
				if (Direction == 0)
				{
					CurRow -= 2;
					CurCol -= 2;
				}
				else
				{
					CurRow += 2;
					CurCol -= 2;
				}
			}
			else if (CurCol == 4)   //在中间
			{
				//srand((unsigned)time(NULL));
				int Direction = rand() % 4;//4个方向，按照象限顺序
				if (Direction == 0)
				{
					CurRow -= 2;
					CurCol += 2;
				}
				else if(Direction == 1)
				{
					CurRow -= 2;
					CurCol -= 2;
				}
				else if (Direction == 2)
				{
					CurRow += 2;
					CurCol -= 2;
				}
				else if (Direction == 3)
				{
					CurRow += 2;
					CurCol += 2;
				}
			}
		}
		int MidRow = (CurRow + PreRow) >> 1;
		int MidCol = (CurCol + PreCol) >> 1;
		if (Color[MidRow][MidCol] != -1 || Color[CurRow][CurCol] == this -> Color)  //重试情况：别象脚或者目的地是一个友军
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