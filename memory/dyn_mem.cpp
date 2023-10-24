#include <iostream>

int main()
{
    // int *ptr {new int{5}};
    // std::cout << "Addr = " << ptr << " Value: " << *ptr << '\n';
    // delete ptr;

    // std::cout << "Addr = " << ptr << " Value: " << *ptr << '\n'; // UB
    // delete ptr; // UB or aborted

    // std::uint32_t *ptr = new std::uint32_t[2];
    // for (std::size_t idx = 0; idx < 2; idx++) {
    //     ptr[idx] = 5;
    // }
    // delete[] ptr;

    return 0;
}

