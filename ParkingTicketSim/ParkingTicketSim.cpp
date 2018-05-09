// ParkingTicketSim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class ParkedCar
{
private:
	string make;
	string model;
	string color;
	string licenseNumber;
	int minutesParked;

public:
	ParkedCar()
	{
		make = "";
		model = "";
		color = "";
		licenseNumber = "";
		minutesParked = 0;
	}
	ParkedCar(string make, string model, string color, string licenseNumber, int minutesParked)
	{
		this->make = make;
		this->model = model;
		this->color = color;
		this->licenseNumber = licenseNumber;
		this->minutesParked = minutesParked;
	}
	void setMake(string make)
	{
		this->make = make;
	}
	void setModel(string model)
	{
		this->model = model;
	}
	void setColor(string color)
	{
		this->color = color;
	}
	void setLicense(string license)
	{
		licenseNumber = license;
	}
	void setMinutes(int minutes)
	{
		minutesParked = minutes;
	}
	void addMinutes(int minutesAdded)
	{
		minutesParked += minutesAdded;
	}
	string getMake()
	{
		return make;
	}
	string getModel()
	{
		return model;
	}
	string getColor()
	{
		return color;
	}
	string getLicense()
	{
		return licenseNumber;
	}
	int getMinutesParked()
	{
		return minutesParked;
	}
};

class ParkingMeter
{
private:
	int minutesPurchased;

public:
	ParkingMeter()
	{
		minutesPurchased = 0;
	}
	ParkingMeter(int minutesPurchased)
	{
		this->minutesPurchased = minutesPurchased;
	}
	void purchaseMinutes(int minutesPurchased)
	{
		this->minutesPurchased += minutesPurchased;
	}
	int getMinutesPurchased()
	{
		return minutesPurchased;
	}
};

class ParkingTicket
{
private:
	int const FIRST_HOUR_FINE = 25;
	int const MULTI_HOUR_FINE = 10;
	int fine = 0;
	string makeReported;
	string modelReported;
	string colorReported;
	string licenseNumberReported;
	string officerName;
	int officerBadge;

public:
	ParkingTicket()
	{
		fine = 0;
		makeReported = "";
		modelReported = "";
		colorReported = "";
		licenseNumberReported = "";
		officerName = "";
		officerBadge = 0;
	}
	ParkingTicket(ParkedCar reportedCar, string officerName, int officerBadge, int timeOver)
	{
		fine += FIRST_HOUR_FINE;
		fine += (timeOver - 1) * MULTI_HOUR_FINE;
		makeReported = reportedCar.getMake();
		modelReported = reportedCar.getModel();
		colorReported = reportedCar.getColor();
		licenseNumberReported = reportedCar.getLicense();
		this->officerName = officerName;
		this->officerBadge = officerBadge;
	}
	string getReportedMake()
	{
		return makeReported;
	}
	string getReportedModel()
	{
		return modelReported;
	}
	string getReportedColor()
	{
		return colorReported;
	}
	string getReportedLicense()
	{
		return licenseNumberReported;
	}
	string getReportingOfficerName()
	{
		return officerName;
	}
	int getReportingOfficerBadge()
	{
		return officerBadge;
	}
	int getTotalFine()
	{
		return fine;
	}
};

class PoliceOfficer
{
private:
	string name;
	int badgeNumber;

public:
	PoliceOfficer()
	{
		name = "";
		badgeNumber = 0;
	}
	PoliceOfficer(string name, int badgeNumber)
	{
		this->name = name;
		this->badgeNumber = badgeNumber;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setBadgeNumber(int badgeNumber)
	{
		this->badgeNumber = badgeNumber;
	}
	string getName()
	{
		return name;
	}
	int getBadgeNumber()
	{
		return badgeNumber;
	}
	ParkingTicket inspect(ParkedCar car, ParkingMeter meter)
	{
		int timeOver = car.getMinutesParked() - meter.getMinutesPurchased();
		if (timeOver > 0)
		{
			ParkingTicket ticket = ParkingTicket(car, name, badgeNumber, timeOver);
			return ticket;
		}
		else
		{
			ParkingTicket ticket = ParkingTicket();
			return ticket;
		}
	}
};

int main()
{
	ParkedCar car1 = ParkedCar("Make", "Model", "Color", "LICENSE", 1);
	ParkedCar car2 = ParkedCar();
	car2.setMake("Make2");
	car2.setModel("Model2");
	car2.setColor("Color2");
	car2.setLicense("L1CENSE");
	car2.addMinutes(10);

	ParkingMeter meter1 = ParkingMeter(5);
	ParkingMeter meter2 = ParkingMeter();
	meter2.purchaseMinutes(8);

	PoliceOfficer officerBob = PoliceOfficer("Bob Boberts", 8675309);

	ParkingTicket ticket1 = officerBob.inspect(car1, meter1);
	ParkingTicket ticket2 = officerBob.inspect(car2, meter2);

	if (ticket1.getTotalFine() == 0)
	{
		cout << "Officer " << officerBob.getName() << " did not report the car with the license number of " << car1.getLicense() << "." << endl;
	}
	else
	{
		cout << "Officer " << officerBob.getName() << " reported the car with the license number of " << car1.getLicense() << "." << endl;
		cout << "Their total fine equals $" << ticket1.getTotalFine() << "." << endl;
	}

	if (ticket2.getTotalFine() == 0)
	{
		cout << "Officer " << officerBob.getName() << " did not report the car with the license number of " << car2.getLicense() << "." << endl;
	}
	else
	{
		cout << "Officer " << officerBob.getName() << " reported the car with the license number of " << car2.getLicense() << "." << endl;
		cout << "Their total fine equals $" << ticket2.getTotalFine() << "." << endl;
	}

    return 0;
}

