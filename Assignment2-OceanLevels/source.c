#include <stdio.h>

/*
 * source.c
 *
 *  Created on: Apr 10, 2018
 *      Author: Moyenne
 */

int main()
{
	double oceanLevelRate = 1.5;

	double fiveYearSpan, sevenYearSpan, tenYearSpan;

	fiveYearSpan = oceanLevelRate * 5;
	sevenYearSpan = oceanLevelRate * 7;
	tenYearSpan = oceanLevelRate * 10;

	printf("The ocean's water level is expected to raise:\n");
	printf("%f millimeters in the next 5 years.\n", fiveYearSpan);
	printf("%f millimeters in the next 7 years.\n", sevenYearSpan);
	printf("%f millimeters in the next 10 years.\n", tenYearSpan);

	return 0;
}
