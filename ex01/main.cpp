
#include <iostream>

template <typename T, typename F>
void iter(T const *arr_addr, int arr_size, F f)
{
	for (int i = 0; i < arr_size; i++)
	{
		std::cout << arr_addr[i] << std::endl;
		arr_addr[i] = f(arr_addr[i]);
		std::cout << arr_addr[i] << std::endl;
	}
};


template <typename T>
T addOne(T const & v)
{
	return (v + 1);
};

int main( void ) 
{
	srand(time(NULL));
	int* mirror = new int[10];

	for (int i = 0; i < 10; i++)
	{
		mirror[i] = rand();
	}



	iter<int*, int(int *)>(mirror, 10, &addOne);


	return 0;
}


/*

int main ()
{
	Zombie	Victor;
	Zombie	*Christina;
	Zombie	*Horde;

	Victor = Zombie("Victor");

	Christina = newZombie("Christina");

	Christina->announce();
	Victor.announce();

	Horde = new Zombie[42];

	Horde[2].announce();

	delete Christina;
	delete [] Horde;
	return 0;
}


*/