#include <iostream>
#include<windows.h>
#include <iomanip>
#include <ctime>
//#include <SFML/Graphics.hpp>


using namespace std;

const int grid = 8;


// GAME OVER FUNCTION SATRTS //
int  gameover()
{
	system("Color 6");
	cout << setw(50) << " King Dies " << endl;
	cout << setw(53) << "Player 1 Wins!!";
	exit(0);
}

int  gameover_1()
{
	system("Color 6");
	cout << setw(50) << " King Dies " << endl;
	cout << setw(53) << "Player 2 Wins!!";

	exit(0);
}
// GAME OVER FUNCTION  ENDS //




// PRINTING CHESSBOARD FUNCTION SATRTS //

void print_chess_board(char(*chess_board)[grid]) {

	cout << "   ";

	for (int col = 0; col < grid; col++) {

		cout << " " << col << "  ";
	}
	cout << endl << endl;

	for (int row = 0; row < grid; row++) {
		cout << row << "  ";

		for (int col = 0; col < grid; col++) {
			if (islower(chess_board[row][col])) {

				cout << "\033[31m";
			}
			else {

				cout << "\033[37m";
			}

			cout << " " << chess_board[row][col] << "  ";
			cout << "\033[0m";
		}

		cout << endl << endl;
	}
}

// PRINTING CHESSBOARD FUNCTION ENDS //

// CHESSBOARD CHECKING FUNCTION STARTS //

void print_chess_board_check(char(*chess_board)[grid]) {

	cout << "   ";

	for (int col = 0; col < grid; col++) {

		cout << " " << col << "  ";
	}
	cout << endl << endl;

	for (int row = 0; row < grid; row++) {
		cout << row << "  ";

		for (int col = 0; col < grid; col++) {
			if (islower(chess_board[row][col])) {

				cout << "\033[31m";
			}
			else {

				cout << "\033[37m";
			}

			cout << " " << chess_board[row][col] << "  ";
			cout << "\033[0m";
		}

		cout << endl << endl;
	}
}
// CHESSBOARD CHECKING FUNCTION ENDS //

 // VALIDITY CHECK FUNCTION STARTS //
bool move_validity(int row, int col) {


	return (row >= 0 && row < grid&& col >= 0 && col < grid);

}
// VALIDITY CHECK FUNCTION ENDS //

  //CHECKMATE FUNCTION STARTS //



bool isCheckmate(char(*chess_board)[grid]) {
	int temp1 = 0, temp2 = 0;

	for (int row = 0; row < grid; row++) {

		for (int col = 0; col < grid; col++) {

			if (chess_board[row][col] == 'K') {

				temp1 = row;
				temp2 = col;
			}
		}
	}

	int movements[8][2] = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};

	for (int i = 0; i < 8; i++) {

		int tempRow = temp1 + movements[i][0];
		int tempCol = temp2 + movements[i][1];

		if (tempRow >= 0 && tempRow < grid && tempCol >= 0 && tempCol < grid) {

			if (chess_board[tempRow][tempCol] == '-') {

				return false;
			}
		}
	}

	return true;
}

bool print_king(char(*chess_board)[grid])
{

	int temp1 = 0, temp2 = 0;

	for (int row = 0; row < grid; row++) {

		for (int col = 0; col < grid; col++) {

			if (chess_board[row][col] == 'k') {

				temp1 = row;
				temp2 = col;
			}
		}
	}

	int movements[8][2] = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};

	for (int i = 0; i < 8; i++) {

		int tempRow = temp1 + movements[i][0];
		int tempCol = temp2 + movements[i][1];

		if (tempRow >= 0 && tempRow < grid && tempCol >= 0 && tempCol < grid) {

			if (chess_board[tempRow][tempCol] == 'K') {

				return false;
			}
		}
	}

	return true;


}

bool print_king_k(char(*chess_board)[grid]) {

	int temp1 = 0, temp2 = 0;

	for (int row = 0; row < grid; row++) {

		for (int col = 0; col < grid; col++) {

			if (chess_board[row][col] == 'K') {

				temp1 = row;
				temp2 = col;
			}
		}
	}

	int movements[8][2] = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};

	for (int i = 0; i < 8; i++) {

		int tempRow = temp1 + movements[i][0];
		int tempCol = temp2 + movements[i][1];

		if (tempRow >= 0 && tempRow < grid && tempCol >= 0 && tempCol < grid) {

			if (chess_board[tempRow][tempCol] == 'k') {

				return false;
			}
		}
	}

	return true;


}

//CHECKMATE FUNCTION ENDS //


// KING FUNCTION STARTS //

void moves_king(char(*board)[8], int x, int y) {

	int movements[8][2] = {

		//x = rows of the chess board
		//y = columns of the chess board

		{x - 1, y - 1},
		{x - 1, y},
		{x - 1, y + 1},
		{x, y - 1},
		{x, y + 1},
		{x + 1, y - 1},
		{x + 1, y},
		{x + 1, y + 1}
	};

	cout << "Possible moves for the king at position << {" << x << ", " << y << "}:" << endl;


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			int temp1 = 0;
			int temp2 = 0;
			temp1 = movements[i][j];
			temp2 = movements[i][j + 1];



			if (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
				if (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
					if (board[temp1][temp2] != '-')
					{
						if (board[temp1][temp2] == 'r' || board[temp1][temp2] == 'n' || board[temp1][temp2] == 'b' || board[temp1][temp2] == 'q' || board[temp1][temp2] == 'k' || board[temp1][temp2] == 'Q' || board[temp1][temp2] == 'N' || board[temp1][temp2] == 'B' || board[temp1][temp2] == 'R') {
						}
					}
					else
					{

						board[temp1][temp2] = '*';
						if (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
						}

					}
					cout << "{" << temp1 << " , " << temp2 << "}" << endl;

				}

			}
		}

	}
}
void moves_king_clear(char(*board)[8], int x, int y) {

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == '*')
			{
				board[i][j] = '-';
			}

			else
				continue;

		}

	}
}

// KING FUNCTION ENDS //


  //QUEEN FUNCTION START//

void moves_queen_clear(char(*board)[8], int x, int y)
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == '*')
			{
				board[i][j] = '-';
			}

			else
				continue;

		}

	}

}
void moves_queen(char(*board)[8], int x, int y) {

	int movements[8][2] = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};

	cout << "Possible moves for the Queen at position {" << x << ", " << y << "}: " << endl;

	for (int i = 0; i < 8; i++) {
		int temp1 = x + movements[i][0];
		int temp2 = y + movements[i][1];

		while (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
			if (board[temp1][temp2] != '-')
			{
				if (board[temp1][temp2] == 'r' || board[temp1][temp2] == 'n' || board[temp1][temp2] == 'b' || board[temp1][temp2] == 'q' || board[temp1][temp2] == 'k' || board[temp1][temp2] == 'K' || board[temp1][temp2] == 'N' || board[temp1][temp2] == 'B' || board[temp1][temp2] == 'R')
				{

				}
			}
			else
			{
				board[temp1][temp2] = '*';
				if (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
				}
			}

			cout << "{" << temp1 << ", " << temp2 << "}" << endl;

			temp1 += movements[i][0];
			temp2 += movements[i][1];
		}
	}
}


// QUEEN FUNCTION ENDS //


// BISHOP FUNCTION STARTS //
void moves_bishop_clear(char(*board)[8], int x, int y)
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == '*')
			{
				board[i][j] = '-';
			}

			else
				continue;

		}

	}

}
void moves_bishop(char(*board)[8], int x, int y) {

	int movements[4][2] = {
		{-1, -1},
		{-1, 1},
		{1, -1},
		{1, 1}
	};

	cout << "Possible moves for the bishop at position {" << x << ", " << y << "}: " << endl;

	for (int i = 0; i < 4; i++) {
		int temp1 = x + movements[i][0];
		int temp2 = y + movements[i][1];

		while (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
			if (board[temp1][temp2] != '-')
			{
				if (board[temp1][temp2] == 'r' || board[temp1][temp2] == 'n' || board[temp1][temp2] == 'b' || board[temp1][temp2] == 'q' || board[temp1][temp2] == 'k' || board[temp1][temp2] == 'K' || board[temp1][temp2] == 'Q' || board[temp1][temp2] == 'N' || board[temp1][temp2] == 'B' || board[temp1][temp2] == 'R')
				{

				}
			}
			else
			{
				board[temp1][temp2] = '*';
				if (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
				}
			}

			cout << "{" << temp1 << ", " << temp2 << "}" << endl;

			temp1 += movements[i][0];
			temp2 += movements[i][1];
		}
	}
}

// BISHOP FUNCTION STARTS //			


// KNIGHT FUNCTION STARTS //
void moves_knight_clear(char(*board)[8], int x, int y)
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == '*')
			{
				board[i][j] = '-';
			}

			else
				continue;

		}

	}
}
void moves_knight(char board[][8], int x, int y) {

	int movements[8][2] = {

		{x - 2, y + 1},
		{x - 1, y + 2},
		{x + 1, y + 2},
		{x + 2, y + 1},
		{x + 2, y - 1},
		{x + 1, y - 2},
		{x - 1, y - 2},
		{x - 2, y - 1}
	};


	cout << "Possible moves for the knight at position << {" << x << ", " << y << "}:" << endl;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			int temp1 = 0;
			int temp2 = 0;
			temp1 = movements[i][j];
			temp2 = movements[i][j + 1];


			if (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
				if (board[temp1][temp2] != '-')
				{
					if (board[temp1][temp2] == 'r' || board[temp1][temp2] == 'n' || board[temp1][temp2] == 'b' || board[temp1][temp2] == 'q' || board[temp1][temp2] == 'k' || board[temp1][temp2] == 'K' || board[temp1][temp2] == 'Q' || board[temp1][temp2] == 'N' || board[temp1][temp2] == 'B' || board[temp1][temp2] == 'R')
					{

					}
				}
				else
				{

					board[temp1][temp2] = '*';
					if (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
					}

				}
				cout << "{" << temp1 << " , " << temp2 << "}" << endl;


			}
		}
	}
}

// KNIGHT FUNCTION ENDS //


// ROCK FUNCTION STARTS //
void moves_rock_clear(char(*board)[8], int x, int y)
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (board[i][j] == '*')
			{
				board[i][j] = '-';
			}

			else
				continue;

		}

	}
}
void moves_rock(char(*board)[8], int x, int y) {

	int movements[4][2] = {

		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}

	};


	cout << "Possible moves for the Rock at position {" << x << ", " << y << "}: " << endl;

	for (int i = 0; i < 4; i++) {
		int temp1 = x + movements[i][0];
		int temp2 = y + movements[i][1];

		while (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
			if (board[temp1][temp2] != '-')
			{
				if (board[temp1][temp2] == 'r' || board[temp1][temp2] == 'n' || board[temp1][temp2] == 'b' || board[temp1][temp2] == 'q' || board[temp1][temp2] == 'k' || board[temp1][temp2] == 'N' || board[temp1][temp2] == 'K' || board[temp1][temp2] == 'Q' || board[temp1][temp2] == 'B' || board[temp1][temp2] == 'R')
				{

				}
			}
			else
			{
				board[temp1][temp2] = '*';
				if (temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
				}
			}

			cout << "{" << temp1 << ", " << temp2 << "}" << endl;

			temp1 += movements[i][0];
			temp2 += movements[i][1];
		}
	}
}


// ROCK FUNCTION ENDS //

// CHESS GAME FUNCTION STARTS //
void chess_game()
{

	cout << setw(50) << "Loading ";
	char x = 219;
	for (int i = 0; i < 30; i++)
	{
		cout << x;
		Sleep(5);
	}
	system("cls");


	cout << endl;
	cout << setw(85) << "<<<--- THIS IS A 2 PLAYER GAME --->>>" << endl;
	cout << endl;
	cout << setw(81) << "PLAYER 1 WILL SAVE THE KING" << endl << endl;
	cout << setw(82) << "PLAYER 2 WILL ATTACK THE KING" << endl;



	char chess_board[grid][grid] = {
		//initializing the chess board grid
{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
{'-', '-', '-', '-', '-', '-', '-', '-'},
{'-', '-', '-', '-', '-', '-', '-', '-'},
{'-', '-', '-', '-', '-', '-', '-', '-'},
{'-', '-', '-', '-', '-', '-', '-', '-'},
{'-', '-', '-', '-', '-', '-', '-', '-'},
{'-', '-', '-', '-', '-', '-', '-', '-'},
{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}

	};


	print_chess_board(chess_board);

	while (true) {

		int rowForKing = 0, colForKing = 0, rowForQueen = 0, colForQueen = 0, rowForBishop = 0, colForBishop = 0, rowForKnight = 0, colForKnight = 0, rowForRock = 0, colForRock = 0, i = 1;

		bool player_1 = true;

		do {
			if (player_1 == true)
			{
				cout << setw(80) << "PLAYER 1, SELECT YOUR MOVE!" << endl << endl;
				cout << setw(80) << "Your Pieces are K, Q, B, N, R" << endl;
				int  star_choice;

				cout << "Select your Piece: " << endl
					<< "[1] King   (K)" << endl
					<< "[2] Queen  (Q)" << endl
					<< "[3] Bishop (B)" << endl
					<< "[4] Rock   (R)" << endl
					<< "[5] Knight (N)" << endl;
				cout << endl;
				cout << "Enter (1 - 5): ";

				cin >> star_choice;

				switch (star_choice)
				{
				case 1:
				{
					// CASE FOR KING

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForKing;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForKing;
						cout << endl;

						if (chess_board[rowForKing][colForKing] != 'K');
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board[rowForKing][colForKing] != 'K');

					chess_board[rowForKing][colForKing] = 'K';

					cout << "Initial position of the king: {" << rowForKing << ", " << colForKing << "}" << endl;

					moves_king(chess_board, rowForKing, colForKing);
					print_chess_board_check(chess_board);

					moves_king_clear(chess_board, rowForKing, colForKing);



					int newrowForKing, newcolForKing;

					cout << "New position for the king:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKing;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKing;
					cout << endl;


					int moves[8][2] = {

						{rowForKing - 1, colForKing - 1},

						{rowForKing - 1, colForKing},

						{rowForKing - 1, colForKing + 1},

						{rowForKing, colForKing - 1},

						{rowForKing, colForKing + 1},

						{rowForKing + 1, colForKing - 1},

						{rowForKing + 1, colForKing},

						{rowForKing + 1, colForKing + 1}

					};


					for (int i = 0; i < 8; i++) {

						if (newrowForKing == moves[i][0] && newcolForKing == moves[i][1]) {

							valid = true;
							break;

						}
					}

					if (valid) {

						chess_board[rowForKing][colForKing] = '-';
						chess_board[newrowForKing][newcolForKing] = 'K';
						rowForKing = newrowForKing;
						colForKing = newcolForKing;

						cout << "Updated chess board:" << endl;
					}

					else {
						cout << "Invalid move for the King. Try again." << endl;
					}


					print_chess_board(chess_board);


				}

				break;

				case 2:
				{
					// CASE FOR QUEEN

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForQueen;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForQueen;
						cout << endl;

						if (chess_board[rowForQueen][colForQueen] != 'Q')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board[rowForQueen][colForQueen] != 'Q');
					chess_board[rowForQueen][colForQueen] = 'Q';

					cout << "Initial position of the Queen: {" << rowForQueen << ", " << colForQueen << "}" << endl;

					moves_queen(chess_board, rowForQueen, colForQueen);
					print_chess_board_check(chess_board);
					moves_queen_clear(chess_board, rowForQueen, colForQueen);

					int newrowForQueen, newcolForQueen;

					cout << "New position for the Queen:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForQueen;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForQueen;
					cout << endl;

					if (newrowForQueen >= 0 && newrowForQueen < 8 && newcolForQueen >= 0 && newcolForQueen < 8)
					{
						if (chess_board[newrowForQueen][newcolForQueen] != '-')
						{

						}
						else
						{
							chess_board[rowForQueen][colForQueen] = '-';
							chess_board[newrowForQueen][newcolForQueen] = 'Q';
						}
					}


					if (chess_board[newrowForQueen][newcolForQueen] == 'k')
					{

						chess_board[rowForQueen][colForQueen] = '-';
						chess_board[newrowForQueen][newcolForQueen] = 'Q';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board);

						gameover();
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board);




				}
				break;

				case 3:
				{
					// CASE FOR BISHOP

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForBishop;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForBishop;
						cout << endl;

						if (chess_board[rowForBishop][colForBishop] != 'B')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board[rowForBishop][colForBishop] != 'B');


					chess_board[rowForBishop][colForBishop] = 'B';

					cout << "Initial position of the Bishop: {" << rowForBishop << ", " << colForBishop << "}" << endl;

					moves_bishop(chess_board, rowForBishop, colForBishop);
					print_chess_board_check(chess_board);
					moves_bishop_clear(chess_board, rowForBishop, colForBishop);

					int newrowForBishop, newcolForBishop;

					cout << "New position for the Bishop:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForBishop;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForBishop;
					cout << endl;

					if (newrowForBishop >= 0 && newrowForBishop < 8 && newcolForBishop >= 0 && newcolForBishop < 8)
					{
						if (chess_board[newrowForBishop][newcolForBishop] != '-')
						{

						}
						else
						{
							chess_board[rowForBishop][colForBishop] = '-';
							chess_board[newrowForBishop][newcolForBishop] = 'B';
						}
					}

					if (chess_board[newrowForBishop][newcolForBishop] == 'k')
					{
						chess_board[rowForBishop][colForBishop] = '-';
						chess_board[newrowForBishop][newcolForBishop] = 'B';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board);

						gameover();
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board);

				}
				break;

				case 4:
				{
					// CASE FOR ROCK

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForRock;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForRock;
						cout << endl;

						if (chess_board[rowForRock][colForRock] != 'R')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board[rowForRock][colForRock] != 'R');

					chess_board[rowForRock][colForRock] = 'R';

					cout << "Initial position of the Rock: {" << rowForRock << ", " << colForRock << "}" << endl;

					moves_rock(chess_board, rowForRock, colForRock);
					print_chess_board_check(chess_board);
					moves_rock_clear(chess_board, rowForRock, colForRock);

					int newrowForRock, newcolForRock;

					cout << "New position for the Rock:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForRock;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForRock;
					cout << endl;

					if (newrowForRock >= 0 && newrowForRock < 8 && newcolForRock >= 0 && newcolForRock < 8)
					{
						if (chess_board[newrowForRock][newcolForRock] != '-')
						{
							cout << "Invalid move. The new position is occupied." << endl;
						}
						else
						{
							chess_board[rowForRock][colForRock] = '-';
							chess_board[newrowForRock][newcolForRock] = 'R';
						}
					}

					if (chess_board[newrowForRock][newcolForRock] == 'k')
					{
						chess_board[rowForRock][colForRock] = '-';
						chess_board[newrowForRock][newcolForRock] = 'R';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board);

						gameover();
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board);
				}
				break;

				case 5:
				{
					// CASE FOR KNIGHT

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForKnight;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForKnight;
						cout << endl;

						if (chess_board[rowForKnight][colForKnight] = 'N')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board[rowForKnight][colForKnight] != 'N');
					chess_board[rowForKnight][colForKnight] = 'N';

					cout << "Initial position of the knight: {" << rowForKnight << ", " << colForKnight << "}" << endl;

					moves_knight(chess_board, rowForKnight, colForKnight);
					print_chess_board_check(chess_board);

					moves_knight(chess_board, rowForKnight, colForKnight);
					moves_knight_clear(chess_board, rowForKnight, colForKnight);

					int newrowForKnight, newcolForKnight;

					cout << "New position for the knight:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKnight;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKnight;
					cout << endl;

					int moves[8][2] = {

						 {rowForKnight - 2, colForKnight + 1},
						 {rowForKnight - 1, colForKnight + 2},
						 {rowForKnight + 1, colForKnight + 2},
						 {rowForKnight + 2, colForKnight + 1},
						 {rowForKnight + 2, colForKnight - 1},
						 {rowForKnight + 1, colForKnight - 2},
						 {rowForKnight - 1, colForKnight - 2},
						 {rowForKnight - 2, colForKnight - 1}

					};



					if (newrowForKnight >= 0 && newrowForKnight < 8 && newcolForKnight >= 0 && newcolForKnight < 8)
					{
						if (chess_board[newrowForKnight][newrowForKnight] != '-')
						{

						}
						else
						{
							chess_board[rowForKnight][colForKnight] = '-';
							chess_board[newrowForKnight][newcolForKnight] = 'N';
						}
					}

					if (chess_board[newrowForKnight][newcolForKnight] == 'k')
					{
						chess_board[rowForKnight][colForKnight] = '-';
						chess_board[newrowForKnight][newcolForKnight] = 'N';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board);

						gameover();
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board);

				}

				default:
					cout << "Choose Valid Piece" << endl << endl;
				}

				player_1 = false;

			}


			if (player_1 == false)
			{

				cout << setw(80) << "PLAYER 2, SELECT YOUR MOVE!" << endl << endl;
				cout << setw(80) << "Your Pieces are k, q, b, n, r" << endl;
				int  star_choice;

				cout << "Select your Piece: " << endl
					<< "[1] King   (k)" << endl
					<< "[2] Queen  (q)" << endl
					<< "[3] Bishop (b)" << endl
					<< "[4] Rock   (r)" << endl
					<< "[5] Knight (n)" << endl;
				cout << endl;
				cout << "Enter (1 - 5): ";

				cin >> star_choice;

				switch (star_choice)
				{
				case 1:
				{
					//CASE FOR KING

					bool valid = false;

					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForKing;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForKing;
						cout << endl;

						if (chess_board[rowForKing][colForKing] != 'k');
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board[rowForKing][colForKing] != 'k');





					chess_board[rowForKing][colForKing] = 'k';

					cout << "Initial position of the king: {" << rowForKing << ", " << colForKing << "}" << endl;

					moves_king(chess_board, rowForKing, colForKing);
					print_chess_board_check(chess_board);

					moves_king_clear(chess_board, rowForKing, colForKing);



					int newrowForKing, newcolForKing;

					cout << "New position for the king:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKing;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKing;
					cout << endl;


					int moves[8][2] = {

						{rowForKing - 1, colForKing - 1},

						{rowForKing - 1, colForKing},

						{rowForKing - 1, colForKing + 1},

						{rowForKing, colForKing - 1},

						{rowForKing, colForKing + 1},

						{rowForKing + 1, colForKing - 1},

						{rowForKing + 1, colForKing},

						{rowForKing + 1, colForKing + 1}

					};


					for (int i = 0; i < 8; i++) {

						if (newrowForKing == moves[i][0] && newcolForKing == moves[i][1]) {

							valid = true;
							break;

						}
					}

					if (valid) {
						//new position of the king if it's a valid move
						chess_board[rowForKing][colForKing] = '-';
						chess_board[newrowForKing][newcolForKing] = 'k';
						rowForKing = newrowForKing;
						colForKing = newcolForKing;

						cout << "Updated chess board:" << endl;
					}

					else {
						cout << "Invalid move for the King. Try again." << endl;
					}


					print_chess_board(chess_board);

				}

				break;

				case 2:
				{
					//CASE FOR QUEEN

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForQueen;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForQueen;
						cout << endl;
						if (chess_board[rowForQueen][colForQueen] != 'q')
						{
							cout << "Invalid Position" << endl;
						}
					} while (chess_board[rowForQueen][colForQueen] != 'q');
					chess_board[rowForQueen][colForQueen] = 'q';

					cout << "Initial position of the Queen: {" << rowForQueen << ", " << colForQueen << "}" << endl;

					moves_queen(chess_board, rowForQueen, colForQueen);
					print_chess_board_check(chess_board);
					moves_queen_clear(chess_board, rowForQueen, colForQueen);

					int newrowForQueen, newcolForQueen;

					cout << "New position for the Queen:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForQueen;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForQueen;
					cout << endl;

					if (newrowForQueen >= 0 && newrowForQueen < 8 && newcolForQueen >= 0 && newcolForQueen < 8)
					{
						if (chess_board[newrowForQueen][newcolForQueen] != '-') {

						}
						else
						{
							chess_board[rowForQueen][colForQueen] = '-';
							chess_board[newrowForQueen][newcolForQueen] = 'q';
						}
					}

					if (chess_board[newrowForQueen][newcolForQueen] == 'K')
					{
						chess_board[rowForQueen][colForQueen] = '-';
						chess_board[newrowForQueen][newcolForQueen] = 'q';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board);

						gameover_1();
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board);

				}
				break;

				case 3:
				{
					//CASE FOR BISHOP

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForBishop;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForBishop;
						cout << endl;

						if (chess_board[rowForBishop][colForBishop] != 'b')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board[rowForBishop][colForBishop] != 'b');
					chess_board[rowForBishop][colForBishop] = 'b';

					cout << "Initial position of the Bishop: {" << rowForBishop << ", " << colForBishop << "}" << endl;

					moves_bishop(chess_board, rowForBishop, colForBishop);
					print_chess_board_check(chess_board);
					moves_bishop_clear(chess_board, rowForBishop, colForBishop);

					int newrowForBishop, newcolForBishop;

					cout << "New position for the Bishop:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForBishop;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForBishop;
					cout << endl;

					if (newrowForBishop >= 0 && newrowForBishop < 8 && newcolForBishop >= 0 && newcolForBishop < 8)
					{
						if (chess_board[newrowForBishop][newcolForBishop] != '-')
						{

						}
						else
						{
							chess_board[rowForBishop][colForBishop] = '-';
							chess_board[newrowForBishop][newcolForBishop] = 'b';
						}
					}

					if (chess_board[newrowForBishop][newcolForBishop] == 'K')
					{

						chess_board[rowForBishop][colForBishop] = '-';
						chess_board[newrowForBishop][newcolForBishop] = 'b';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board);

						gameover_1();
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board);

				}
				break;

				case 4:
				{
					//CASE FOR ROCK

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForRock;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForRock;
						cout << endl;

						if (chess_board[rowForRock][colForRock] != 'r')
						{
							cout << "invalid input.Try again." << endl;
						}

					} while (chess_board[rowForRock][colForRock] != 'r');
					chess_board[rowForRock][colForRock] = 'r';

					cout << "Initial position of the Rock: {" << rowForRock << ", " << colForRock << "}" << endl;

					moves_rock(chess_board, rowForRock, colForRock);
					print_chess_board_check(chess_board);
					moves_rock_clear(chess_board, rowForRock, colForRock);

					int newrowForRock, newcolForRock;

					cout << "New position for the Rock:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForRock;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForRock;
					cout << endl;

					if (newrowForRock >= 0 && newrowForRock < 8 && newcolForRock >= 0 && newcolForRock < 8)
					{
						if (chess_board[newrowForRock][newcolForRock] != '-')
						{

						}
						else
						{
							chess_board[rowForRock][colForRock] = '-';
							chess_board[newrowForRock][newcolForRock] = 'r';
						}
					}

					if (chess_board[newrowForRock][newcolForRock] == 'K')
					{
						chess_board[rowForRock][colForRock] = '-';
						chess_board[newrowForRock][newcolForRock] = 'r';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board);

						gameover_1();
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board);
				}
				break;

				case 5:
				{
					//CASE FOR KNIGHT

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForKnight;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForKnight;
						cout << endl;

						if (chess_board[rowForKnight][colForKnight] != 'n')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board[rowForKnight][colForKnight] != 'n');
					chess_board[rowForKnight][colForKnight] = 'n';

					cout << "Initial position of the knight: {" << rowForKnight << ", " << colForKnight << "}" << endl;

					moves_knight(chess_board, rowForKnight, colForKnight);
					print_chess_board_check(chess_board);

					moves_knight(chess_board, rowForKnight, colForKnight);
					moves_knight_clear(chess_board, rowForKnight, colForKnight);

					int newrowForKnight, newcolForKnight;

					cout << "New position for the knight:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKnight;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKnight;
					cout << endl;

					int moves[8][2] = {

						 {rowForKnight - 2, colForKnight + 1},
						 {rowForKnight - 1, colForKnight + 2},
						 {rowForKnight + 1, colForKnight + 2},
						 {rowForKnight + 2, colForKnight + 1},
						 {rowForKnight + 2, colForKnight - 1},
						 {rowForKnight + 1, colForKnight - 2},
						 {rowForKnight - 1, colForKnight - 2},
						 {rowForKnight - 2, colForKnight - 1}

					};

					for (int i = 0; i < 8; i++) {

						if (newrowForKnight == moves[i][0] && newcolForKnight == moves[i][1]) {

							valid = true;
							break;

						}
					}

					if (valid) {
						//new position of the king if it's a valid move
						chess_board[rowForKnight][colForKnight] = '-';
						chess_board[newrowForKnight][newcolForKnight] = 'n';
						rowForKnight = newrowForKnight;
						colForKnight = newcolForKnight;

						cout << "Updated chess board:" << endl;
					}

					else {

					}

					if (chess_board[newrowForKnight][newcolForKnight] == 'K')
					{
						chess_board[rowForKnight][colForKnight] = '-';
						chess_board[newrowForKnight][newcolForKnight] = 'n';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board);
						gameover_1();
					}

					print_chess_board(chess_board);
				}



				}

			}


			// FUNCTION THAT CHECKS CHECKMATE //
			if (isCheckmate(chess_board)) {
				system("Color 6");

				cout << "King is in CHECKMATE!" << endl
					<< "GAME OVER!!!" << endl;
				exit(0);

			}


			// Prompt the player to continue or exit the game
			char choice;

			cout << "Do you want to continue? (y/n): ";
			cin >> choice;


			if (choice == 'y' || choice == 'Y') {
				player_1 = true;
				break;
			}

			else if (choice == 'n' || choice == 'N')
			{
				system("cls");
				exit(0);
			}

			else
				cout << "Invalid Option" << endl;
		} while (i < 0);

	}
}
// CHESS GAME FUNCTION ENDS HERE //

// KING GAME FUNCTION STARTS HERE //

void king_game()
{

	cout << setw(50) << "Loading ";
	char x = 219;
	for (int i = 0; i < 30; i++)
	{
		cout << x;
		Sleep(15);
	}
	system("cls");
	cout << setw(85) << "<<<--- THIS IS A CHECK-MATE GAME --->>>" << endl;
	cout << endl;
	cout << setw(78) << "PLAYER 1 WILL SAVE THE KING" << endl << endl;
	cout << setw(79) << "PLAYER 2 WILL ATTACK THE KING" << endl;

	int rowForKing = 0, colForKing = 0, rowForQueen = 0, colForQueen = 0, rowForBishop = 0, colForBishop = 0, rowForKnight = 0, colForKnight = 0, rowForRock = 0, colForRock = 0, i = 1;

	char chess_board_2[grid][grid] = {
		//initializing the chess board grid
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},


	};

	do {

		int  choice;
		//choice for the pieces
		cout << "Select your  Piece : " << endl
			<< "[1] Queen  (1 only)" << endl
			<< "[2] Bishop (2 only)" << endl
			<< "[3] Rock   (2 only)" << endl
			<< "[4] Knight (2 only)" << endl;
		cout << endl;
		cout << "Enter (1 - 4): ";

		cin >> choice;

		switch (choice)
		{
		case 1: {

			cout << setw(50) << "Loading ";
			char x = 219;
			for (int i = 0; i < 30; i++)
			{
				cout << x;
				Sleep(15);
			}
			system("cls");

			bool player_1 = true;

			char chess_board_2[grid][grid] = {
				//initializing the chess board grid
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', 'q', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', 'K', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},


			};



			print_chess_board(chess_board_2);



			do {
				if (player_1 == true)
				{
					bool valid = false;

					cout << setw(80) << "PLAYER 1, ENTER YOUR MOVE!" << endl << endl;
					cout << setw(75) << "Your Pieces is K" << endl;
					cout << endl;
					do {
						cout << "Enter King Postion for Row: ";
						cin >> rowForKing;
						cout << endl;
						cout << "Enter King Postion for Column: ";
						cin >> colForKing;
						cout << endl;

						if (chess_board_2[rowForKing][colForKing] != 'K');
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForKing][colForKing] != 'K');

					chess_board_2[rowForKing][colForKing] = 'K';

					cout << "Initial position of the king: {" << rowForKing << ", " << colForKing << "}" << endl;

					moves_king(chess_board_2, rowForKing, colForKing);
					print_chess_board_check(chess_board_2);

					moves_king_clear(chess_board_2, rowForKing, colForKing);



					int newrowForKing, newcolForKing;

					cout << "New position for the king:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKing;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKing;
					cout << endl;


					int moves[8][2] = {

						{rowForKing - 1, colForKing - 1},

						{rowForKing - 1, colForKing},

						{rowForKing - 1, colForKing + 1},

						{rowForKing, colForKing - 1},

						{rowForKing, colForKing + 1},

						{rowForKing + 1, colForKing - 1},

						{rowForKing + 1, colForKing},

						{rowForKing + 1, colForKing + 1}

					};


					for (int i = 0; i < 8; i++) {

						if (newrowForKing == moves[i][0] && newcolForKing == moves[i][1]) {

							valid = true;
							break;

						}
					}

					if (valid) {
						//new position of the king if it's a valid move
						chess_board_2[rowForKing][colForKing] = '-';
						chess_board_2[newrowForKing][newcolForKing] = 'K';
						rowForKing = newrowForKing;
						colForKing = newcolForKing;

						cout << "Updated chess board:" << endl;
					}

					else {
						cout << "Invalid move for the King. Try again." << endl;
					}

					print_chess_board(chess_board_2);
					player_1 = false;
				}


				if (player_1 == false)
				{
					bool valid = false;
					cout << setw(80) << "PLAYER 2, ENTER YOUR MOVE!" << endl << endl;
					cout << setw(75) << "Your Pieces is Q" << endl;
					do {
						cout << "Enter Queen Postion for Row: ";
						cin >> rowForQueen;
						cout << endl;
						cout << "Enter Queen Postion for Column: ";
						cin >> colForQueen;
						cout << endl;

						if (chess_board_2[rowForQueen][colForQueen] != 'q')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForQueen][colForQueen] != 'q');

					chess_board_2[rowForQueen][colForQueen] = 'q';

					cout << "Initial position of the Queen: {" << rowForQueen << ", " << colForQueen << "}" << endl;

					moves_queen(chess_board_2, rowForQueen, colForQueen);
					print_chess_board_check(chess_board_2);
					moves_queen_clear(chess_board_2, rowForQueen, colForQueen);

					int newrowForQueen, newcolForQueen;

					cout << "New position for the Queen:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForQueen;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForQueen;
					cout << endl;

					if (newrowForQueen >= 0 && newrowForQueen < 8 && newcolForQueen >= 0 && newcolForQueen < 8)
					{
						if (chess_board_2[newrowForQueen][newcolForQueen] != '-')
						{
						}
						else
						{
							chess_board_2[rowForQueen][colForQueen] = '-';
							chess_board_2[newrowForQueen][newcolForQueen] = 'q';
						}
					}

					if (chess_board_2[newrowForQueen][newcolForQueen] == 'K')
					{
						chess_board_2[rowForQueen][colForQueen] = '-';
						chess_board_2[newrowForQueen][newcolForQueen] = 'q';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board_2);

						//KING DIES//
						gameover_1();
						//KING DIES//
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board_2);

					player_1 = true;
				}
			} while (i < 10);
		}
			  break;
		case 2: {

			cout << setw(50) << "Loading ";
			char x = 219;
			for (int i = 0; i < 30; i++)
			{
				cout << x;
				Sleep(15);
			}
			system("cls");

			bool player_1 = true;

			char chess_board_2[grid][grid] = {
				//initializing the chess board grid
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', 'K', '-'},
			{'-', 'b', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', 'b', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},


			};



			print_chess_board(chess_board_2);




			do {
				if (player_1 == true)
				{
					bool valid = false;

					cout << setw(80) << "PLAYER 1, ENTER YOUR MOVE!" << endl << endl;
					cout << setw(75) << "Your Pieces is K" << endl;
					cout << endl;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForKing;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForKing;
						cout << endl;

						if (chess_board_2[rowForKing][colForKing] != 'K');
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForKing][colForKing] != 'K');





					chess_board_2[rowForKing][colForKing] = 'K';

					cout << "Initial position of the king: {" << rowForKing << ", " << colForKing << "}" << endl;

					moves_king(chess_board_2, rowForKing, colForKing);
					print_chess_board_check(chess_board_2);

					moves_king_clear(chess_board_2, rowForKing, colForKing);



					int newrowForKing, newcolForKing;

					cout << "New position for the king:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKing;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKing;
					cout << endl;


					int moves[8][2] = {

						{rowForKing - 1, colForKing - 1},

						{rowForKing - 1, colForKing},

						{rowForKing - 1, colForKing + 1},

						{rowForKing, colForKing - 1},

						{rowForKing, colForKing + 1},

						{rowForKing + 1, colForKing - 1},

						{rowForKing + 1, colForKing},

						{rowForKing + 1, colForKing + 1}

					};


					for (int i = 0; i < 8; i++) {

						if (newrowForKing == moves[i][0] && newcolForKing == moves[i][1]) {

							valid = true;
							break;

						}
					}

					if (valid) {
						//new position of the king if it's a valid move
						chess_board_2[rowForKing][colForKing] = '-';
						chess_board_2[newrowForKing][newcolForKing] = 'K';
						rowForKing = newrowForKing;
						colForKing = newcolForKing;

						cout << "Updated chess board:" << endl;
					}

					print_chess_board(chess_board_2);
					player_1 = false;
				}


				if (player_1 == false)
				{
					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForBishop;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForBishop;
						cout << endl;
						if (chess_board_2[rowForBishop][colForBishop] != 'b')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForBishop][colForBishop] != 'b');
					chess_board_2[rowForBishop][colForBishop] = 'b';

					cout << "Initial position of the Bishop: {" << rowForBishop << ", " << colForBishop << "}" << endl;

					moves_bishop(chess_board_2, rowForBishop, colForBishop);
					print_chess_board_check(chess_board_2);
					moves_bishop_clear(chess_board_2, rowForBishop, colForBishop);

					int newrowForBishop, newcolForBishop;

					cout << "New position for the Bishop:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForBishop;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForBishop;
					cout << endl;

					if (newrowForBishop >= 0 && newrowForBishop < 8 && newcolForBishop >= 0 && newcolForBishop < 8)
					{
						if (chess_board_2[newrowForBishop][newcolForBishop] != '-') {

						}
						else
						{
							chess_board_2[rowForBishop][colForBishop] = '-';
							chess_board_2[newrowForBishop][newcolForBishop] = 'b';
						}
					}

					if (chess_board_2[newrowForBishop][newcolForBishop] == 'K')
					{

						chess_board_2[rowForBishop][colForBishop] = '-';
						chess_board_2[newrowForBishop][newcolForBishop] = 'b';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board_2);

						//KING DIES//
						gameover_1();
						//KING DIES//
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board_2);
					player_1 = true;
				}
			} while (i < 10);

		}
			  break;
		case 3: {

			cout << setw(50) << "Loading ";
			char x = 219;
			for (int i = 0; i < 30; i++)
			{
				cout << x;
				Sleep(15);
			}
			system("cls");
			bool player_1 = true;

			char chess_board_2[grid][grid] = {
				//initializing the chess board grid
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', 'r', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', 'K', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', 'r', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},


			};



			print_chess_board(chess_board_2);



			do {
				if (player_1 == true)
				{
					bool valid = false;

					cout << setw(80) << "PLAYER 1, ENTER YOUR MOVE!" << endl << endl;
					cout << setw(75) << "Your Pieces is K" << endl;
					cout << endl;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForKing;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForKing;
						cout << endl;

						if (chess_board_2[rowForKing][colForKing] != 'K')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForKing][colForKing] != 'K');

					chess_board_2[rowForKing][colForKing] = 'K';

					cout << "Initial position of the king: {" << rowForKing << ", " << colForKing << "}" << endl;

					moves_king(chess_board_2, rowForKing, colForKing);
					print_chess_board_check(chess_board_2);

					moves_king_clear(chess_board_2, rowForKing, colForKing);



					int newrowForKing, newcolForKing;

					cout << "New position for the king:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKing;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKing;
					cout << endl;


					int moves[8][2] = {

						{rowForKing - 1, colForKing - 1},

						{rowForKing - 1, colForKing},

						{rowForKing - 1, colForKing + 1},

						{rowForKing, colForKing - 1},

						{rowForKing, colForKing + 1},

						{rowForKing + 1, colForKing - 1},

						{rowForKing + 1, colForKing},

						{rowForKing + 1, colForKing + 1}

					};


					for (int i = 0; i < 8; i++) {

						if (newrowForKing == moves[i][0] && newcolForKing == moves[i][1]) {

							valid = true;
							break;

						}
					}

					if (valid) {
						//new position of the king if it's a valid move
						chess_board_2[rowForKing][colForKing] = '-';
						chess_board_2[newrowForKing][newcolForKing] = 'K';
						rowForKing = newrowForKing;
						colForKing = newcolForKing;

						cout << "Updated chess board:" << endl;
					}

					else {
						cout << "Invalid move for the King. Try again." << endl;
					}


					print_chess_board(chess_board_2);
					player_1 = false;
				}

				if (player_1 == false)
				{
					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForRock;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForRock;
						cout << endl;
						if (chess_board_2[rowForRock][colForRock] != 'r')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForRock][colForRock] != 'r');


					chess_board_2[rowForRock][colForRock] = 'r';

					cout << "Initial position of the Rock: {" << rowForRock << ", " << colForRock << "}" << endl;

					moves_rock(chess_board_2, rowForRock, colForRock);
					print_chess_board_check(chess_board_2);
					moves_rock_clear(chess_board_2, rowForRock, colForRock);

					int newrowForRock, newcolForRock;

					cout << "New position for the Rock:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForRock;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForRock;
					cout << endl;

					if (newrowForRock >= 0 && newrowForRock < 8 && newcolForRock >= 0 && newcolForRock < 8)
					{
						if (chess_board_2[newrowForRock][newcolForRock] != '-')
						{

						}
						else
						{
							chess_board_2[rowForRock][colForRock] = '-';
							chess_board_2[newrowForRock][newcolForRock] = 'r';
						}
					}

					if (chess_board_2[newrowForRock][newcolForRock] == 'K')
					{
						chess_board_2[rowForRock][colForRock] = '-';
						chess_board_2[newrowForRock][newcolForRock] = 'r';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board_2);

						//KING DIES//
						gameover_1();
						//KING DIES//
					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board_2);
					player_1 = true;
				}
			} while (i < 10);
		}
			  break;
		case 4:
		{
			cout << setw(50) << "Loading ";
			char x = 219;
			for (int i = 0; i < 30; i++)
			{
				cout << x;
				Sleep(15);
			}
			system("cls");
			bool player_1 = true;



			char chess_board_2[grid][grid] = {
				//initializing the chess board grid
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', 'K', '-', '-'},
			{'-', 'n', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', 'n', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},
			{'-', '-', '-', '-', '-', '-', '-', '-'},


			};

			print_chess_board(chess_board_2);





			do {
				if (player_1 == true)
				{
					bool valid = false;

					cout << setw(80) << "PLAYER 1, ENTER YOUR MOVE!" << endl << endl;
					cout << setw(75) << "Your Pieces is K" << endl;
					cout << endl;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForKing;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForKing;
						cout << endl;
						if (chess_board_2[rowForKing][colForKing] != 'K')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForKing][colForKing] != 'K');





					chess_board_2[rowForKing][colForKing] = 'K';

					cout << "Initial position of the king: {" << rowForKing << ", " << colForKing << "}" << endl;

					moves_king(chess_board_2, rowForKing, colForKing);
					print_chess_board_check(chess_board_2);

					moves_king_clear(chess_board_2, rowForKing, colForKing);



					int newrowForKing, newcolForKing;

					cout << "New position for the king:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKing;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKing;
					cout << endl;


					int moves[8][2] = {

						{rowForKing - 1, colForKing - 1},

						{rowForKing - 1, colForKing},

						{rowForKing - 1, colForKing + 1},

						{rowForKing, colForKing - 1},

						{rowForKing, colForKing + 1},

						{rowForKing + 1, colForKing - 1},

						{rowForKing + 1, colForKing},

						{rowForKing + 1, colForKing + 1}

					};


					for (int i = 0; i < 8; i++) {

						if (newrowForKing == moves[i][0] && newcolForKing == moves[i][1]) {

							valid = true;
							break;

						}
					}

					if (valid) {

						//new position of the king if it's a valid move
						chess_board_2[rowForKing][colForKing] = '-';
						chess_board_2[newrowForKing][newcolForKing] = 'K';
						rowForKing = newrowForKing;
						colForKing = newcolForKing;

						cout << "Updated chess board:" << endl;
					}

					else {
						cout << "Invalid move for the King. Try again." << endl;
					}


					print_chess_board(chess_board_2);
					player_1 = false;
				}


				if (player_1 == false)
				{
					bool valid = false;
					do {
						cout << "Enter Postion for Knight Row: ";
						cin >> rowForKnight;
						cout << endl;
						cout << "Enter Postion for Knight Column: ";
						cin >> colForKnight;

						if (chess_board_2[rowForKnight][colForKnight] != 'n')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForKnight][colForKnight] != 'n');

					cout << "Initial position of the knight: {" << rowForKnight << ", " << colForKnight << "}" << endl;

					moves_knight(chess_board_2, rowForKnight, colForKnight);
					print_chess_board_check(chess_board_2);

					moves_knight(chess_board_2, rowForKnight, colForKnight);
					moves_knight_clear(chess_board_2, rowForKnight, colForKnight);

					int newrowForKnight, newcolForKnight;

					cout << "New position for the knight:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKnight;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKnight;
					cout << endl;

					int moves[8][2] = {

						 {rowForKnight - 2, colForKnight + 1},
						 {rowForKnight - 1, colForKnight + 2},
						 {rowForKnight + 1, colForKnight + 2},
						 {rowForKnight + 2, colForKnight + 1},
						 {rowForKnight + 2, colForKnight - 1},
						 {rowForKnight + 1, colForKnight - 2},
						 //{rowForKnight - 1, colForKnight - 2},
						 {rowForKnight - 2, colForKnight - 1}

					};

					for (int i = 0; i < 8; i++) {

						if (newrowForKnight == moves[i][0] && newcolForKnight == moves[i][1]) {

							valid = true;
							break;

						}
					}



					if (chess_board_2[newrowForKnight][newcolForKnight] == 'K')
					{
						chess_board_2[rowForKnight][colForKnight] = '-';
						chess_board_2[newrowForKnight][newcolForKnight] = 'n';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board_2);

						//KING DIES//
						gameover_1();
						//KING DIES//
					}

					print_chess_board(chess_board_2);
					player_1 = true;
				}

			} while (i < 10);


		}
		break;
		}
	} while (i < 10);
}
// KING GAME FUNCTION ENDS HERE //

// CHECK GAME FUNCTION STARTS HERE //

void check_game()
{
	cout << setw(50) << "Loading ";
	char x = 219;
	for (int i = 0; i < 30; i++)
	{
		cout << x;
		Sleep(15);
	}
	system("cls");
	cout << setw(80) << "This Scenario will be for check-mate" << endl;
	cout << setw(70) << "Player 1 is King" << endl;
	cout << setw(88) << " Player 2 has control over a Bishop, Knight, Queen, & Rock " << endl;
	cout << endl;


	char chess_board_2[grid][grid] = {
		//initializing the chess board grid
	{'-', '-', '-', 'n', '-', 'k', '-', 'r'},
	{'-', '-', '-', '-', '-', '-', 'K', '-'},
	{'-', '-', 'b', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', 'q', '-', 'n'},
	{'-', '-', '-', 'b', 'r', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},


	};
	print_chess_board(chess_board_2);


	while (true) {

		int rowForKing = 0, colForKing = 0, rowForQueen = 0, colForQueen = 0, rowForBishop = 0, colForBishop = 0, rowForKnight = 0, colForKnight = 0, rowForRock = 0, colForRock = 0, i = 1;

		bool player_1 = true;

		do {
			if (player_1 == true)
			{
				cout << setw(80) << "PLAYER 1, SELECT YOUR MOVE!" << endl << endl;
				cout << setw(80) << "Your Pieces is K" << endl;
				int  star_choice;


				// CASE FOR KING

				bool valid = false;
				do {
					cout << "Enter Postion for Row: ";
					cin >> rowForKing;
					cout << endl;
					cout << "Enter Postion for Column: ";
					cin >> colForKing;
					cout << endl;

					if (chess_board_2[rowForKing][colForKing] != 'K');
					{
						cout << "invalid input.Try again." << endl;
					}
				} while (chess_board_2[rowForKing][colForKing] != 'K');

				chess_board_2[rowForKing][colForKing] = 'K';

				cout << "Initial position of the king: {" << rowForKing << ", " << colForKing << "}" << endl;

				moves_king(chess_board_2, rowForKing, colForKing);
				print_chess_board_check(chess_board_2);

				moves_king_clear(chess_board_2, rowForKing, colForKing);



				int newrowForKing, newcolForKing;

				cout << "New position for the king:" << endl;                    // user input
				cout << "Enter Row" << endl;
				cin >> newrowForKing;
				cout << endl;
				cout << "Enter Column" << endl;
				cin >> newcolForKing;
				cout << endl;


				int moves[8][2] = {

					{rowForKing - 1, colForKing - 1},

					{rowForKing - 1, colForKing},

					{rowForKing - 1, colForKing + 1},

					{rowForKing, colForKing - 1},

					{rowForKing, colForKing + 1},

					{rowForKing + 1, colForKing - 1},

					{rowForKing + 1, colForKing},

					{rowForKing + 1, colForKing + 1}

				};


				for (int i = 0; i < 8; i++) {

					if (newrowForKing == moves[i][0] && newcolForKing == moves[i][1]) {

						valid = true;
						break;

					}
				}

				if (valid) {

					chess_board_2[rowForKing][colForKing] = '-';
					chess_board_2[newrowForKing][newcolForKing] = 'K';
					rowForKing = newrowForKing;
					colForKing = newcolForKing;

					cout << "Updated chess board:" << endl;
				}

				else {
					cout << "Invalid move for the King. Try again." << endl;
				}


				print_chess_board(chess_board_2);

				player_1 = false;
			}





			if (player_1 == false)
			{

				cout << setw(80) << "PLAYER 2, SELECT YOUR MOVE!" << endl << endl;
				cout << setw(80) << "Your Pieces are  q, b, n, r" << endl;
				int  option;

				cout << "Select your Piece: " << endl
					<< "[1] Queen  (q)" << endl
					<< "[2] Bishop (b)" << endl
					<< "[3] Rock   (r)" << endl
					<< "[4] Knight (n)" << endl;
				cout << endl;
				cout << "Enter (1 - 4): ";

				cin >> option;

				switch (option)
				{

				case 1:
				{
					//CASE FOR QUEEN

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForQueen;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForQueen;
						cout << endl;
						if (chess_board_2[rowForQueen][colForQueen] != 'q')
						{
							cout << "Invalid Position" << endl;
						}
					} while (chess_board_2[rowForQueen][colForQueen] != 'q');
					chess_board_2[rowForQueen][colForQueen] = 'q';

					cout << "Initial position of the Queen: {" << rowForQueen << ", " << colForQueen << "}" << endl;

					moves_queen(chess_board_2, rowForQueen, colForQueen);
					print_chess_board_check(chess_board_2);
					moves_queen_clear(chess_board_2, rowForQueen, colForQueen);

					int newrowForQueen, newcolForQueen;

					cout << "New position for the Queen:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForQueen;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForQueen;
					cout << endl;

					if (newrowForQueen >= 0 && newrowForQueen < 8 && newcolForQueen >= 0 && newcolForQueen < 8)
					{
						if (chess_board_2[newrowForQueen][newcolForQueen] != '-') {

						}
						else
						{
							chess_board_2[rowForQueen][colForQueen] = '-';
							chess_board_2[newrowForQueen][newcolForQueen] = 'q';
						}
					}

					if (chess_board_2[newrowForQueen][newcolForQueen] == 'K')
					{
						chess_board_2[rowForQueen][colForQueen] = '-';
						chess_board_2[newrowForQueen][newcolForQueen] = 'q';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board_2);

						//KING DIES//
						gameover_1();
						//KING DIES//

					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board_2);

				}
				break;

				case 2:
				{
					//CASE FOR BISHOP

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForBishop;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForBishop;
						cout << endl;

						if (chess_board_2[rowForBishop][colForBishop] != 'b')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForBishop][colForBishop] != 'b');
					chess_board_2[rowForBishop][colForBishop] = 'b';

					cout << "Initial position of the Bishop: {" << rowForBishop << ", " << colForBishop << "}" << endl;

					moves_bishop(chess_board_2, rowForBishop, colForBishop);
					print_chess_board_check(chess_board_2);
					moves_bishop_clear(chess_board_2, rowForBishop, colForBishop);

					int newrowForBishop, newcolForBishop;

					cout << "New position for the Bishop:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForBishop;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForBishop;
					cout << endl;

					if (newrowForBishop >= 0 && newrowForBishop < 8 && newcolForBishop >= 0 && newcolForBishop < 8)
					{
						if (chess_board_2[newrowForBishop][newcolForBishop] != '-')
						{

						}
						else
						{
							chess_board_2[rowForBishop][colForBishop] = '-';
							chess_board_2[newrowForBishop][newcolForBishop] = 'b';
						}
					}

					if (chess_board_2[newrowForBishop][newcolForBishop] == 'K')
					{

						chess_board_2[rowForBishop][colForBishop] = '-';
						chess_board_2[newrowForBishop][newcolForBishop] = 'b';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board_2);
						//KING DIES//
						gameover_1();
						//KING DIES//

					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board_2);

				}
				break;

				case 3:
				{
					//CASE FOR ROCK

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForRock;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForRock;
						cout << endl;

						if (chess_board_2[rowForRock][colForRock] != 'r')
						{
							cout << "invalid input.Try again." << endl;
						}

					} while (chess_board_2[rowForRock][colForRock] != 'r');
					chess_board_2[rowForRock][colForRock] = 'r';

					cout << "Initial position of the Rock: {" << rowForRock << ", " << colForRock << "}" << endl;

					moves_rock(chess_board_2, rowForRock, colForRock);
					print_chess_board_check(chess_board_2);
					moves_rock_clear(chess_board_2, rowForRock, colForRock);

					int newrowForRock, newcolForRock;

					cout << "New position for the Rock:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForRock;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForRock;
					cout << endl;

					if (newrowForRock >= 0 && newrowForRock < 8 && newcolForRock >= 0 && newcolForRock < 8)
					{
						if (chess_board_2[newrowForRock][newcolForRock] != '-')
						{

						}
						else
						{
							chess_board_2[rowForRock][colForRock] = '-';
							chess_board_2[newrowForRock][newcolForRock] = 'r';
						}
					}

					if (chess_board_2[newrowForRock][newcolForRock] == 'K')
					{
						chess_board_2[rowForRock][colForRock] = '-';
						chess_board_2[newrowForRock][newcolForRock] = 'r';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board_2);
						//KING DIES//
						gameover_1();
						//KING DIES//

					}

					cout << "Updated chess board:" << endl;
					print_chess_board(chess_board_2);
				}
				break;

				case 4:
				{
					//CASE FOR KNIGHT

					bool valid = false;
					do {
						cout << "Enter Postion for Row: ";
						cin >> rowForKnight;
						cout << endl;
						cout << "Enter Postion for Column: ";
						cin >> colForKnight;
						cout << endl;

						if (chess_board_2[rowForKnight][colForKnight] != 'n')
						{
							cout << "invalid input.Try again." << endl;
						}
					} while (chess_board_2[rowForKnight][colForKnight] != 'n');
					chess_board_2[rowForKnight][colForKnight] = 'n';

					cout << "Initial position of the knight: {" << rowForKnight << ", " << colForKnight << "}" << endl;

					moves_knight(chess_board_2, rowForKnight, colForKnight);
					print_chess_board_check(chess_board_2);

					moves_knight(chess_board_2, rowForKnight, colForKnight);
					moves_knight_clear(chess_board_2, rowForKnight, colForKnight);

					int newrowForKnight, newcolForKnight;

					cout << "New position for the knight:" << endl;                    // user input
					cout << "Enter Row" << endl;
					cin >> newrowForKnight;
					cout << endl;
					cout << "Enter Column" << endl;
					cin >> newcolForKnight;
					cout << endl;

					int moves[8][2] = {

						 {rowForKnight - 2, colForKnight + 1},
						 {rowForKnight - 1, colForKnight + 2},
						 {rowForKnight + 1, colForKnight + 2},
						 {rowForKnight + 2, colForKnight + 1},
						 {rowForKnight + 2, colForKnight - 1},
						 {rowForKnight + 1, colForKnight - 2},
						 {rowForKnight - 1, colForKnight - 2},
						 {rowForKnight - 2, colForKnight - 1}

					};

					for (int i = 0; i < 8; i++) {

						if (newrowForKnight == moves[i][0] && newcolForKnight == moves[i][1]) {

							valid = true;
							break;

						}
					}

					if (valid) {
						//new position of the king if it's a valid move
						chess_board_2[rowForKnight][colForKnight] = '-';
						chess_board_2[newrowForKnight][newcolForKnight] = 'n';
						rowForKnight = newrowForKnight;
						colForKnight = newcolForKnight;

						cout << "Updated chess board:" << endl;
					}

					else {

					}

					if (chess_board_2[newrowForKnight][newcolForKnight] == 'K')
					{
						chess_board_2[rowForKnight][colForKnight] = '-';
						chess_board_2[newrowForKnight][newcolForKnight] = 'n';
						cout << "Updated chess board:" << endl;
						print_chess_board(chess_board_2);
						//KING DIES//
						gameover_1();
						//KING DIES//

					}

					print_chess_board(chess_board_2);
				}



				}

			}


			// FUNCTION THAT CHECKS CHECKMATE //
			if (isCheckmate(chess_board_2)) {
				system("Color 6");

				cout << "King is in CHECKMATE!" << endl
					<< "GAME OVER!!!" << endl;
				exit(0);

			}


			// 
			// 
			// Prompt the player to continue or exit the game
			char choice;

			cout << "Do you want to continue? (y/n): ";
			cin >> choice;


			if (choice == 'y' || choice == 'Y') {
				player_1 = true;
				break;
			}

			else if (choice == 'n' || choice == 'N')
			{
				system("cls");
				exit(0);
			}

			else
				cout << "Invalid Option" << endl;
		} while (i < 0);

	}
}
// CHECK GAME FUNTION ENDS HERE //

// START FUNCTION //

void start()
{
	//system("Color DE");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << setw(80) << "<<<<---- THE CHESS MASTER ----->>>>" << endl << endl;;
	cout << endl;
	cout << setw(50) << "LOADING... ";
	char x = 219;
	for (int i = 0; i < 30; i++)
	{
		cout << x;
		Sleep(60);
	}
	system("cls");





	cout << setw(85) << "<<<--- WELCOME TO THE GAME OF LIFE AND BRAIN --->>>" << endl;
	cout << endl;
	cout << setw(70) << "<<<-- THE CHESS -->>>" << endl;
	int choice_1;
	do {
		cout << endl;
		cout << "What game do you want to play?" << endl << endl
			<< "[1] 2 Player Chess Game" << endl
			<< "[2] Save The King ( with 1 Queen, or 2 Bishop/Knight/Rock)" << endl
			<< "[3] Check-mate Scenario" << endl;
		cout << endl;
		cout << "Enter Option (1-3): ";
		cin >> choice_1;

		if (choice_1 == 1)
			chess_game();

		if (choice_1 == 2)
			king_game();


		if (choice_1 == 3)
			check_game();

		else
			cout << "Invalid Option" << endl;


	} while (choice_1 != 2 && choice_1 != 1 && choice_1 != 3);
}
// START FUNCTION ENDS //

// MAIN FUNCTION STARTS //
int main()
{

	start();

	return 0;
}
// MAIN FUNCTION ENDS //