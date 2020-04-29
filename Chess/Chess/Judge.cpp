#include "Judge.h"
#include "Player.h"
#include "ChessBoard.h"
//Player Red(1);
//Player Black(0);
void GameStart()
{
	Player  Red = Player(1);
	Player Black = Player(0);
	ChessBoard Board(Red, Black);
	int CurPlayer = 1;//��������
	//���ϳ�ʼ�����̺��׷����

	cout << "GameStart!" << endl;
	int RedKingRow = 9;
	int RedKingCol = 4;
	int BlackKingRow = 0;
	int BlackKingCol = 4;
	//���ϳ�ʼ����˧λ��

	while (Board.Color[RedKingRow][RedKingCol] == 1 && Board.Color[BlackKingRow][BlackKingCol] == 0) //˫���Ľ�˧������
	{
		cout << "Press Enter to move a random chess!" << endl << endl;
		if (CurPlayer == 1)
		{
			cin.get();
			cout << "Player �� Considering...." << endl;
			int MoveID = -1;
			int status = 0;//��ʾ�ƶ����յ�
			Red.Choose(MoveID, Board.Color, Board.Board, status);//��ɫ���ѡ���ƶ�����
			while(status == -1)//����ʱ������ѡ��
				Red.Choose(MoveID, Board.Color, Board.Board, status);//��ɫ���ѡ���ƶ�����
			if (status == 1)
				Black.Refresh(Board.Color);
			Board.Show();//������ʾ����
			CurPlayer = 0;
		}
		else
		{
			cin.get();  
			cout << "Player �� Considering...."<<endl;
			int MoveID = -1;
			int status = 0;//��ʾ�ƶ����յ�
			Black.Choose(MoveID, Board.Color, Board.Board, status);//��ɫ���ѡ���ƶ�����
			while (status == -1)//����ʱ������ѡ��
				Black.Choose(MoveID, Board.Color, Board.Board, status);//��ɫ���ѡ���ƶ�����
			if (status == 1)
				Red.Refresh(Board.Color);
			Board.Show();//������ʾ����
			CurPlayer = 1;
		}
		RedKingRow = Red.Chesses[0]->GetCurRow();
		RedKingCol = Red.Chesses[0]->GetCurCol();
		BlackKingRow = Black.Chesses[0]->GetCurRow();
		BlackKingCol = Black.Chesses[0]->GetCurCol();
	}
	if (Red.Chesses[0]->GetLive())
		cout << "Winner is Red!" << endl << endl;
	else
		cout << "Winner is Black!" << endl << endl;
}