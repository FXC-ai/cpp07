#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void iter(T *arr_addr, int arr_size, T (&f)(T))
{
    for (int i = 0; i < arr_size; i++)
    {
        std::cout << arr_addr[i] << std::endl;
        arr_addr[i] = f(arr_addr[i]);
        std::cout << arr_addr[i] << std::endl;
        std::cout << std::endl;
    }
}

template <typename T>
T addOne(T v)  
{
    return (v + 1);
}

template <typename T>
T byTwo(T v)  
{
    return (v * 2);
}


int main(void)
{
    srand(time(NULL));
    int *mirror = new int[10];

    for (int i = 0; i < 10; i++)
    {
        mirror[i] = rand() % 10;
    }

	iter<int>(mirror, 10, addOne);

	std::cout << "----------------------------" << std::endl;

	iter<int>(mirror, 10, byTwo);

    delete[] mirror;  

    return 0;
}
