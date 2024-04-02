/*
1.
Напишите программу на C++, которая запрашивает у пользователя два числа и затем делит первое число на второе.
Обработайте исключение деления на ноль с помощью исключений C++.
Тип исключения std::runtime_error / std::invalid_argument
2.
Напишите программу на C++, которая будет запрашивать у пользователя возраст и проверять его на корректность.
Если возраст меньше 0 или больше 100, программа должна генерировать исключение типа std::out_of_range
*/

#include <iostream>

double solution(double a, double b);

int main(){
    double a, b;
    std::cout << "Введи два числа" << std::endl;
    std::cin >> a >> b;
    double result = -1;

    try{
        result = solution(a,b);
        std::cout << ((int)result == result ? (int)result : result)<< std::endl;
    }
    catch(std::exception& ex){
        std::cout << ex.what();
    }
}

double solution(double a, double b){
    double result = 0;
    if(!b){
        throw std::runtime_error("divide by zero exception");
    }
    else{
        result = a/b; 
    }
    return result;
}