#include <iostream>

template<typename T>
class Array
{
    public:
        Array(): _tab(new T[1]), _size(1) {}

        Array(unsigned int n): _tab(new T[n]), _size(n) {
            for (unsigned int i = 0; i < n; i++) {
                _tab[i] = 0;
            }
        }

        Array(const Array<T>& src): _tab(new T[src._size]), _size(src._size) {
            for (unsigned int i = 0; i < src._size; i++) {
                _tab[i] = src._tab[i];
            }
        }

        Array<T>& operator=(const Array<T>& rhs) {
            if (this != &rhs) 
			{
                delete[] _tab;  // Deallocate current memory
                _size = rhs._size;
                _tab = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _tab[i] = rhs._tab[i];
                }
            }
            return *this;
        }

        ~Array() {
            delete[] _tab;
        }

        T & operator[](int index) {
            return _tab[index];
        }

        unsigned int size() const {
            return _size;
        }

    private:
        T *_tab;
        unsigned int _size;
};

// ... Rest of the code ...
