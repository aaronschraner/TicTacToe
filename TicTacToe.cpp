/*
 * Program name: Tic Tac Toe
 * Description: A C++ implementation of Tic Tac Toe with adjustable board size
 * Created by Aaron Schraner on  January 18, 2015
 */

#include <cstring>
#include <iostream>
#include <cctype>
#include "consoleGraphics.h"

#ifndef BOARD_SIZE
#define BOARD_SIZE 3
#else
#if BOARD_SIZE > 9
#pragma message( "WARNING: board sizes greater than 9 have inaccessible tiles")
#endif
#endif
//#define CLEAR //uncomment to clear console before displaying board

using namespace std;

//output constants
char clearstr[] = {0x1B, 0x5B, 0x48, 0x1B, 0x5B, 0x32, 0x4A};

//function prototypes
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void initboard(char board[BOARD_SIZE][BOARD_SIZE]);
void printHelp();
int getAndPlaceTile(string prompt, char player, char board[BOARD_SIZE][BOARD_SIZE]);
char gameOver(char board[BOARD_SIZE][BOARD_SIZE]);

//main function
int main()
{
	char userResponse;
	bool userWantsToPlay;
	//declarations
	char board[BOARD_SIZE][BOARD_SIZE];
	char playerChar;


	do 
	{
	

	//initialization
	initboard(board);

	//greeting / info
#ifdef CLEAR
	cout << clearstr;
#endif
	cout << "Welcome to Tic Tac Toe!\n";
	cout << "Compiled with board size " << BOARD_SIZE << 'x' << BOARD_SIZE;
#ifdef CLEAR
	cout << " and line clearing";
#endif
	cout << endl;

	playerChar='X'; //player X goes first

	cout << "Enter the coordinates of where you want to place your tile. (x,y)";
	while(!gameOver(board)) 
	{
		//game logic and things
		cout << "\nCurrent game:\n";
		printBoard(board);
		//display current game state
		
		cout << "You are " << playerChar << endl; //indicate whose turn it is
		if(getAndPlaceTile("Choose your spot! ", playerChar, board))
		{
			cout << "Quitting...\n";
			return 0; 
		}
		//get coordinates from user and place tile

#ifdef CLEAR
		cout << clearstr; //clear screen (if CLEAR is defined)
#endif
		playerChar=(playerChar=='X'?'O':'X'); //toggle whose turn it is
	}

	switch(gameOver(board)) //indicate how the game ended
	{
		case 'N':
			cout << "It's a tie!";
			break;
		case 'X':
			cout << "X Wins!" ;
			break;
		case 'O':
			cout << "O Wins!";
			break;
		default:
			cout << "Game ended unexpectedly";
	}

	cout << "\nFinal game:\n\n"; //show the final game board
	printBoard(board);
	cout << endl;

	cout << "Would you like to play again? (y/n)\n> "; //ask if user would like to play again
	cin >> userResponse;
	userWantsToPlay=(userResponse=='y');

	}while(userWantsToPlay);

	//exit
}




void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) //print a tic tac toe board
{
	cout << "  "; //header indent
	for(int x=0;x<BOARD_SIZE;x++)
	{
		cout << "  " << x + 1 << "  " << (x<BOARD_SIZE-1?' ':'\n');
	} //header with line numbers

	
	for(int y=0;y<BOARD_SIZE;y++)
	{
		for(int x=-1;x<BOARD_SIZE;x++) //column -1 is for line numbers
		{
			if(x<0) //line numbers
			{
				cout << "  "; //indent
				for(int i=0;i<6*BOARD_SIZE-1;i++)
					cout << ( i % 6 == 5 && i < 6 * BOARD_SIZE - 1 ? CG_LINE_VERT : ' '); //draw vertical lines
				cout << endl;
				cout << y + 1 << " "; //left column labels
			}
			else
			{
				cout << "  " << board[y][x] << "  "; //draw the tile that's supposed to be here
				if(x!=BOARD_SIZE-1)
					cout << CG_LINE_VERT; //draw the last vertical line if we're not on the right edge of the board
				else
					cout << endl;
			}
		}

		if(y!=BOARD_SIZE-1) //as long as we're not on the bottom row
		{
			cout << "  "; //indent

			for(int i=0;i<6*BOARD_SIZE-1;i++)
				cout << (i%6==5&&i<6*BOARD_SIZE-1?CG_LINE_VERT:' '); //print vertical lines

			cout << endl << "  "; //indent

			for(int i=0;i<6*BOARD_SIZE-1;i++)
				cout << (i%6==5&&i<6*BOARD_SIZE-1?CG_CROSS:CG_LINE_HOR); //print horizontal line with crosses and bars

			cout << endl;
		}
	}
	cout << "  "; //indent

	for(int i=0;i<6*BOARD_SIZE-1;i++)
		cout << (i%6==5&&i<6*BOARD_SIZE-1?CG_LINE_VERT:' '); //print last set of vertical bars

	cout << endl;
}


bool tryPlacePiece(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char player) //attempt to place a tile at given coordinates
{

	//ensure the values are within the board boundaries
	if(y < BOARD_SIZE && y >= 0 && x < BOARD_SIZE && x >= 0)
	{

		//if the desired spot is blank, put the piece and return success
		if(board[y][x] == ' ')
		{
			board[y][x] = player;
			return false; //no error
		}
		else
		{
			cout << "Space already taken.\n";
			return true; //space already taken
		}
	}
	else
		return true; //return error (coords out of bounds)
}

void initboard(char board[BOARD_SIZE][BOARD_SIZE])
{
	for(int i=0;i<BOARD_SIZE;i++)
		for(int b=0;b<BOARD_SIZE;b++)
			board[i][b]=' ';
}

char gameOver(char board[][BOARD_SIZE]) //game over logic goes here
{
	char cline='N';
	//cline holds the last character read in the board.
	//it is initialized at the beginning of each line parse.
	//if the board value at the current position is equal to cline, do nothing
	//if it is not equal to cline, set cline to 'N' and keep searching.
	//if cline is 'X' or 'O' at the end of the line, return the winner.
	//
	for(int x=0;x<BOARD_SIZE;x++) //test all possible vertical lines
	{
		for(int y=0;y<BOARD_SIZE;y++)
		{
			if(y==0)
			{
				cline=board[x][y];
			}
			else if(board[x][y]!=cline)
			{
				cline='N';
			}
		}
		if(cline=='X' || cline == 'O')
			return cline;

	}

	for(int y=0;y<BOARD_SIZE;y++) //test all possible horizontal lines
	{
		for(int x=0;x<BOARD_SIZE;x++)
		{
			if(x==0)
			{
				cline=board[x][y];
			}
			else if(board[x][y]!=cline)
			{
				cline='N';
			}
		}
		if(cline=='X' || cline == 'O')
			return cline;

	}
	
	for(int d=0;d<BOARD_SIZE;d++) //test diagonal (top left to bottom right)
	{
		if(d==0)
			cline=board[d][d];
		else if(board[d][d]!=cline)
			cline='N';
	}
	if(cline=='X'||cline=='O')
		return cline;

	for(int d=0;d<BOARD_SIZE;d++)//test diagonal (top right to bottom left)
	{
		if(d==0)
			cline=board[BOARD_SIZE-1-d][d];
		else if(board[BOARD_SIZE-1-d][d]!=cline)
			cline='N';
	}
	if(cline=='X'||cline=='O')
		return cline;

	//find if board is completely filled
	bool hasempty=false;
	for(int i=0;i<BOARD_SIZE;i++)
	{
		for(int x=0;x<BOARD_SIZE;x++)
			hasempty |= (board[x][i]==' '); 
	}
	if(!hasempty)
		return 'N'; //no winner

	// if no winner was found and the board is not full, return that the game is still going
	return false;
}

void printHelp()
{
	//help message
	cout << "Enter the coordinates of the tile you want to place your piece in and hit enter.\n\"x,y\" (without quotes) " << endl;
	//etc
}

//handle all game input
//(help, number guide, tile placing)
int getAndPlaceTile(string prompt, char player, char board[BOARD_SIZE][BOARD_SIZE])
{
	char chSpace[3];
	int x=-1,y=-1;
	do
	{
		cout << prompt << "\n> ";
		cin >> chSpace;
		if(
				chSpace[0]<'1'+BOARD_SIZE &&
				chSpace[0]>'0'&&
				chSpace[2]<'1'+BOARD_SIZE &&
				chSpace[2]>'0')
		{
			x=chSpace[0]-'0'-1;
			y=chSpace[2]-'0'-1;
		}
		else
		{
			switch(chSpace[0]) //non-move input processing
			{
				case 'h':
				case 'H':
					printHelp();
					break;
				case 'q':
				case 'Q':
					return 1;
					//cout << "Ctrl+C to quit \n";
					break;
				default:
					cout << "Invalid input.\n (H for help)\n";
					break;
			}
		}

	}
	while(tryPlacePiece(board, x, y,player)); //break loop on success
	return 0;
}

