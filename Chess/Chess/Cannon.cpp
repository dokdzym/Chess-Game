#include "Chess.h"
int Cannon::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "��" : "��";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move.....";
	int count = 30;
	while (--count)
	{
		PreRow = CurRow;
		PreCol = CurCol;
		//�м���������г����ܵ��ƶ�λ��
		//�������������ĸ�����Ѱ��ǰ������ͬһ���ϵ����ӣ�����÷������ҵ��ĸ���С��2��continue������ڶ��������ǵз����ı�row��col
		int Direction = rand() % 4;//01��ʾ���£�23��ʾ����
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
		if (CurRow < 0 || CurRow > 9 || CurCol < 0 || CurCol > 8 || Color[CurRow][CurCol] == this->Color)//������߸÷������Ѿ�
		{
			CurRow = PreRow;
			CurCol = PreCol;
			continue;
		}
		Color[PreRow][PreCol] = -1;//ԭ��λ���ÿ�
		Board[PreRow][PreCol] = "++";//ԭ��λ���ÿ�
		if (Color[CurRow][CurCol] == 1 - this -> Color)//�Ե�һ������
		{
			Color[CurRow][CurCol] = this -> Color;//��λ����Ϊ������ɫ
			Board[CurRow][CurCol] = NAME;//��λ����Ϊ������ɫ
			cout << "to (" << CurRow << ", " << CurCol << ") Successfully!" << endl << endl;
			return 1;//����1
		}
		Color[CurRow][CurCol] = this->Color;//��λ����Ϊ������ɫ
		Board[CurRow][CurCol] = NAME;//��λ����Ϊ������ɫ
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