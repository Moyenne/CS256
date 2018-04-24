#include <stdio.h>

/*
 * source.c
 *
 *  Created on: Apr 18, 2018
 *      Author: Moyenne
 */

int totalTicketSale;
double totalProfit;

char seatList[15][30];

float seatPrices[15];

int priceInitialization(int x)
{
	float input;

	printf("Please input a non-negative, double value for the price of seats in row %d.\n", x + 1);

	fflush(stdout);
	scanf("%f", &input);

	if(input < 0)
	{
		printf("Input error, please try again.\n");
		return 0;
	}
	else
	{
		printf("Input accepted, please continue.\n");
		seatPrices[x] = input;
		return 1;
	}
}

void printScreen()
{
	printf("\t\t\tTheater Seating Chart\n");
	printf("\t");
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 10; y++)
		{
			if(y < 9)
			{
				printf("%d ", y + 1);
			}
			else
			{
				printf("0 ");
			}
		}
	}
	printf("\n");
	for(int x = 0; x < 15; x++)
	{
		printf("Row %d\t", x + 1);
		for(int y = 0; y < 30; y++)
		{
			printf("%c ", seatList[x][y]);
		}
		printf("\n");
	}
}

void ticketSale()
{
	float totalSale = 0;
	int numbTickets;

	printf("How many tickets do you plan to sell?\n");

	fflush(stdout);
	scanf("%d", &numbTickets);

	if(numbTickets < 0)
	{
		printf("Error. You cannot sell a negative number of tickets.\n");
	}
	else
	{
		for(int x = 0; x < numbTickets; x++)
		{
			int row;

			printf("Please input the row of the seat being sold.\n");

			fflush(stdout);
			scanf("%d", &row);

			if(row < 0 || row > 14)
			{
				printf("Error, invalid row input detected. Please try again.\n");
				x--;
			}
			else
			{
				float price = seatPrices[row];
				int column;

				printf("Please input the seat number in row %d being sold.\n", row + 1);

				fflush(stdout);
				scanf("%d", &column);

				if(column < 0 || column > 29)
				{
					printf("Error, invalid column input detected. Please try again.\n");
					x--;
				}
				else
				{
					if(seatList[row][column] == '*')
					{
						printf("Error, this seat has already been sold. Please try again.\n");
						x--;
					}
					else
					{
						seatList[row][column] = '*';
						totalTicketSale++;
						totalProfit += price;
						totalSale += price;
					}
				}
			}
		}
	}

	printf("A total of %d tickets were sold for a total of $%f.\n", numbTickets, totalSale);
}

void printProfits()
{
	printf("A total of %d tickets have been sold for a total profit of $%f.\n", totalTicketSale, totalProfit);
}

void printSeatDetails()
{
	int totalAvailable = 0;

	printf("A total of %d seats have been sold.\n", totalTicketSale);
	printf("The number of seats available in ");

	for(int x = 0; x < 15; x++)
	{
		int available = 0;

		printf("Row %d is ", x + 1);

		for(int y = 0; y < 30; y++)
		{
			if(seatList[x][y] == '#')
			{
				available++;
			}
		}

		printf("%d.\n", available);

		totalAvailable += available;
	}

	printf("There are a total of %d seats available in the auditorium.\n", totalAvailable);
}

int main()
{
	for(int x = 0; x < 15; x++)
	{
		for(int y = 0; y < 30; y++)
		{
			seatList[x][y] = '#';
		}
	}

	printf("Welcome to the Theater Seating Program.\n");

	for(int x = 0; x < 15; x++)
	{
		if(priceInitialization(x) == 0)
		{
			x--;
		}
	}

	int x = 0;
	while(x < 1)
	{
		int selection;

		printScreen();

		printf("Please select which operation you would like to perform now (1-4).\n");
		printf("1. Sell Tickets\n");
		printf("2. View Total Profits\n");
		printf("3. View Remaining Seat Details\n");
		printf("4. Exit Application\n");

		fflush(stdout);
		scanf("%d", &selection);

		if(selection == 1)
		{
			ticketSale();
		}
		else if(selection == 2)
		{
			printProfits();
		}
		else if(selection == 3)
		{
			printSeatDetails();
		}
		else if(selection == 4)
		{
			printf("Goodbye.\n");
			return 0;
		}
		else
		{
			printf("Error, invalid selection detected. Please try again.");
		}
	}

	return 0;
}
