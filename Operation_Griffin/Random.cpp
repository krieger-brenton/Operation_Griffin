#include "Random.h"
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <cmath>


Random::Random()
{
}


Random::~Random()
{
}

int Random::randomGen(int min, int max)
{
	using namespace std::chrono;
	auto now = high_resolution_clock::now();
	auto nanos = duration_cast<nanoseconds>(now.time_since_epoch()).count();
	return nanos % max + min;
}

void Random::randomTest()
{
	int test[100];
	for (int i = 0; i < 100; i++)
		test[i] = 0;

	for (int i = 0; i < 100000; i++)
		test[randomGen(0, 100)]++;

	for (int i = 0; i < 100; i++)
		std::cout << i << ":" << test[i] << std::endl;
}
