
#include <iostream>

int main()
{
    int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
    size_t const			amounts_size( sizeof(amounts) / sizeof(int) );

    int                     i = 0;

    while (amounts[i])
    {
        std::cout << "amounts[i]: " << amounts[i] << std::endl;
        i++;
    }
    std::cout << "amounts_size: " << amounts_size << std::endl;

    return (0);
}