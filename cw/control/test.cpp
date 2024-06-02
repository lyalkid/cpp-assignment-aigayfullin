#include <iostream>
#include <vector>
#include <stdlib.h>
int main(){
    int size = 5;
    int* arr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i <size; i++){
        int tmp;
        std::cin >> tmp;
        arr[i] = tmp;
    }
        std::cout << "---------------------------------------------\n";


    for(int i = 0; i <size; i++){
        std::cout << arr[i] << std::endl;
    }

    free(arr);
    
}

