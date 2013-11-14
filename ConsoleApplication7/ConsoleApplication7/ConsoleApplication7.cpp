#include <list>
#include <iostream>
#include <thread>

using namespace std;


class Fork
{
	bool use;
	Fork();
	~Fork();
	
};

class Philosopher
{

	public:
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

	private:
	protected:
};

int main()
{
	Philosopher bob (0);
	Philosopher phil (1);
	Philosopher josue (2);
	Philosopher bill (3);
	Philosopher max (4);
	list <Philosopher*> a;
	thread * thr =new thread [5];
	typename list<Philosopher*>::iterator  it_list;
	int x=0;
	for(it_list =a.begin(); it_list!=a.end();it_list++)
	{
	
		thr[x]=thread((*it_list)->Wait);
		x++;
	}
	a.push_back(& bob);

	return 0;
}

