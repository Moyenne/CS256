// Quiz2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Circle
{
private:
	double r;
	const double PI = 3.13159;

public:
	Circle(double radius = 0.0) : r(radius) {};
	void setRadius(double newRadius)
	{
		r = newRadius;
	};
	double getRadius()
	{
		return r;
	};
	double getArea()
	{
		double area = (r * r) * PI;

		return area;
	};
	double getDiameter()
	{
		double diameter = r * 2;

		return diameter;
	};
	double getCircumfrence()
	{
		double circumfrence = r * 2 * PI;

		return circumfrence;
	};
};

int main()
{
	double radiusInput;

	cout << "Greetings user. Welcome to Circle Simulator 2018. Please input the radius of your circle." << endl;
	cout << "(Warning: Please input a positive, non-zero double value as the radius of the circle)" << endl;

	cin >> radiusInput;

	if (radiusInput <= 0)
	{
		cout << "Great job. You screwed it up. Run this program again if you want to try for real." << endl;
	}
	else
	{
		cout << "Neato! Now let's make your circle." << endl;
		
		Circle c(radiusInput);

		cout << "You gave your circle a radius of " << c.getRadius() << "." << endl;
		cout << "Therefore, your circle has an area of " << c.getArea() << ", ";
		cout << "a diameter of " << c.getDiameter() << ", ";
		cout << "and a circumference of " << c.getCircumfrence() << "." << endl;
		cout << "Wow! Ain't that neat?" << endl;
	}

    return 0;
}

