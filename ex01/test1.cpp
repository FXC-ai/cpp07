#include <iostream>

// Function template for 'iter'
template <typename T, typename Func>
void iter(T* arr, size_t length, Func f) {
    for (size_t i = 0; i < length; ++i) {
        f(arr[i]);
    }
}

// Function templates to be used as the third argument for 'iter'
template <typename T>
void print_element(const T& elem) {
    std::cout << elem << " ";
}

template <typename T>
void double_element(T& elem) {
    elem *= 2;
}

int main() {
    // Test with integer array
    int arr1[] = {1, 2, 3, 4, 5};
    size_t len1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array: ";
    iter(arr1, len1, print_element<int>);
    std::cout << "\nDoubled array: ";
    iter(arr1, len1, double_element<int>);
    iter(arr1, len1, print_element<int>);
    std::cout << std::endl;

    // Test with double array
    double arr2[] = {1.1, 2.2, 3.3};
    size_t len2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array: ";
    iter(arr2, len2, print_element<double>);
    std::cout << "\nDoubled array: ";
    iter(arr2, len2, double_element<double>);
    iter(arr2, len2, print_element<double>);
    std::cout << std::endl;

    return 0;
}
