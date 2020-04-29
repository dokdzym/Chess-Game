#include "Chess.h"
int Elephant::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0)? "��" : "��";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move.....";
	int count = 100;
	while (--count)
	{
		PreRow = CurRow;
		PreCol = CurCol;
		if (CurRow == 0 || CurRow == 5)//��ʱֻ�������ƶ�
		{
			CurRow += 2;
			int Direction = rand() % 2;//2������,0�����£�1������
			CurCol = (Direction == 0) ? (CurCol - 2) : (CurCol + 2);
		}
		else if (CurRow == 4 || CurRow == 9)//��ʱֻ�������ƶ�
		{
			CurRow -= 2;
			int Direction = rand() % 2;//2������,0�����ϣ�1������
			CurCol = (Direction == 0) ? (CurCol - 2) : (CurCol + 2);
		}
		else if (CurRow == 2 || CurRow == 7)//���м䣬���ܵ�λ��������
		{
			if (CurCol == 0)   //�����
			{
				int Direction = rand() % 2;//2������,0�����ϣ�1������
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
			if (CurCol == 8)   //���Ҳ�
			{
				//srand((unsigned)time(NULL));
				int Direction = rand() % 2;//2������,0�����ϣ�1������
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
			else if (CurCol == 4)   //���м�
			{
				//srand((unsigned)time(NULL));
				int Direction = rand() % 4;//4�����򣬰�������˳��
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
		if (Color[MidRow][MidCol] != -1 || Color[CurRow][CurCol] == this -> Color)  //�������������Ż���Ŀ�ĵ���һ���Ѿ�
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