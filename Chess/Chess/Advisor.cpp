#include "Chess.h"
int Advisor::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "��" : "��";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move.....";
	int count = 30;
	while (-- count)
	{
		PreRow = CurRow;
		PreCol = CurCol;
		if (CurRow == 1 || CurRow == 8)//���м䣬���ĸ�����
		{
			int Direction = rand() % 4;//4������,0-3�ֱ��ǵ�һ���޵��������޵ķ���
			if (Direction == 0)
			{
				CurRow -= 1;
				CurCol += 1;
			}
			else if (Direction == 1)
			{
				CurRow -= 1;
				CurCol -= 1;
			}
			else if (Direction == 2)
			{
				CurRow += 1;
				CurCol -= 1;
			}
			else if (Direction == 3)
			{
				CurRow += 1;
				CurCol += 1;
			}
			else
			{
				cout << "error!" << endl;
			}
		}
		else if (CurRow == 0 || CurRow == 7)//ʿ��ʱֻ�������ƶ�
		{
			CurRow += 1;
			CurCol = (CurCol == 3) ? (CurCol + 1) : (CurCol - 1);
		}
		else if (CurRow == 2 || CurRow == 9)//ʿ��ʱֻ�������ƶ�
		{
			CurRow -= 1;
			CurCol = (CurCol == 3) ? (CurCol + 1) : (CurCol - 1);
		}
		if (Color[CurRow][CurCol] == this->Color)
		{
			CurRow = PreRow;
			CurCol = PreCol;
			continue;//���Ѿ�
		}
		Color[PreRow][PreCol] = -1;//ԭ��λ���ÿ�
		Board[PreRow][PreCol] = "++";//ԭ��λ���ÿ�
		if (Color[CurRow][CurCol] == 1 - this->Color)//�Ե�һ������
		{
			Color[CurRow][CurCol] = this->Color;//��λ����Ϊ������ɫ
			Board[CurRow][CurCol] = NAME;//��λ����Ϊ������ɫ
			cout << "to (" << CurRow << ", " << CurCol << ") Successfully!" << endl << endl;
			return 1;//����1
		}
		Color[CurRow][CurCol] = this -> Color;//��λ����Ϊ������ɫ
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