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
	int CurPlayer = 1;//红棋先走
	//以上初始化棋盘和首发玩家

	cout << "GameStart!" << endl;
	int RedKingRow = 9;
	int RedKingCol = 4;
	int BlackKingRow = 0;
	int BlackKingCol = 4;
	//以上初始化将帅位置

	while (Board.Color[RedKingRow][RedKingCol] == 1 && Board.Color[BlackKingRow][BlackKingCol] == 0) //双方的将帅都活着
	{
		cout << "Press Enter to move a random chess!" << endl << endl;
		if (CurPlayer == 1)
		{
			cin.get();
			cout << "Player 红 Considering...." << endl;
			int MoveID = -1;
			int status = 0;//表示移动到空地
			Red.Choose(MoveID, Board.Color, Board.Board, status);//红色玩家选出移动棋子
			while(status == -1)//出错时，重新选择
				Red.Choose(MoveID, Board.Color, Board.Board, status);//红色玩家选出移动棋子
			if (status == 1)
				Black.Refresh(Board.Color);
			Board.Show();//重新显示棋盘
			CurPlayer = 0;
		}
		else
		{
			cin.get();  
			cout << "Player 黑 Considering...."<<endl;
			int MoveID = -1;
			int status = 0;//表示移动到空地
			Black.Choose(MoveID, Board.Color, Board.Board, status);//红色玩家选出移动棋子
			while (status == -1)//出错时，重新选择
				Black.Choose(MoveID, Board.Color, Board.Board, status);//红色玩家选出移动棋子
			if (status == 1)
				Red.Refresh(Board.Color);
			Board.Show();//重新显示棋盘
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