#include "Chess.h"
int Pawn::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "��" : "��";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position "<<CurRow<<", "<<CurCol<<" "<<", Trying to move....." ;
	int count = 30;
	while (--count)
	{
		PreRow = CurRow;
		PreCol = CurCol;
		if (this->Color)//��ɫ�����·�
		{
			if(CurRow > 4)//û�й���	
				-- CurRow;
			else
			{
				int Direction = rand() % 3;//0��ʾ�ϣ�12��ʾ����
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
		else//��ɫ�����Ϸ�
		{
			if (CurRow < 5)
				++CurRow;
			else
			{
				int Direction = rand() % 3;//0��ʾ�ϣ�12��ʾ����
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
		if (CurRow < 0 || CurRow > 9 || CurCol < 0 || CurCol > 8 || Color[CurRow][CurCol] == this->Color)//������߸÷������Ѿ�
		{
			CurRow = PreRow;
			CurCol = PreCol;
			continue;
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