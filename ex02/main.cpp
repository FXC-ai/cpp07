#include <iostream>

template<typename T>
class Array
{

	public :
		Array()
		{
			this->_tab = new T;
			this->_size = 1;
		};
		Array(unsigned int n)
		{
			this->_size = n;
			this->_tab = new T [n];
			for (unsigned int i = 0; i < n; i++)
			{
				this->_tab[i] = 0;
			}

		};
		Array(Array & src)
		{	
			unsigned int tmp_size;
			tmp_size = src.size();

			this->_size = tmp_size;
			this->_tab = new T[tmp_size];

			for (unsigned int i = 0 ; i < tmp_size ; i++)
			{
				this->_tab[i] = src[i];

			}


		}

		Array<T> & operator=(Array & rhs)
		{


			


			if (this->_size <= rhs.size())
			{
				for (unsigned int i = 0; i < rhs.size(); i++)
				{
					this->_tab[i] = rhs[i];
				}
			}


			return *this;
		}

		T & operator[](int index)
		{
			return this->_tab[index];
		}

		unsigned int size() const
		{
			return this->_size;
		}




	private :
		T *_tab;
		unsigned int _size;



};



int main(void)
{

	int * a = new int();
	std::cout << a << std::endl;

	Array<int> arr_test;
	
	
	std::cout << arr_test[0] << std::endl;


	Array<int> arr_test1(55);
	std::cout << arr_test1[12] << std::endl;
	arr_test1[12] = 1;
	std::cout << arr_test1[12] << std::endl;

	Array<int> arr_test2(5);
	arr_test2[0] = 10;
	arr_test2[1] = 20;
	arr_test2[2] = 30;
	arr_test2[3] = 40;
	arr_test2[4] = 50;

	Array<int> arr_test3(arr_test2);

	//arr_test3 = arr_test2;

	std::cout << arr_test3[3] <<std::endl;

	Array<int> arr_test4;

	arr

    return 0;
}