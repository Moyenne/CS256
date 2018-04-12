#include <stdio.h>

/*
 * source.c
 *
 *  Created on: Apr 10, 2018
 *      Author: Moyenne
 */

int main()
{
	int sharesBought = 1000;
	double pricePerShare = 45.5;
	double totalStockPrice = sharesBought * pricePerShare;
	double commissionPercentage = .02;
	double totalCommission = totalStockPrice * commissionPercentage;

	int sharesSold = 1000;
	double pricePerShare2 = 56.9;
	double totalStockPrice2 = sharesSold * pricePerShare2;
	double commissionPercentage2 = .02;
	double totalCommission2 = totalStockPrice2 * commissionPercentage2;

	double totalProfit = totalStockPrice2 - (totalStockPrice + totalCommission + totalCommission2);

	printf("Joe spent a total of $%f purchasing stock.\n", totalStockPrice);
	printf("Joe spent a total of $%f on his initial commission.\n", totalCommission);
	printf("Joe received a total of $%f selling stock.\n", totalStockPrice2);
	printf("Joe spent a total of $%f on his second commission.\n", totalCommission2);
	printf("Joe had a total profit of $%f.\n", totalProfit);

	return 0;
}
