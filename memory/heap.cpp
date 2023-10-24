#include <iostream>
#include <cstdlib>
#include <new>

int main()
{   
    // std::uint8_t *ptr = (std::uint8_t *)std::malloc(5);
    // free(ptr);

    
    // std::uint8_t *ptr = new std::uint8_t {5};
    // delete ptr;

    // std::uint8_t *ptr = new std::uint8_t[5];
    // delete[] ptr;
    
    const std::size_t size = 5;
    std::uint32_t *ptr = new std::uint32_t[size];
    for (std::size_t idx = 0; idx < size; idx++) {
        *(ptr+idx) = 7;
    }
    delete[] ptr;

    // try
    // {
    //     while (true)
    //     {
    //         new int[100000000ul];
    //     }
    // }
    // catch (const std::bad_alloc& e)
    // {
    //     std::cout << "Allocation failed: " << e.what() << '\n';
    // }
    

    return 0;
}

