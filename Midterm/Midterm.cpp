// Midterm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human
{
private:
	Human() {};
	string name;
	int age;
	char sex;
	string work;
	
protected:
	Human(string name, int age, char sex, string work)
	{
		this->name = name;
		this->age = age;
		this->sex = sex;
		this->work = work;
	}

public:
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return name;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	int getAge()
	{
		return age;
	}
	void getSex(char sex)
	{
		this->sex = sex;
	}
	char getSex()
	{
		return sex;
	}
	void setWork(string work)
	{
		this->work = work;
	}
	string getWork()
	{
		return work;
	}
	//virtual void work() 
	//{
	//	cout << "Work: " << work << endl;
	//}
};

class Child;

class Parent : public Human
{
private:
	vector<Child> children;

public:
	Parent() : Human("a", 0, 'a', "a") {};
	Parent(string name, int age, char sex, string work) : Human(name, age, sex, work) {}
	void setChildren(vector<Child> childrenList)
	{
		int y = childrenList.size();
		children.clear();
		for (int x = 0; x < y; x++)
		{
			children.push_back(childrenList.at(x));
		}
	}
	vector<Child> getChildren()
	{
		return children;
	}
	void setChildsName(Child c, string name)
	{
		c.setName(name);
	}
};

class Child : public Human
{
	friend class Parent;

private:
	Child() : Human("a", 0, 'a', "a") {};
	Parent mother;
	Parent father;

public:
	Child(string name, int age, char sex, string work, Parent mother, Parent father) : Human(name, age, sex, work)
	{
		this->mother = mother;
		this->father = father;
	}
};

int main()
{
	Parent Marge = Parent("Marge", 34, 'F', "Safety Inspector");
	Parent Homer = Parent("Homer", 36, 'M', "Housewife");

	Child Lisa = Child("Gisa", 12, 'F', "Student", Marge, Homer);
	Marge.getChildren().push_back(Lisa);
	Homer.getChildren().push_back(Lisa);
	Child Bart = Child("Gart", 10, 'M', "Student", Marge, Homer);
	Marge.getChildren().push_back(Bart);
	Homer.getChildren().push_back(Bart);
	Child Maggie = Child("Jaggie", 3, 'F', "Play", Marge, Homer);
	Marge.getChildren().push_back(Maggie);
	Homer.getChildren().push_back(Maggie);

	Marge.setChildsName(Maggie, "Maggie");
	Homer.setChildsName(Lisa, "Lisa");
	Homer.setChildsName(Bart, "Bart");

	cout << Homer.getName() << " " << Homer.getAge() << " " << Homer.getSex() << " " << Homer.getWork() << endl;
	cout << Marge.getName() << " " << Marge.getAge() << " " << Marge.getSex() << " " << Marge.getWork() << endl;
	cout << Maggie.getName() << " " << Maggie.getAge() << " " << Maggie.getSex() << " " << Maggie.getWork() << endl;

    return 0;
}

