// ShipCruiseCargo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Ship
{
private:
	string name;
	string yearBuilt;

public:
	Ship()
	{
		name = "";
		yearBuilt = "";
	}
	Ship(string name, string yearBuilt)
	{
		this->name = name;
		this->yearBuilt = yearBuilt;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setYear(string year)
	{
		yearBuilt = year;
	}
	string getName()
	{
		return name;
	}
	string getYear()
	{
		return yearBuilt;
	}
	virtual void print()
	{
		cout << "This ship's name is " << name << ", and it was built in " << yearBuilt << "." << endl;
	}

};

class CruiseShip : public Ship
{
private:
	int maxPassengers;

public:
	CruiseShip() : Ship()
	{
		maxPassengers = 0;
	}
	CruiseShip(string name, string yearBuilt, int maxPassengers) : Ship(name, yearBuilt)
	{
		this->maxPassengers = maxPassengers;
	}
	void setMaxPassengers(int max)
	{
		maxPassengers = max;
	}
	int getMaxPassengers()
	{
		return maxPassengers;
	}
	void print()
	{
		cout << "This ship's name is " << getName() << ", and it can hold up to " << maxPassengers << " people." << endl;
	}
};

class CargoShip : public Ship
{
private:
	int tonsOfCargoCapacity;

public:
	CargoShip() : Ship()
	{
		tonsOfCargoCapacity = 0;
	}
	CargoShip(string name, string yearBuilt, int tonsOfCargoCapacity) : Ship(name, yearBuilt)
	{
		this->tonsOfCargoCapacity = tonsOfCargoCapacity;
	}
	void setCargoCapacity(int capacityInTons)
	{
		tonsOfCargoCapacity = capacityInTons;
	}
	int getCargoCapacity()
	{
		return tonsOfCargoCapacity;
	}
	void print()
	{
		cout << "This ship's name is " << getName() << ", and it can hold up to " << tonsOfCargoCapacity << " tons of cargo." << endl;
	}
};

int main()
{
	const int NUM_SHIPS = 3;
	Ship *ships[NUM_SHIPS] =
	{
		new Ship("Boaty McBoatFace", "2016"),
		new CruiseShip("Cruisy McCruiseFace", "2017", 420),
		new CargoShip("Cargy McCargoFace", "2018", 69)
	};

	for (int x = 0; x < NUM_SHIPS; x++)
	{
		cout << "Boat #" << (x + 1) << ":\n";
		ships[x]->print();
		cout << endl;
	}

    return 0;
}

