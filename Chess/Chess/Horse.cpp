#include "Chess.h"
int Horse::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "黑" : "红";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move....." ;
	int count = 50;
	int MoveRow = 0;
	int MoveCol = 0;
	while (count--)//
	{
		MoveRow = 0;
		MoveCol = 0;
		int Direction = rand()%8;//产生随机方向0-7

		if (Direction == 0 && CurRow >= 1 && CurCol <= 6) //可以往0方向走
		{
			if (Color[CurRow][CurCol + 1] != -1)//被卡住马脚
				continue;
			if (Color[CurRow - 1][CurCol + 2] == this->Color)//友方棋子
				continue;//产生新方向
			MoveRow = -1;
			MoveCol = 2;
		}

		else if (Direction == 1 && CurRow >= 2 && CurCol <= 7) //可以往1方向走
		{
			if (Color[CurRow - 1][CurCol] != -1)//被卡住马脚
				continue;
			if (Color[CurRow - 2][CurCol + 1] == this->Color)//友方棋子
				continue;//产生新方向
			MoveRow = -2;
			MoveCol = 1;
		}

		else if (Direction == 2 && CurRow >= 2 && CurCol >= 1) //可以往2方向走
		{
			if (Color[CurRow - 1][CurCol] != -1)//被卡住马脚
				continue;
			if (Color[CurRow - 2][CurCol - 1] == this->Color)//友方棋子
				continue;//产生新方向
			MoveRow = -2;
			MoveCol = -1;
		}

		else if (Direction == 3 && CurRow >= 1 && CurCol >= 2) //可以往3方向走
		{
			if (Color[CurRow][CurCol - 1] != -1)//被卡住马脚
				continue;
			if (Color[CurRow - 1][CurCol - 2] == this->Color)//友方棋子
				continue;//产生新方向
			MoveRow = -1;
			MoveCol = -2;
		}

		else if (Direction == 4 && CurRow <= 8 && CurCol >= 2) //可以往4方向走
		{
			if (Color[CurRow][CurCol - 1] != -1)//被卡住马脚
				continue;
			if (Color[CurRow + 1][CurCol - 2] == this->Color)//友方棋子
				continue;//产生新方向
			MoveRow = 1;
			MoveCol = -2;
		}

		else if (Direction == 5 && CurRow <= 7 && CurCol >= 1) //可以往5方向走
		{
			if (Color[CurRow + 1][CurCol] != -1)//被卡住马脚
				continue;
			if (Color[CurRow + 2][CurCol - 1] == this->Color)//友方棋子
				continue;//产生新方向
			MoveRow = 2;
			MoveCol = -1;
		}

		else if (Direction == 6 && CurRow <= 7 && CurCol <= 7) //可以往6方向走
		{
			if (Color[CurRow + 1][CurCol] != -1)//被卡住马脚
				continue;
			if (Color[CurRow + 2][CurCol + 1] == this->Color)//友方棋子
				continue;//产生新方向
			MoveRow = 2;
			MoveCol = 1;
		}

		else if (Direction == 7 && CurRow <= 8 && CurCol <= 6) //可以往7方向走
		{
			if (Color[CurRow][CurCol + 1] != -1)//被卡住马脚
				continue;
			if (Color[CurRow + 1][CurCol + 2] == this->Color)//友方棋子
				continue;//产生新方向
			MoveRow = 1;
			MoveCol = 2;
		}
		else //该方向不行，那就换一个方向
			continue;
		PreRow = CurRow;
		PreCol = CurCol;
		Color[PreRow][PreCol] = -1;//原先位置置空
		Board[PreRow][PreCol] = "++";//原先位置置空
		CurRow += MoveRow;
		CurCol += MoveCol;
		if (Color[CurRow][CurCol] == 1 - this->Color)//吃掉一个棋子
		{
			Color[CurRow][CurCol] = this->Color;//新位置置为棋子颜色
			Board[CurRow][CurCol] = NAME;//新位置置为棋子颜色
			cout << "to (" << CurRow << ", " << CurCol << ") Successfully!" << endl <<endl;
			return 1;//返回1
		}
		Color[CurRow][CurCol] = this->Color;//新位置置为棋子颜色
		Board[CurRow][CurCol] = NAME;//新位置置为棋子颜色
		cout << "to (" << CurRow << ", " << CurCol << ") Successfully!" << endl << endl;
		break;
	}
	if (count <= 0)
	{
		cout << "Failed to move!"<<endl<<"Player is reconsidering....." << endl<<endl;
		Sleep(1000);
		return -1;
	}
	return 0;
}