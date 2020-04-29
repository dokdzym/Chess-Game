#include "Chess.h"
int King::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "��" : "��";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move.....";
	int count = 30;
	while (--count)
	{
		PreRow = CurRow;
		PreCol = CurCol;
		int Direction = rand() % 4;//01��ʾ���£�23��ʾ����
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
			continue;//���磬����
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