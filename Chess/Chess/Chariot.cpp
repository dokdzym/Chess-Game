#include "Chess.h"
int Chariot::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "��" : "��";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move....." ;
	int count = 100;
	while (count--)//
	{
		int Direction = rand() % 4;//�������������������,0�������ϣ�1�������£�2��������3��������
		int Distance = 0;//�÷������ж��ٸ���λ
		int MoveD = 0;
		if (Direction == 0) //����
		{
			Distance = 0;
			for (int i = CurRow - 1; i >= 0 && Color[i][CurCol] == -1; --i)
				++Distance;
			//��Distance+1�����ӣ�Ҫô���Ѿ���Ҫô�ǵо�������ǵо���ֱ�ӳԵ���������Ѿ�������ƶ�һ�ξ���
			if (CurRow - Distance - 1 >= 0 && (Color[CurRow - Distance - 1][CurCol] == 1 - this->Color))//�ǵо���ֱ�ӳԵ�
			{
				MoveD = 0 - Distance - 1;
				cout << "Killing A Chess��" << endl;
			}
			else//���Ѿ����߳��磬����ƶ�һ��
			{
				if (Distance == 0) 
				{
					Direction = (rand() % 4 + 1) % 4;
					Sleep(1);
					continue;
				}//�÷����޷����ߣ�����
				MoveD = -1 - rand() % Distance;
			}
		}
		else if (Direction == 1) //����
		{
			Distance = 0;
			for (size_t i = CurRow + 1; i <= 9 && Color[i][CurCol] == -1; ++i)
				++Distance;
			if (CurRow + Distance + 1 <= 9 && (Color[CurRow + Distance + 1][CurCol] == 1 - this->Color))//�ǵо���ֱ�ӳԵ�
			{
				MoveD = Distance + 1;
				cout << "Killing A Chess��" << endl;
			}
			else//���Ѿ����߳��磬����ƶ�һ��
			{
				if (Distance == 0) 
				{
					Direction = (rand() % 4 + 1) % 4;
					Sleep(1);
					continue;
				}//�÷����޷����ߣ�����
				MoveD = 1 + rand() % Distance;
			}
		}
		else if (Direction == 2) //����
		{
			Distance = 0;
			for (int i = CurCol - 1; i >= 0 && Color[CurRow][i] == -1; --i)
				++Distance;
			if (Distance == 0)
			{
				Direction = (rand() % 4 + 1) % 4;
				Sleep(1);
				continue;
			}//�÷����޷����ߣ�����
			if (CurCol - Distance - 1 >= 0 && (Color[CurRow][CurCol - Distance - 1] == 1 - this->Color))//�ǵо���ֱ�ӳԵ�
			{
				MoveD = 0 - Distance - 1;
				cout << "Killing A Chess��" << endl;
			}
			else//���Ѿ����߳��磬����ƶ�һ��
			{
				if (Distance == 0) continue;//�÷����޷����ߣ�����
				MoveD = -1 - rand() % Distance;
			}
		}
		else if (Direction == 3) //����
		{
			Distance = 0;
			for (size_t i = CurCol + 1; i <= 8 && Color[CurRow][i] == -1; ++i)
				++Distance;
			if (CurCol + Distance + 1 <= 8 && (Color[CurRow][CurCol + Distance + 1] == 1 - this->Color))//�ǵо���ֱ�ӳԵ�
			{
				MoveD = Distance + 1;
				cout << "Killing A Chess��" << endl;
			}

			else//���Ѿ����߳��磬����ƶ�һ��
			{
				if (Distance == 0)
				{
					Direction = (rand() % 4 + 1) %4;
					Sleep(1);
					continue;
				}//�÷����޷����ߣ�����
				MoveD = 1 + rand() % Distance;
			}
		}
		else
			cout << "Error choosing direction.";
		if (MoveD == 0)
			cout << "Cannot Move in this direction! Press Enter again please." << endl;
		PreRow = CurRow;
		PreCol = CurCol;
		Color[PreRow][PreCol] = -1;//ԭ��λ���ÿ�
		Board[PreRow][PreCol] = "++";//ԭ��λ���ÿ�
		if (Direction == 0 || Direction == 1)//�����ƶ�
			CurRow += MoveD;
		if (Direction == 2 || Direction == 3)//�����ƶ�
			CurCol += MoveD;
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