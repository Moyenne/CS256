// Game21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Die
{
private:
	int sides;
	int value;

public:
	Die(int numSides = 6)
	{
		unsigned seed = time(0);
		srand(seed);
		sides = numSides;
		roll();
	}
	void roll()
	{
		const int MIN_VALUE = 1;
		value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
	}
	int getSides()
	{
		return sides;
	}
	int getValue()
	{
		return value;
	}
};

int main()
{
	Die compDie = Die();
	int compTotal = 0;
	Die playerDie = Die();
	int playerTotal = 0;

	string input1 = "";
	string input2 = "";

	cout << "Roll the dice? y/n" << endl;
	cin >> input1;

	if (input1 == "n")
	{
		cout << "Whelp. Game's over, folks." << endl;
	}
	else
	{
		int x = 0;
		while (x < 1)
		{
			compDie.roll();
			compTotal += compDie.getValue();

			playerDie.roll();
			playerTotal += playerDie.getValue();

			if (playerTotal > 21)
			{
				cout << "Whelp. Game's over, folks." << endl;
				x++;
			}
			else
			{
				cout << "Your current total equals " << playerTotal << "." << endl;
				cout << "My current total equals... wait, why am I telling you this? No! No hints!" << endl;
				cout << "Roll again? y/n" << endl;
				cin >> input2;

				if (input2 == "n")
				{
					cout << "Alright, nerd. Show me what you've got!" << endl;
					x++;
				}
			}
		}

		if (compTotal > 21 && playerTotal > 21)
		{
			cout << "My total was " << compTotal << "." << endl;
			cout << "Your total was " << playerTotal << "." << endl;
			cout << "Ha ha, what losers! Everybody loses! No winners here." << endl;
		}
		else if (compTotal > 21)
		{
			cout << "My total was " << compTotal << "." << endl;
			cout << "Your total was " << playerTotal << "." << endl;
			cout << "Congratulations! The other guy lost. So I guess you win?" << endl;
		}
		else if (playerTotal > 21)
		{
			cout << "My total was " << compTotal << "." << endl;
			cout << "Your total was " << playerTotal << "." << endl;
			cout << "Sorry, bub. You went over the limit. Better luck next time." << endl;
		}
		else if (compTotal > playerTotal)
		{
			cout << "My total was " << compTotal << "." << endl;
			cout << "Your total was " << playerTotal << "." << endl;
			cout << "Sorry, bub. That's a loss for you. Better luck next time.";
		}
		else if (playerTotal > compTotal)
		{
			cout << "My total was " << compTotal << "." << endl;
			cout << "Your total was " << playerTotal << "." << endl;
			cout << "What!? You cheater! How could you beat me at my own game?" << endl;
		}
		else if (compTotal == playerTotal)
		{
			cout << "My total was " << compTotal << "." << endl;
			cout << "Your total was " << playerTotal << "." << endl;
			cout << "Ha ha, I win! Wait, what do you mean 'No, you don't'? Wait, what do you mean 'It's a draw'!?";
		}
	}

    return 0;
}

