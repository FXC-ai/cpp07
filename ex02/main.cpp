#include <iostream>

template<typename T>
class Array
{

	public :
		Array()
		{
			this->_tab = nullptr;
			this->_size = 0;
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
			delete [] this->_tab;
			
			this->_tab = new T [rhs.size()];
			for (unsigned int i = 0; i < rhs.size(); i++)
			{
				this->_tab[i] = rhs[i];
			}
			return *this;
		}

		T & operator[](unsigned int index)
		{

			if (index > this->_size)
			{
				throw OutOfRange();
			}
			return this->_tab[index];
			
		}

		unsigned int size() const
		{
			return this->_size;
		}

		T *get_tab ()
		{
			return this->_tab;
		}

		T *set_tab(T* tab)
		{
			this->_tab = tab;
		}


		class OutOfRange : public std::exception
		{
			virtual const char* what () const throw()
			{
				return "Index out of range";
			}
		};

	private :
		T *_tab;
		unsigned int _size;



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
    delete [] mirror;//
    return 0;
}