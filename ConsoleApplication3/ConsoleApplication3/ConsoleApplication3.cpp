#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex io_mutex;

void F1(char c, int x)
{
	for (long i = 0; i < 10000; ++i)
	{
		lock_guard<mutex> a (io_mutex);
		cout<<c;
		1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1;
		
	}
}

int main()
{
	int i, nthreads = thread::hardware_concurrency();

	thread* ths = new thread[nthreads];

	for ( i = 0; i < nthreads; i++ )
		ths[i] = thread(F1, char('a'+i), i);

	for ( i = 0; i < nthreads; i++ )
		ths[i].join();

	delete[] ths;
	getchar();
	return 0;
}
