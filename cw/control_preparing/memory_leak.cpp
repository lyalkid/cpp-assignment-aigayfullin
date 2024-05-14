#include <iostream>

int main() {
    int* data = new int[0x8];
    uint8_t* blob = new uint8_t[0x100];

    delete [] data;
    delete [] blob;
    return 0;
}
