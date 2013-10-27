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

	int method() const
	{
		return 5;
	}

	int ass;

protected:
	int foo;
};

int freeFunction()
{
	return 5;
}

class VirtualBase
{
public:
	virtual int virtualMethod() const
	{
		return 1;
	}

	int method() const
	{
		return 30;
	}
};

class VirtualChild: public VirtualBase
{
public:
	int virtualMethod() const
	{
		return 2;
	}
};

// class VirtualChild2: public VirtualBase
// {
// public:
// 	int virtualMethod() const
// 	{
// 		return 3;
// 	}
// };

int main(int argc, char const *argv[])
{
//	int f;

	std::chrono::high_resolution_clock::duration total;

	const TestClass& test = TestClass();
	const VirtualBase& testVirtual = VirtualChild();
	auto start = std::chrono::high_resolution_clock::now();
	// auto end = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < 2000000000; ++i)
	{
		// start = std::chrono::high_resolution_clock::now();
		//testVirtual.virtualMethod();

		// if(true);
		#ifdef VIRTUAL
			testVirtual.virtualMethod();
		#endif

		#ifdef METHOD
			test.method();
		#endif

		#ifdef FUNCTION
			freeFunction();
		#endif
		// end = std::chrono::high_resolution_clock::now();

		// total += (end - start);
		//if(f != 1) f = 1; else f = 2;
		// total += (end - start);
		// getAss();
		// test.getAss();
	}

	auto end = std::chrono::high_resolution_clock::now();
	total = (end - start);

	auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(total);
	std::cout << dur.count() << std::endl;

	return 0;
}
