#include <iostream>
#include <chrono>

class TestClass
{
public:
	int method() const
	{
		return 5;
	}
};

int freeFunction()
{
	return 5;
}

int freeFunction2()
{
	return 1;
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

class IntClass
{
public:
	int a;
	int b;
	int c;
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
	int f;

	std::chrono::high_resolution_clock::duration total;

	const TestClass& test = TestClass();
	const VirtualBase& testVirtual = VirtualChild();
	auto start = std::chrono::high_resolution_clock::now();
	// auto end = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < 2000000000; ++i)
	{
		// start = std::chrono::high_resolution_clock::now();
		//testVirtual.virtualMethod();

		// IntClass ints;
		// int a;
		// int b;
		// int c;

		#ifdef IF_VIRTUAL
			f = testVirtual.virtualMethod();
		#endif

		#ifdef IF_INLINE
			if(f == 5) f = 1; else f = 5;
		#endif

		#ifdef IF_FUNCTION
			if(f == 5) f = freeFunction2(); else f = freeFunction();
		#endif


		#ifdef CALL_VIRTUAL
			testVirtual.virtualMethod();
		#endif

		#ifdef CALL_METHOD
			test.method();
		#endif

		#ifdef CALL_FUNCTION
			freeFunction();
		#endif
		// end = std::chrono::high_resolution_clock::now();

		// total += (end - start);
		// total += (end - start);
	}

	auto end = std::chrono::high_resolution_clock::now();
	total = (end - start);

	auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(total);
	std::cout << dur.count() << std::endl;

	return 0;
}
