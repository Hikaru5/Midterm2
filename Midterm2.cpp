
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

class Human
{
private:
	std::string name;
	int age;
	char sex;
	Human()
	{
		name = "";
		age = 0;
		sex = 'x';
	}

protected:
	Human(std::string n, int a, char s)
	{
		name = n;
		age = a;
		sex = s;
	}
public:
	std::string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	char getSex()
	{
		return sex;
	}
	void setName(std::string n)
	{
		name = n;
	}
	void setAge(int a)
	{
		age = a;
	}
	void setSex(char s)
	{
		sex = s;
	}

};

class Child : public Human
{
private:
	std::string momName;
	std::string dadName;
	int allowance;
	Child():Human("",0,'x')
	{
		momName = "";
		dadName = "";
		allowance = 0;
	}
public:
	Child(std::string n, int a, char s, std::string momN, std::string dadN):Human(n,a,s)
	{
		momName = momN;
		dadName = dadN;
		allowance = 0;
	}
	int getAllowance() const
	{
		return allowance;
	}
	void printParent()
	{
		std::cout << momName << " and " << dadName << std::endl;
	}
	void setAllowance(int allow, Child &child);
	friend class Parent;
};

class Parent :public Human
{
private:
	std::vector<std::string> children;
	Parent():Human("",0,'x')
	{
		children = { "" };
	}
public:
	Parent(std::string n, int a, char s) :Human(n, a, s)
	{

	}
	void printChild()
	{
		for (int i = 0; i < children.size(); i++)
		{
			std::cout << children[i] << " ";
		}
	}
	void setChild(Child c)
	{
		children.push_back(c.getName());
	}
	void setAllowance(int allow, Child &child)
	{
		std::string name = child.getName();
		bool absent = true;
		int iter = 0;
		while (absent)
		{
			if (name.compare(children[iter]) == 0)
				absent = false;
			iter++;
		}
		if (!absent)
			child.allowance = allow;
		else
			std::cout << "No such child exists" << std::endl;
	}
}; 
void printInfo(Human &human)
{
	std::cout << "Name: " << human.getName() << std::endl << "Age: " << human.getAge() << std::endl << "Sex: " << human.getSex() << std::endl;
}
int main()
{
	Parent Homer("Homer", 36, 'M');
	Parent March("March", 34, 'F');
	Child Lisa("Lisa", 12, 'F',"March","Homer");
	Child Bart("Bart", 10, 'M',"March","Homer");
	Child Maggie("Maggie", 3, 'F',"March","Homer");
	Homer.setChild(Lisa);
	Homer.setChild(Bart);
	Homer.setChild(Maggie);
	March.setChild(Lisa);
	March.setChild(Bart);
	March.setChild(Maggie);
	std::cout << "Bart's allowance: " << Bart.getAllowance() << std::endl;
	Homer.setAllowance(5, Bart);
	std::cout << "Bart's allowance: " << Bart.getAllowance() << std::endl;
	Bart.printParent();
	printInfo(March);
	printInfo(Lisa);
}
