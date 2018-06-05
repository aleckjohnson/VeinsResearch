/*
g++ -pthread -o run threads.cpp
*/

#include <iostream>
#include <thread>

void foo()
{
	// stuff happens
}

void bar(int x)
{
	// do stuff
}

int main()
{
	std::thread first (foo);
	std::thread second (bar,0);

	std::cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	first.join();
	second.join();

	std::cout << "foo and bar completed.\n";

	return 0;
}
