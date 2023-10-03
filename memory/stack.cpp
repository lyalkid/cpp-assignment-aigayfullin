#include <iostream>

int func()
{
    int a = 10;
    int f = 1.0;
    return 5;
}

int main()
{
    int a = 5;
    int b = 6;
    int c = 7;
    auto d = func();
    // std::cout << &a << '\n' << &b << '\n' << &c << '\n';
    return 0;
}

