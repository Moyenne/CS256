#include <stdio.h>
const double PI = 3.14159;

/*
 * source.c
 *
 *  Created on: Apr 15, 2018
 *      Author: Moyenne
 */

int circle()
{
	float radius;
	double area;

	printf("Please input a non-zero, non-negative value for the circle's radius.\n");

	fflush(stdout);
	scanf("%f", &radius);

	if(radius <= 0)
	{
		printf("Error. Invalid input detected. Please try again with a valid radius value.\n");
	}
	else
	{
		double radius2 = pow(radius, 2);
		area = PI * radius2;
		printf("A circle with a radius of %f has an area of %f.\n", radius, area);
	}

	return 0;
}

int rectangle()
{
	float length;
	float width;
	double area;

	printf("Please input a non-zero, non-negative value for the rectangle's length.\n");

	fflush(stdout);
	scanf("%f", &length);

	if(length <= 0)
	{
		printf("Error. Invalid input detected. Please try again with a valid length value.\n");
	}
	else
	{
		printf("Please input a non-zero, non-negative value for the rectangle's width.\n");

		fflush(stdout);
		scanf("%f", &width);

		if(width <= 0)
		{
			printf("Error. Invalid input detected. Please try again with a valid width value.\n");
		}
		else
		{
			area = length * width;
			printf("A rectangle with a length of %f and a width of %f has an area of %f.\n", length, width, area);
		}
	}

	return 0;
}

int triangle()
{
	float base;
	float height;
	double area;

	printf("Please input a non-zero, non-negative value for the triangle's base.\n");

	fflush(stdout);
	scanf("%f", &base);

	if(base <= 0)
	{
		printf("Error. Invalid input detected. Please try again with a valid base value.\n");
	}
	else
	{
		printf("Please input a non-zero, non-negative value for the triangle's height.\n");

		fflush(stdout);
		scanf("%f", &height);

		if(height <= 0)
		{
			printf("Error. Invalid input detected. Please try again with a valid height value.\n");
		}
		else
		{
			area = base * height * 0.5;
			printf("A triangle with a base of %f and a height of %f has an area of %f.\n", base, height, area);
		}
	}

	return 0;
}

int main()
{
	int choice;

	printf("Geometry Calculator\n");
	printf("1. Calculate the Area of a Circle\n");
	printf("2. Calculate the Area of a Rectangle\n");
	printf("3. Calculate the Area of a Triangle\n");
	printf("4. Quit\n");
	printf("\nEnter your choice (1-4): \n");

	fflush(stdout);
	scanf("%d", &choice);

	if(choice == 1)
	{
		circle();
	}
	else if(choice == 2)
	{
		rectangle();
	}
	else if(choice == 3)
	{
		triangle();
	}
	else if(choice == 4)
	{
		printf("Goodbye\n");
	}
	else
	{
		printf("You chose an invalid option. Please try again and enter a valid choice (1-4).\n");
	}

	return 0;
}
