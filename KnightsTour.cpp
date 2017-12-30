/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	A Knights Tour
//
//Dev Env:	Visual Studio
//
//Description: Recursion Program.
//
//
//The program has no answers for a board of size 3 or 4.
//On a size 5 board if the knight is started in position 3,3 there are 64 solutions.
//If the knight is started in position 1,1 on a size 5 board there are there are 304 solutions.
//
//When all solutions have been found, "All done... Thanks for playing Knights Tour" prints to the screen.
//
=======================================================================================================================*/
#include <iostream>
#include <iomanip>

using namespace std;


const int MAX_SIZE = 7;

struct Board
{
	int board[MAX_SIZE][MAX_SIZE];
	int size;
};
void solveKnightsTour(Board someBoard, int row, int col, int currentMoveNumber = 1);
void printBoard(Board someBoard);

void main()
{
	int startRow, startCol;
	//int solutionCount = 0;

	Board myBoard;

	cout<<"The Knights Tour Solver Have Fun!\n\n";
	cout<<"Enter a board size between (3-7): ";
	cin>>myBoard.size;
	while(myBoard.size < 3 || myBoard.size > MAX_SIZE)
	{
		cout<<"Enter a board size between (3-7): ";
		cin>>myBoard.size;
	}

	cout<<"Enter a starting position (row col): ";
	cin>> startRow >> startCol;

	//validate user input for starting position
	while(startRow < 1 || startCol < 1 || startRow > myBoard.size || startCol > myBoard.size)
	{
		cout<<"Enter a starting position (row col): ";
		cin>> startRow >> startCol;
	}

	//initialize the board with values
	for(int x=0; x<myBoard.size; x++)
		for(int y=0; y<myBoard.size; y++)
			myBoard.board[x][y] = 99;

	//set starting position
	myBoard.board[startRow-1][startCol-1] = 1;

	//printBoard(myBoard);

	cout<< "Thinking.....\n\n";
	
	solveKnightsTour(myBoard, startRow-1, startCol-1);

	//keep console open
	cout<<"All done... Thanks for playing Knights Tour\n";
	cin.get();
	cin.get();
}

//================================================================
// Description:  
//	Recursively solves the knights tour using brute force.  
//	Prints any solutions if finds.
// Args:
//   board (I/O) - the board we’re working with 
//		(board with previous moves and size)
//   row (I) - the row we’re going to attempt to place the knight on this move.
//   col (I) - the column we’re going to attempt place the knight on this move.
//   currentMoveNumber (I) - the move we’re making 
//	(1=first placement, 16=last placement on 4x4 board)
//     Note: row and col may be invalid (<0 or >=boardsize) 
//		or already taken (<currentMoveNum)
//  Returns: 
//	The number of solutions the given board and move leads to
//===============================================================
void solveKnightsTour(Board someBoard, int row, int col, int currentMoveNumber)
{
	//come up with a potential move and see if it is valid if so move the knight 
	const int MOVE[8][2] = {-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};
	int solutionCount = 0;

	//validate move
	if(row < 0 || row >= someBoard.size || col < 0 || col >= someBoard.size || someBoard.board[row][col] < currentMoveNumber)
		return;

	someBoard.board[row][col] = currentMoveNumber;

	//is board full
	if(currentMoveNumber == someBoard.size * someBoard.size)
	{
		printBoard(someBoard);
		return;
	}
	
	currentMoveNumber++;

	//try all possible moves
	for(int x=0; x<8; x++)
		solveKnightsTour(someBoard, row + MOVE[x][0], col + MOVE [x][1], currentMoveNumber);
	return;
}
//======================================================================
// Description:
//	Prints the board
//
// Args:
//	board (I) - the board in use
//
//=======================================================================
void printBoard(Board someBoard)
{
	static int solutionCount = 1;
	
	cout<<"Solution #"<<solutionCount++;
	for(int x=0; x<someBoard.size; x++)
	{
		cout<<endl;
		for(int y=0; y<someBoard.size; y++)
			cout<<setfill('0')<<setw(2)<<someBoard.board[x][y]<< " ";
	}
	cout <<endl<<endl;
}
