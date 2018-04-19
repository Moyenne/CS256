#include <stdio.h>

/*
 * source.c
 *
 *  Created on: Apr 15, 2018
 *      Author: Moyenne
 */

int main()
{
	int initialPopulation;
	float birthRate;
	float deathRate;
	int yearsToDisplay;
	double finalPopulation;

	printf("Population Calculator\n");
	printf("Please input an integer value that is greater than or equal to 2 as the initial population.\n");

	fflush(stdout);
	scanf("%d", &initialPopulation);

	if(initialPopulation < 2)
	{
		printf("Whoops, a mistake. Try again.\n");
		abort();
	}

	printf("Please input a float value that is greater than 0 as the birth rate.\n");

	fflush(stdout);
	scanf("%f", &birthRate);

	if(birthRate <= 0)
	{
		printf("Whoops, a mistake. Try again.\n");
		abort();
	}

	printf("Please input a float value that is greater than 0 as the death rate.\n");

	fflush(stdout);
	scanf("%f", &deathRate);

	if(deathRate <= 0)
	{
		printf("Whoops, a mistake. Try again.\n");
		abort();
	}

	printf("Please input an integer value that is greater than or equal to 1 as the number of years to display.\n");

	fflush(stdout);
	scanf("%d", &yearsToDisplay);

	if(yearsToDisplay < 1)
	{
		printf("Whoops, a mistake. Try again.\n");
		abort();
	}

	int nextPopulation = initialPopulation;
	for(int x = yearsToDisplay; x > 0; x--)
	{
		nextPopulation += (birthRate * nextPopulation) - (deathRate * nextPopulation);
	}
	finalPopulation = nextPopulation;

	printf("Initial population: %d.\n", initialPopulation);
	printf("Birth rate: %f.\n", birthRate);
	printf("Death rate: %f.\n", deathRate);
	printf("Years passed: %d.\n", yearsToDisplay);
	printf("Final population: %f.\n", finalPopulation);

	return 0;
}
