// Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:

protected:
	double startBalance;
	double balance;
	double annualInterest;
	double monthlyService;
	int monthlyDeposits;
	int monthlyWithdrawals;

public:
	BankAccount(double initialBalance, double initialInterest)
	{
		startBalance = initialBalance;
		balance = initialBalance;
		annualInterest = initialInterest;
		monthlyService = 0.0;
		monthlyDeposits = 0;
		monthlyWithdrawals = 0;
	}
	virtual void deposit(double depositAmount)
	{
		balance += depositAmount;
		monthlyDeposits++;
	}
	virtual void withdrawal(double withdrawalAmount)
	{
		balance -= withdrawalAmount;
		monthlyWithdrawals++;
	}
	virtual void calcInt()
	{
		double mIR = (annualInterest / 12);
		double mI = (mIR * balance);
		balance += mI;
	}
	virtual void monthlyProc()
	{
		balance -= monthlyService;
		cout << monthlyService;
		calcInt();
		monthlyService = 0.0;
		monthlyDeposits = 0;
		monthlyWithdrawals = 0;
	}
	double getStartBalance()
	{
		return startBalance;
	}
	double getBalance()
	{
		return balance;
	}
	int getDeposits()
	{
		return monthlyDeposits;
	}
	int getWithdrawals()
	{
		return monthlyWithdrawals;
	} 
};

class SavingsAccount : public BankAccount
{
private:
	bool status;

public:
	SavingsAccount(double initialBalance, double initialInterest) : BankAccount(initialBalance, initialInterest)
	{
		if (initialBalance >= 25.0)
		{
			status = true;
		}
		else
		{
			status = false;
		}
	}
	virtual void deposit(double depositAmount)
	{
		if (!status)
		{
			if (balance + depositAmount >= 25.0)
			{
				status = true;
				BankAccount::deposit(depositAmount);
			}
			else
			{
				BankAccount::deposit(depositAmount);
			}
		}
		else
		{
			BankAccount::deposit(depositAmount);
		}
	}
	virtual void withdrawal(double withdrawalAmount)
	{
		if (status)
		{
			BankAccount::withdrawal(withdrawalAmount);
			if (balance < 25.0)
			{
				status = false;
			}
		}
	}
	virtual void monthlyProc()
	{
		if (monthlyWithdrawals > 4)
		{
			monthlyService += monthlyWithdrawals - 4;
		}
		BankAccount::monthlyProc();
		if (balance < 25.0)
		{
			status = false;
		}
	}
	bool getStatus()
	{
		return status;
	}
};

class CheckingAccount : public BankAccount
{
private:
	bool failed;

public:
	CheckingAccount(double initialBalance, double initialInterest) : BankAccount(initialBalance, initialInterest)
	{
	}
	virtual void withdrawal(double withdrawalAmount)
	{
		failed = false;
		if (balance - withdrawalAmount < 0)
		{
			balance -= 15.0;
			failed = true;
		}
		else
		{
			BankAccount::withdrawal(withdrawalAmount);
		}
	}
	virtual void monthlyProc()
	{
		monthlyService = 5.0 + (0.10 * monthlyWithdrawals);
		BankAccount::monthlyProc();
	}
	bool getFailure()
	{
		return failed;
	}
};

int main()
{
	SavingsAccount savings = SavingsAccount(0.0, 0.125);
	CheckingAccount checking = CheckingAccount(0.0, 0.125);

	cout << "Welcome to the Total Garbage Banking System v4.20" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	int x = 0;
	while (x < 1)
	{
		int menuSelect;

		cout << "Please select which operation you would like to perform (1-5)." << endl;
		cout << "1. Deposit Into Savings Account" << endl;
		cout << "2. Withdrawal From Savings Account" << endl;
		cout << "3. Deposit Into Checking Account" << endl;
		cout << "4. Withdrawal From Checking Account" << endl;
		cout << "5. Exit Application" << endl;

		cin >> menuSelect;

		if (menuSelect == 1)
		{
			int y = 0;
			while (y < 1)
			{
				double depositAmountS;

				cout << "Please input a positive double amount to deposit into your savings account." << endl;

				cin >> depositAmountS;

				if (depositAmountS < 0.0)
				{
					cout << "Error. Invalid input detected. Please try again." << endl;
				}
				else
				{
					savings.deposit(depositAmountS);
					cout << "You have successfully added $" << depositAmountS << " into your savings account." << endl;
					if (savings.getStatus())
					{
						cout << "Your savings account is now active." << endl;
					}
					else
					{
						cout << "Your savings account is now inactive." << endl;
					}
					y++;
				}
			}
		}
		else if (menuSelect == 2)
		{
			int y = 0;
			while (y < 1)
			{
				double withdrawalAmountS;

				cout << "Please input a positive double amount to withdraw from your savings account." << endl;

				cin >> withdrawalAmountS;

				if (withdrawalAmountS < 0.0)
				{
					cout << "Error. Invalid input detected. Please try again." << endl;
				}
				else
				{
					if (savings.getStatus())
					{
						savings.withdrawal(withdrawalAmountS);
						cout << "You have successfully withdrawn $" << withdrawalAmountS << " from your savings account." << endl;
						if (savings.getStatus())
						{
							cout << "Your savings account is now active." << endl;
						}
						else
						{
							cout << "Your savings account is now inactive." << endl;
						}
					}
					else
					{
						cout << "Error, your savings account is inactive." << endl;
						cout << "You cannot withdraw funds from an inactive savings account." << endl;
					}
					y++;
				}
			}
		}
		else if (menuSelect == 3)
		{
			int y = 0;
			while (y < 1)
			{
				double depositAmountC;

				cout << "Please input a positive double amount to deposit into your checking account." << endl;

				cin >> depositAmountC;

				if (depositAmountC < 0.0)
				{
					cout << "Error. Invalid input detected. Please try again." << endl;
				}
				else
				{
					checking.deposit(depositAmountC);
					cout << "You have successfully added $" << depositAmountC << " into your checking account." << endl;
					y++;
				}
			}
		}
		else if (menuSelect == 4)
		{
			int y = 0;
			while (y < 1)
			{
				double withdrawalAmountC;

				cout << "Please input a positive double amount to withdraw from your checking account." << endl;

				cin >> withdrawalAmountC;

				if (withdrawalAmountC < 0.0)
				{
					cout << "Error. Invalid input detected. Please try again." << endl;
				}
				else
				{
					checking.withdrawal(withdrawalAmountC);
					if (!checking.getFailure())
					{
						cout << "You have successfully withdrawn $" << withdrawalAmountC << " from your checking account." << endl;
					}
					else
					{
						cout << "Warning. Your checking account has been charged $15.00 for attempting to withdraw from insufficient funds." << endl;
						if (checking.getBalance() < 0)
						{
							cout << "Warning. Your checking account has negative funds equaling $" << checking.getBalance() << "." << endl;
							cout << "Please pay the negative funds directly to your Total Garbage Bank to resolve this issue." << endl;
						}
					}
					y++;
				}
			}
		}
		else if (menuSelect == 5)
		{
			cout << "Ok. Printing monthly statistics." << endl;
			x++;
		}
		else
		{
			cout << "Error. Invalid input detected. Please try again." << endl;
		}
	}

	cout << "Total Garbage Banking System Monthly Statistics" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Initial Savings Account Balance: $" << savings.getStartBalance() << "." << endl;
	cout << "Initial Checking Account Balance: $" << checking.getStartBalance() << "." << endl;
	cout << "Total Savings Deposits Made: " << savings.getDeposits() << "." << endl;
	cout << "Total Savings Withdrawals Made: " << savings.getWithdrawals() << "." << endl;
	cout << "Total Checking Deposits Made: " << checking.getDeposits() << "." << endl;
	cout << "Total Checking Withdrawals Made: " << checking.getWithdrawals() << "." << endl;
	cout << "Total Savings Account Service Charges: $";
	
	savings.monthlyProc();

	cout << "." << endl;
	cout << "Total Checking Account Service Charges: $";

	checking.monthlyProc();

	cout << "." << endl;
	cout << "Final Savings Account Balance: $" << savings.getBalance() << "." << endl;
	cout << "Final Checking Account Balance: $" << checking.getBalance() << "." << endl;
	cout << "Have a nice day." << endl;

    return 0;
}

