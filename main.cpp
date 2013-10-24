#include <iostream>
#include <chrono>

class TestClass
{
public:
	TestClass()
	{
	}

	int getFoo()
	{
		return foo;
	}

	int getAss()
	{
		return 5;
	}

	int ass;

protected:
	int foo;
};

int getAss()
{
	return 5;
}

int main(int argc, char const *argv[])
{
	int f;
	TestClass test;

	auto start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < 2000000000; ++i)
	{
		TestClass test;
		// getAss();
		// test.getAss();
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Measured time: " << dur.count() << "ms" << std::endl;

	return 0;
}
