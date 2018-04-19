#include <stdio.h>

/*
 * source.c
 *
 *  Created on: Apr 17, 2018
 *      Author: Moyenne
 */

void addX(char board[3][3], int row, int column)
{
	if(board[row][column] == '*')
	{
		board[row][column] = 'X';
	}
	else
	{
		printf("Error detected. Space is already occupied. Try again.\n");
		abort();
	}
}

void addO(char board[3][3], int row, int column)
{
	if(board[row][column] == '*')
	{
		board[row][column] = 'O';
	}
	else
	{
		printf("Error detected. Space is already occupied. Try again.\n");
		abort();
	}
}

void printBoard(char board[3][3])
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
}

int checkBoardX(char board[3][3])
{
	int inARow = 0;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(board[x][y] == 'X')
			{
				inARow++;
			}
		}

		if(inARow == 3)
		{
			return 1;
		}
		else
		{
			inARow = 0;
		}
	}

	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			if(board[x][y] == 'X')
			{
				inARow++;
			}
		}

		if(inARow == 3)
		{
			return 1;
		}
		else
		{
			inARow = 0;
		}
	}

	if(board[1][1] == 'X')
	{
		if(board[0][0] == 'X' && board[2][2] == 'X')
		{
			return 1;
		}
		else if(board[2][0] == 'X' && board[0][2] == 'X')
		{
			return 1;
		}
	}

	return 0;
}

int checkBoardO(char board[3][3])
{
	int inARow = 0;

		for(int x = 0; x < 3; x++)
		{
			for(int y = 0; y < 3; y++)
			{
				if(board[x][y] == 'O')
				{
					inARow++;
				}
			}

			if(inARow == 3)
			{
				return 1;
			}
			else
			{
				inARow = 0;
			}
		}

		for(int y = 0; y < 3; y++)
		{
			for(int x = 0; x < 3; x++)
			{
				if(board[x][y] == 'O')
				{
					inARow++;
				}
			}

			if(inARow == 3)
			{
				return 1;
			}
			else
			{
				inARow = 0;
			}
		}

		if(board[1][1] == 'O')
		{
			if(board[0][0] == 'O' && board[2][2] == 'O')
			{
				return 1;
			}
			else if(board[2][0] == 'O' && board[0][2] == 'O')
			{
				return 1;
			}
		}

		return 0;
}

int main()
{
	char board[3][3];

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			board[x][y] = '*';
		}
	}

	printf("Welcome to Tic Tac Toe!\n");
	printBoard(board);

	int x = 0;

	while(x < 100)
	{
		if(x == 0)
		{
		int row;
		int column;

		printf("Player 1's turn. Start by choosing which row to place your X (0 - 2).\n");

		fflush(stdout);
		scanf("%d", &row);

		if(row < 0 || row > 2)
		{
			printf("Error detected. Invalid row input. Try again.\n");
			x = 101;
		}

		printf("Now choose which column to place your X (0 - 2).\n");

		fflush(stdout);
		scanf("%d", &column);

		if(column < 0 || column > 2)
		{
			printf("Error detected. Invalid column input. Try again.\n");
			x = 101;
		}

		addX(board, row, column);

		if(checkBoardX(board) == 1)
		{
			printf("Congratulations! Player 1 wins!\n");
			x = 101;
		}
		else
		{
			printf("The game continues.\n");
		}

		printBoard(board);

		x++;
		}
		else
		{
			int row;
					int column;

					printf("Player 2's turn. Start by choosing which row to place your O (0 - 2).\n");

					fflush(stdout);
					scanf("%d", &row);

					if(row < 0 || row > 2)
					{
						printf("Error detected. Invalid row input. Try again.\n");
						x = 101;
					}

					printf("Now choose which column to place your O (0 - 2).\n");

					fflush(stdout);
					scanf("%d", &column);

					if(column < 0 || column > 2)
					{
						printf("Error detected. Invalid column input. Try again.\n");
						x = 101;
					}

					addO(board, row, column);

					if(checkBoardO(board) == 1)
					{
						printf("Congratulations! Player 2 wins!\n");
						x = 101;
					}
					else
					{
						printf("The game continues.\n");
					}

					printBoard(board);

					x--;
		}
	}

	return 0;
}
