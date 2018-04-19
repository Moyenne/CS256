#include <stdio.h>

/*
 * source.c
 *
 *  Created on: Apr 17, 2018
 *      Author: Moyenne
 */

void changeArray(int *array[], int position)
{
	int input;

	printf("Now, input an integer value for the %d position in the array.\n", position);

	fflush(stdout);
	scanf("%d", input);

	array[position] = input;
}

int main()
{
	int *ptr = NULL;

	int arraySize;

	printf("Welcome to the array reverser. Let's start with the size of the array (non-negative, non-zero).\n");

	fflush(stdout);
	scanf("%d", &arraySize);

	if(arraySize < 1)
	{
		printf("Whoops, a mistake. Try again.\n");
	}
	else
	{
		int array[arraySize];

		ptr = &array;

		for(int x = 0; x < arraySize; x++)
		{
			//changeArray(ptr, x);
			array[x] = x;
		}

		int arrayCopy[arraySize];

		for(int x = 0; x < arraySize; x++)
		{
			arrayCopy[x] = array[arraySize - (1 + x)];
		}

		for(int x = 0; x < arraySize; x++)
		{
			printf("%d\n", arrayCopy[x]);
		}
	}

	return ptr;
}
