#include "Chess.h"
int Chariot::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "黑" : "红";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move....." ;
	int count = 100;
	while (count--)//
	{
		int Direction = rand() % 4;//产生随机方向上下左右,0代表向上，1代表向下，2代表向左，3代表向右
		int Distance = 0;//该方向上有多少个空位
		int MoveD = 0;
		if (Direction == 0) //往上
		{
			Distance = 0;
			for (int i = CurRow - 1; i >= 0 && Color[i][CurCol] == -1; --i)
				++Distance;
			//第Distance+1个格子，要么是友军，要么是敌军，如果是敌军，直接吃掉，如果是友军，随机移动一段距离
			if (CurRow - Distance - 1 >= 0 && (Color[CurRow - Distance - 1][CurCol] == 1 - this->Color))//是敌军，直接吃掉
			{
				MoveD = 0 - Distance - 1;
				cout << "Killing A Chess！" << endl;
			}
			else//是友军或者超界，随机移动一段
			{
				if (Distance == 0) 
				{
					Direction = (rand() % 4 + 1) % 4;
					Sleep(1);
					continue;
				}//该方向无法行走，重试
				MoveD = -1 - rand() % Distance;
			}
		}
		else if (Direction == 1) //往下
		{
			Distance = 0;
			for (size_t i = CurRow + 1; i <= 9 && Color[i][CurCol] == -1; ++i)
				++Distance;
			if (CurRow + Distance + 1 <= 9 && (Color[CurRow + Distance + 1][CurCol] == 1 - this->Color))//是敌军，直接吃掉
			{
				MoveD = Distance + 1;
				cout << "Killing A Chess！" << endl;
			}
			else//是友军或者超界，随机移动一段
			{
				if (Distance == 0) 
				{
					Direction = (rand() % 4 + 1) % 4;
					Sleep(1);
					continue;
				}//该方向无法行走，重试
				MoveD = 1 + rand() % Distance;
			}
		}
		else if (Direction == 2) //往左
		{
			Distance = 0;
			for (int i = CurCol - 1; i >= 0 && Color[CurRow][i] == -1; --i)
				++Distance;
			if (Distance == 0)
			{
				Direction = (rand() % 4 + 1) % 4;
				Sleep(1);
				continue;
			}//该方向无法行走，重试
			if (CurCol - Distance - 1 >= 0 && (Color[CurRow][CurCol - Distance - 1] == 1 - this->Color))//是敌军，直接吃掉
			{
				MoveD = 0 - Distance - 1;
				cout << "Killing A Chess！" << endl;
			}
			else//是友军或者超界，随机移动一段
			{
				if (Distance == 0) continue;//该方向无法行走，重试
				MoveD = -1 - rand() % Distance;
			}
		}
		else if (Direction == 3) //往右
		{
			Distance = 0;
			for (size_t i = CurCol + 1; i <= 8 && Color[CurRow][i] == -1; ++i)
				++Distance;
			if (CurCol + Distance + 1 <= 8 && (Color[CurRow][CurCol + Distance + 1] == 1 - this->Color))//是敌军，直接吃掉
			{
				MoveD = Distance + 1;
				cout << "Killing A Chess！" << endl;
			}

			else//是友军或者超界，随机移动一段
			{
				if (Distance == 0)
				{
					Direction = (rand() % 4 + 1) %4;
					Sleep(1);
					continue;
				}//该方向无法行走，重试
				MoveD = 1 + rand() % Distance;
			}
		}
		else
			cout << "Error choosing direction.";
		if (MoveD == 0)
			cout << "Cannot Move in this direction! Press Enter again please." << endl;
		PreRow = CurRow;
		PreCol = CurCol;
		Color[PreRow][PreCol] = -1;//原先位置置空
		Board[PreRow][PreCol] = "++";//原先位置置空
		if (Direction == 0 || Direction == 1)//上下移动
			CurRow += MoveD;
		if (Direction == 2 || Direction == 3)//左右移动
			CurCol += MoveD;
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