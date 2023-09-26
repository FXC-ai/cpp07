#include <iostream>

template<typename T>

T const & max(const T & lhs, const T & rhs)
{
	return ( lhs>=rhs ? lhs : rhs);
}

template<typename U, typename V>
void donne(U a, V b)
{
	std::cout << a << " " << b << std::endl;
}

template<typename U, typename V>
V donnePlus(U a, V b)
{
	std::cout << a << b << std::endl;
	return b;
}

class ListInt
{
	public :
		ListInt(){};
		ListInt(int content) : _content(content), _next(nullptr)
		{
			std::cout << "Creation List : " << content << std::endl;
		}
		void set_next(ListInt * next)
		{
			this->_next = next;
		}
		int get_content()
		{
			return this->_content;
		}
		ListInt *get_next ()
		{
			return this->_next;
		}

	private:
		int			_content;
		ListInt*	_next;

};

template <typename W>
class List 
{
	public :
		List<W>(W content) : _content(content), _next(nullptr)
		{
			std::cout << "Creation List : " << content << std::endl;
		}
		void set_next(List *next)
		{
			this->_next = next;
		}

		List* get_next()
		{
			return this->_next;
		}

		W get_content()
		{
			return this->_content;
		}

	private:
		W		_content;
		List<W>	*_next;
};


int main(void)
{
	int a = 42;
	int b = 410;

	std::cout << max<int>(a, b) <<std::endl;

	donne<std::string, int>("Voila : ", 42);

	float result = donnePlus<std::string, float>("Je te donne plus ", 3.14159);

	std::cout << "Result = " << result << std::endl;

	ListInt *nodeInt0 = new ListInt(42);
	ListInt *nodeInt1 = new ListInt(420);
	nodeInt0->set_next(nodeInt1);
	std::cout<< "Ça doit afficher 420 : " << nodeInt0->get_next()->get_content() << std::endl;

	List<float> *node0 = new List<float>(3.14159);
	List<float> *node1 = new List<float>(42);

	node0->set_next(node1);
	std::cout<< "Ça doit afficher 42 : " << node0->get_next()->get_content() << std::endl;





	return 0;
}