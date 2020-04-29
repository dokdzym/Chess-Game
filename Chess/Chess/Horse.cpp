#include "Chess.h"
int Horse::Move(vector<vector<int>> & Color, vector<vector<string>> & Board)
{
	string CurPlayer = (this->Color == 0) ? "��" : "��";
	cout << "This is Player " << CurPlayer << "'s " << this->NAME << " in position " << CurRow << ", " << CurCol << " " << ", Trying to move....." ;
	int count = 50;
	int MoveRow = 0;
	int MoveCol = 0;
	while (count--)//
	{
		MoveRow = 0;
		MoveCol = 0;
		int Direction = rand()%8;//�����������0-7

		if (Direction == 0 && CurRow >= 1 && CurCol <= 6) //������0������
		{
			if (Color[CurRow][CurCol + 1] != -1)//����ס���
				continue;
			if (Color[CurRow - 1][CurCol + 2] == this->Color)//�ѷ�����
				continue;//�����·���
			MoveRow = -1;
			MoveCol = 2;
		}

		else if (Direction == 1 && CurRow >= 2 && CurCol <= 7) //������1������
		{
			if (Color[CurRow - 1][CurCol] != -1)//����ס���
				continue;
			if (Color[CurRow - 2][CurCol + 1] == this->Color)//�ѷ�����
				continue;//�����·���
			MoveRow = -2;
			MoveCol = 1;
		}

		else if (Direction == 2 && CurRow >= 2 && CurCol >= 1) //������2������
		{
			if (Color[CurRow - 1][CurCol] != -1)//����ס���
				continue;
			if (Color[CurRow - 2][CurCol - 1] == this->Color)//�ѷ�����
				continue;//�����·���
			MoveRow = -2;
			MoveCol = -1;
		}

		else if (Direction == 3 && CurRow >= 1 && CurCol >= 2) //������3������
		{
			if (Color[CurRow][CurCol - 1] != -1)//����ס���
				continue;
			if (Color[CurRow - 1][CurCol - 2] == this->Color)//�ѷ�����
				continue;//�����·���
			MoveRow = -1;
			MoveCol = -2;
		}

		else if (Direction == 4 && CurRow <= 8 && CurCol >= 2) //������4������
		{
			if (Color[CurRow][CurCol - 1] != -1)//����ס���
				continue;
			if (Color[CurRow + 1][CurCol - 2] == this->Color)//�ѷ�����
				continue;//�����·���
			MoveRow = 1;
			MoveCol = -2;
		}

		else if (Direction == 5 && CurRow <= 7 && CurCol >= 1) //������5������
		{
			if (Color[CurRow + 1][CurCol] != -1)//����ס���
				continue;
			if (Color[CurRow + 2][CurCol - 1] == this->Color)//�ѷ�����
				continue;//�����·���
			MoveRow = 2;
			MoveCol = -1;
		}

		else if (Direction == 6 && CurRow <= 7 && CurCol <= 7) //������6������
		{
			if (Color[CurRow + 1][CurCol] != -1)//����ס���
				continue;
			if (Color[CurRow + 2][CurCol + 1] == this->Color)//�ѷ�����
				continue;//�����·���
			MoveRow = 2;
			MoveCol = 1;
		}

		else if (Direction == 7 && CurRow <= 8 && CurCol <= 6) //������7������
		{
			if (Color[CurRow][CurCol + 1] != -1)//����ס���
				continue;
			if (Color[CurRow + 1][CurCol + 2] == this->Color)//�ѷ�����
				continue;//�����·���
			MoveRow = 1;
			MoveCol = 2;
		}
		else //�÷����У��Ǿͻ�һ������
			continue;
		PreRow = CurRow;
		PreCol = CurCol;
		Color[PreRow][PreCol] = -1;//ԭ��λ���ÿ�
		Board[PreRow][PreCol] = "++";//ԭ��λ���ÿ�
		CurRow += MoveRow;
		CurCol += MoveCol;
		if (Color[CurRow][CurCol] == 1 - this->Color)//�Ե�һ������
		{
			Color[CurRow][CurCol] = this->Color;//��λ����Ϊ������ɫ
			Board[CurRow][CurCol] = NAME;//��λ����Ϊ������ɫ
			cout << "to (" << CurRow << ", " << CurCol << ") Successfully!" << endl <<endl;
			return 1;//����1
		}
		Color[CurRow][CurCol] = this->Color;//��λ����Ϊ������ɫ
		Board[CurRow][CurCol] = NAME;//��λ����Ϊ������ɫ
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