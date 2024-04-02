/*
2.
Напишите программу на C++, которая будет запрашивать у пользователя возраст и проверять его на корректность.
Если возраст меньше 0 или больше 100, программа должна генерировать исключение типа std::out_of_range
*/

#include <iostream>

void check_age(int age);
int main(){
    int age;
    std::cin >> age;
    try{
        check_age(age);
    }
    catch(std::out_of_range& ex){
        std::cout << ex.what();
    }
}

void check_age(int age){
    if(age < 0 || age > 100) {
        throw std::out_of_range("N/A\n");
    }
    else{
        std::cout << "OK\n"; 
    }
}