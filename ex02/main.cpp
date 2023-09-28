#include "Array.hpp"

class bidon
{
	public :
		bidon(){};
		void display (){std::cout << "useless class" << std::endl;}
};


#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	std::cout << std::endl;

	//Test Construction with no parameters
	Array<char> noParam;

	//Construction with an unsigned int n as a parameter
	Array<int> arrayInt(3);

	//Elements can be accessed through the subscript operator: [ ].
	arrayInt[0] = 3;
	arrayInt[1] = 1;
	arrayInt[2] = 4;
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << "arrayInt[" << i << "] = " << arrayInt[i] << std::endl;
	}

	//A member function size() that returns the number of elements in the array.
	std::cout << "arrayInt.size() = " << arrayInt.size() << std::endl;

	// When accessing an element with the [ ] operator, if its index is out of bounds, an
	//std::exception is thrown.
	try
	{
		std::cout << arrayInt[14] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << " : Index is out of bounds" << std::endl;
	}

	Array<bidon> test(3);

	test[2].display();

	return 0;
}