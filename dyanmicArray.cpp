#include <iostream>

int main(int argc, char *argv[])
{
    int *my_dynamic_array;

    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    my_dynamic_array = new int[size];

    for (int k = 0; k < size; k++)
        my_dynamic_array[k] = k;

    for (int k = 0; k < size; k++)
        std::cout << my_dynamic_array[k] << std::endl;

    delete[] my_dynamic_array;

    return 0;
}