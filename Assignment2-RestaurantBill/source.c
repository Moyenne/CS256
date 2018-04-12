#include <stdio.h>

/*
 * source.c
 *
 *  Created on: Apr 10, 2018
 *      Author: Moyenne
 */

int main()
{
	/**
	 * The following are constant values that are not altered,
	 * which brings to question why I didn't make them constants.
	 */
	double mealCharge = 88.67;
	double taxRate = 0.0675;
	double tipRate = .2;

	/**
	 * Declaring variables that will be used in the final output.
	 */
	double taxAmount, tipAmount, totalCharge;

	/**
	 * The main calculations for the 3 declared variables, which
	 * utilizes the 'constants' and the newly declared variables.
	 */
	taxAmount = mealCharge * taxRate;
	tipAmount = (mealCharge + taxAmount) * tipRate;
	totalCharge = mealCharge + taxAmount + tipAmount;

	/**
	 * Just some print statements with their respective amounts
	 * from the variables that were altered above.
	 */
	printf("You bill is:\n");
	printf("Initial meal charge: %f\n", mealCharge);
	printf("Total tax amount: %f\n", taxAmount);
	printf("Total tip amount: %f\n", tipAmount);
	printf("Total meal charge: %f\n", totalCharge);

	return 0;
}
