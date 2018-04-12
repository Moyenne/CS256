#include <stdio.h>

/*
 * source.c
 *
 *  Created on: Apr 11, 2018
 *      Author: Moyenne
 */

int main()
{
	for(int x = 1; x < 11; x++)
	{
		for(int y = 0; y < x; y++)
		{
			printf("+");
		}
		printf("\n");
	}

	printf("\n");

	for(int x = 10; x > 0; x--)
	{
		for(int y = 0; y < x; y++)
		{
			printf("+");
		}
		printf("\n");
	}

	return 0;
}
