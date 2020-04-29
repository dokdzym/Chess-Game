#include<iostream>
#include "Judge.h"
using namespace std;
int main()
{
	char again = 'Y';
	while (again == 'Y')
	{
		GameStart();
		cout << "GameOver! Enter Y to play another time. Enter N to quit." << endl <<"Play Again ?  ";
		cin >> again;
	}
	return 0;
}