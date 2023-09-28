#include "iter.hpp"
#include <cstdlib>
#include <ctime>

// subject
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

// mine
template <typename T>
void addOne(T &v)  
{
    v++;
}

template <typename T>
void byTwo(T &v)  
{
    v *= 2;
}

int main() 
{

  //subject
  const int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  std::cout << "----------------------------" << std::endl;

  //mine
  srand(time(NULL));
  int *mirror = new int[10];

  for (int i = 0; i < 10; i++)
  {
      mirror[i] = rand() % 10;
      std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
  }

  std::cout << "----------------------------" << std::endl;

  iter<int>(mirror, 10, addOne);
  iter<int>(mirror, 10, byTwo);

  for (int i = 0; i < 10; i++)
  {
      std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
  }
  std::cout << "----------------------------" << std::endl;

  char char_tab[3];

  char_tab[0] = 'a';
  char_tab[1] = 'b';
  char_tab[2] = 'C';

  for (int i = 0; i < 3; i++)
  {
      std::cout << "char_tab[" << i << "] = " << char_tab[i] << std::endl;
  }

  std::cout << "----------------------------" << std::endl;

  iter<char>(char_tab, 3, addOne);

  for (int i = 0; i < 3; i++)
  {
      std::cout << "char_tab[" << i << "] = " << char_tab[i] << std::endl;
  }

  delete[] mirror;  
    

  return 0;
}


// int main(void)
// {
//     srand(time(NULL));
//     int *mirror = new int[10];

//     for (int i = 0; i < 10; i++)
//     {
//         mirror[i] = rand() % 10;
//     }

// 	iter<int>(mirror, 10, addOne);

// 	std::cout << "----------------------------" << std::endl;

// 	iter<int>(mirror, 10, byTwo);

//     delete[] mirror;  

//     return 0;
// }
