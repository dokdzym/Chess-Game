#include "ChessBoard.h"
ChessBoard::ChessBoard(Player Red, Player Black)
{
	Fill(Red,Black);
	Show();
	cout << endl << endl << endl << endl;
	cout << "A New ChessBoard Built!" << endl;
}

void ChessBoard::Fill(Player Red, Player Black)
{
	for (size_t i = 0; i < 16; ++i)
	{
		Board[Red.Chesses[i]->GetCurRow()][Red.Chesses[i]->GetCurCol()] = Red.Chesses[i]->GetNAME();
		Board[Black.Chesses[i]->GetCurRow()][Black.Chesses[i]->GetCurCol()] = Black.Chesses[i]->GetNAME();

		Color[Red.Chesses[i]->GetCurRow()][Red.Chesses[i]->GetCurCol()] = 1;
		Color[Black.Chesses[i]->GetCurRow()][Black.Chesses[i]->GetCurCol()] = 0;
	}
}

void ChessBoard::Show()
{
	for (size_t row = 0; row < 10; ++row)
	{
		for (size_t col = 0; col < 9; ++col)
		{
			string tmp = Board[row][col];
			for (size_t i = 0; i < tmp.size(); ++i)
				cout << tmp[i];
		}
		cout << endl ;
	}
	cout << endl;
}