#include <iostream>
#include <windows.h>
#include <chrono>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


char game[3][3] = { {'_','_','_'},
					{'_','_','_'},
					{'_','_','_'} };


void Showtable (char arraye[3][3]) 
{
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			if (arraye[i][j] == 'X') 
			{
				SetConsoleTextAttribute(hConsole, 5);
				cout << arraye[i][j] << "\t";
				SetConsoleTextAttribute(hConsole, 14);
			}
			if (arraye[i][j] == 'O')
			{
				SetConsoleTextAttribute(hConsole, 9);
				cout << arraye[i][j] << "\t";
				SetConsoleTextAttribute(hConsole, 14);
			}
			if (arraye[i][j] == '_')
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << arraye[i][j] << "\t";
			}

		}
		cout << endl;
		
	}

}

void Putin(char game[][3], int playern)
{
	int row, column;

	while (true)
	{
		cout << "player " << playern << " :" << endl;
		cout << "pls enter ur row" << endl;
		cin >> row;
		cout << "pls enter ur column" << endl;
		cin >> column;
		row--, column--;

		if (0 <= row && row <= 2 && 0 <= column && column <= 2)
		{

			if (game[row][column] == '_')
			{
				if (playern == 1)
				{
					game[row][column] = 'O';
				}
				else 
				{
					game[row][column] = 'X'; 
				}
				break;
			}
			else cout << "cant place here!" << endl;
		}
		else cout << "out of range" << endl;
	}
}

void Putin_AI(char game[][3])
{
	srand(time(0));
	int row, column;
	int rowr = rand();
	int colr = rand() + rand();
	while (true) 
	{
		row = (rowr % 3);
		column = (colr % 4);
		if(game[row][column]=='_') 
		{
			game[row][column] = 'X';
			break;
		}
		if (0 <= row && row <= 2) rowr++;
		if (0 <= column && column <= 2) colr++;
	}
}

int check(char game[][3]) 
{
	int win=0;
	for(int i = 0 ; i < 3 ; i++) 
	{
		if(game[i][0]!='_') 
		{
			if(game[i][0]==game[i][1] && game[i][0] == game[i][2]) 
			{
				win = 1;
				break;
			}
		}
	}

	for(int i = 0 ; i < 3 ; i++) 
	{
		if(game[0][i]!='_') 
		{
			if (game[0][i] == game[1][i] && game[0][i] == game[2][i])
			{
				win = 1;
				break;
			}
		}
	}
	
	if (game[0][0] != '_')
	{
		if (game[1][1] == game[0][0] && game[0][0] == game[2][2])
		{
			win = 1;
		}
	}
	if (game[0][2] != '_')
	{
		if (game[1][1] == game[0][2] && game[0][2] == game[2][0])
		{
			win = 1;
		}
	}
	
	return win;
}

int main () 
{
	int AI = 0;
	cout << "If u want to play hotsit with ur friend enter 0 or if u want to play with AI enter 1" << endl;
	cin >> AI;
	auto start = chrono::steady_clock::now();
	Showtable(game);
	int player;
	for(int i = 1 ; i < 10 ; i++) 
	{
		player = i % 2;
		if (player == 0) player = 2;
		if(AI==1 && player == 2) 
		{
			cout << "let me think!" << endl;
			Putin_AI(game);
		}
		else Putin(game, player);
		Showtable(game);
		if(check(game)==1) 
		{
			cout << "the winner is player " << player << "! nice one!" << endl;		
			Sleep(1);
			auto end = chrono::steady_clock::now();
			cout << "Elapsed time in seconds: "
				<< chrono::duration_cast<chrono::seconds>(end - start).count()
				<< " sec";
			system("pause");
			return 0;
		}
	}
	if (check(game) == 1)
	{
		cout << "the winner is player " << player << "! nice one!" << endl;
		Sleep(1);
		auto end = chrono::steady_clock::now();
		cout << "Elapsed time in seconds: "
			<< chrono::duration_cast<chrono::seconds>(end - start).count()
			<< " sec";
		system("pause");
		return 0;
	}
	else 
	{
		cout << "draw looks like u guys cant beat each other! can y?..." << endl;
		Sleep(1);
		auto end = chrono::steady_clock::now();
		cout << "Elapsed time in seconds: "
			<< chrono::duration_cast<chrono::seconds>(end - start).count()
			<< " sec";
		system("pause");
		return 0;
	}

}