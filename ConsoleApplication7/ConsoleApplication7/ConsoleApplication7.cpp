// ConsoleApplication7.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <list>
#include <iostream>
using namespace std;


class Fork
{
	bool use;
	Fork();
	~Fork();

};

class Philosopher
{
	int id;
	int counter_for_die;
	int counter_for_eat;
	Fork * have [2];
	 
	void Eat()
	{
		cout<<id<<"\tis eating\n";
	}

	void Wait()
	{
		while (true)
		{
			if(have[1] && have[2])
			{
				Eat();
				counter_for_eat--;
			}
			else{
				counter_for_die--;
			}

			if(counter_for_die==0)
			{
				cout<<id<<"\tis dead\n";
				break;
			}
		}
	}

	Philosopher()
	{

	}
	Philosopher(int x)
	{
		id=x;
		counter_for_die=300;
		counter_for_eat=100;
		have[1]=NULL;
		have[2]=NULL;
	}
	~Philosopher()
	{
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Philosopher bob (0);
	Philosopher phil (1);
	Philosopher josue (2);
	Philosopher bill (3);
	Philosopher max (4);
	list <Philosopher*> a;
	a.push_back(& bob);

	return 0;
}

