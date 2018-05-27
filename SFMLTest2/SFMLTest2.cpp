#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace std;

//ALTERATIONS: Change food image - 16x16 pixel image
//Speed should increment with food eating
//Add a second player
int num_vertBox = 30;
int num_horzBox = 20;
int pixelSize = 16; //number of pixels
int w = pixelSize * num_horzBox; //background number of pixels in width
int h = pixelSize * num_vertBox; //background number of pixels in height

int direction1 = 4;
int snake_length1 = 4;

int direction2 = 4;
int snake_length2 = 4;

float delay;

//max size of snake
struct Snake
{
	int x;
	int y;
}s1[100], s2[100];

struct Fruit
{
	int x;
	int y;
}food;

//snake piece movement s[1] - s[99]
void tick()
{
	for (int i = snake_length1; i > 0; i--)
	{
		s1[i].x = s1[i - 1].x;
		s1[i].y = s1[i - 1].y;
	}
	for (int i = snake_length2; i > 0; i--)
	{
		s2[i].x = s2[i - 1].x;
		s2[i].y = s2[i - 1].y;
	}

	//head of snake depends on user input s[0]
	//user up
	if (direction1 == 3)
	{
		s1[0].y -= 1;
	}
	//user down
	if (direction1 == 0)
	{
		s1[0].y += 1;
	}
	//user left
	if (direction1 == 1)
	{
		s1[0].x -= 1;
	}
	//user right
	if (direction1 == 2)
	{
		s1[0].x += 1;
	}
	//user2 up
	if (direction2 == 3)
	{
		s2[0].y -= 1;
	}
	//user2 down
	if (direction2 == 0)
	{
		s2[0].y += 1;
	}
	//user2 left
	if (direction2 == 1)
	{
		s2[0].x -= 1;
	}
	//user2 right
	if (direction2 == 2)
	{
		s2[0].x += 1;
	}

	//snake growth
	if ((s1[0].x == food.x) && (s1[0].y == food.y))
	{
		snake_length1++;

		if(delay > 0.03)
		{
			delay -= 0.005;
		}

		//randomly place food
		food.x = rand() % num_horzBox;
		food.y = rand() % num_vertBox;
	}
	if ((s2[0].x == food.x) && (s2[0].y == food.y))
	{
		snake_length2++;

		if (delay > 0.03)
		{
			delay -= 0.005;
		}

		//randomly place food
		food.x = rand() % num_horzBox;
		food.y = rand() % num_vertBox;
	}

	//boundary looping
	if (s1[0].x > num_horzBox)
	{
		s1[0].x = 0;
	}
	if (s1[0].x < 0)
	{
		s1[0].x = num_horzBox;
	}
	if (s1[0].y > num_vertBox)
	{
		s1[0].y = 0;
	}
	if (s1[0].y < 0)
	{
		s1[0].y = num_vertBox;
	}
	if (s2[0].x > num_horzBox)
	{
		s2[0].x = 0;
	}
	if (s2[0].x < 0)
	{
		s2[0].x = num_horzBox;
	}
	if (s2[0].y > num_vertBox)
	{
		s2[0].y = 0;
	}
	if (s2[0].y < 0)
	{
		s2[0].y = num_vertBox;
	}

	//self kill
	for (int n = 1; n < snake_length1; n++)
	{
		if ((s1[0].x == s1[n].x) && (s1[0].y == s1[n].y))
		{
			int delayIncrease = snake_length1 - n;
			snake_length1 = n;
			if (delay + (0.005 * delayIncrease) < 0.1)
			{
				delay += (0.005 * delayIncrease);
			}
			else
			{
				delay = 0.1;
			}
		}
	}
	for (int n = 1; n < snake_length2; n++)
	{
		if ((s2[0].x == s2[n].x) && (s2[0].y == s2[n].y))
		{
			int delayIncrease = snake_length2 - n;
			snake_length2 = n;
			if (delay + (0.005 * delayIncrease) < 0.1)
			{
				delay += (0.005 * delayIncrease);
			}
			else
			{
				delay = 0.1;
			}
		}
	}

	for (int n = 1; n < snake_length2; n++)
	{
		if ((s1[0].x == s2[n].x) && (s1[0].y == s2[n].y))
		{
			snake_length2 = n;
			if (delay + 0.005 < 0.1)
			{
				delay += 0.005;
			}
			else
			{
				delay = 0.1;
			}
		}
	}
	for (int n = 1; n < snake_length1; n++)
	{
		if ((s2[0].x == s1[n].x) && (s2[0].y == s1[n].y))
		{
			snake_length1 = n;
			if (delay + 0.005 < 0.1)
			{
				delay += 0.005;
			}
			else
			{
				delay = 0.1;
			}
		}
	}
}

int main()
{
	//randomizing seed
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(w, h), "Snake Game");

	//textures - load an image
	sf::Texture t1, t2, t3, t4;
	t1.loadFromFile("images/White.png");
	t2.loadFromFile("images/Red.png");
	t3.loadFromFile("images/Green.png");
	t4.loadFromFile("images/Apple.png");

	//sprites - has dimensions
	sf::Sprite sprite1(t1);
	sf::Sprite sprite2(t2);
	sf::Sprite sprite3(t3);
	sf::Sprite sprite4(t4);

	food.x = 10;
	food.y = 15;

	sf::Clock clock;
	float timer = 0;
	delay = 0.1;

	for (int a = 0; a < snake_length2; a++)
	{
		s2[a].x = num_horzBox - 1;
		s2[a].y = 0;
	}

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		//events allow us to check when a user does something
		sf::Event e;

		//check when window is closing
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//controls
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			direction1 = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			direction1 = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			direction1 = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			direction1 = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			direction2 = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			direction2 = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			direction2 = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			direction2 = 2;
		}

		if (timer > delay)
		{
			//reset timer
			timer = 0;

			//move the snack one sprite
			tick();
		}


		//draw window
		window.clear();

		//draw background
		for (int x = 0; x < num_horzBox; x++)
		{
			for (int y = 0; y < num_vertBox; y++)
			{
				sprite1.setPosition(x * pixelSize, y * pixelSize);
				window.draw(sprite1);
			}
		}

		//draw snake1
		for (int a = 0; a < snake_length1; a++)
		{
			sprite2.setPosition(s1[a].x * pixelSize, s1[a].y * pixelSize);
			window.draw(sprite2);
		}

		//draw snake2
		for (int a = 0; a < snake_length2; a++)
		{
			sprite3.setPosition(s2[a].x * pixelSize, s2[a].y * pixelSize);
			window.draw(sprite3);
		}

		//draw food
		sprite4.setPosition(food.x * pixelSize, food.y * pixelSize);
		window.draw(sprite4);

		window.display();
	}

	return 0;
}