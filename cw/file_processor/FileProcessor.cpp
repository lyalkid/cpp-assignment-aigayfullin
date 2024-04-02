/*
Напиcать программу на C++, которая считывает целые числа из файла,
вычисляет их сумму, а затем записывает сумму в другой файл
Реализовать обработку исключений для операций ввода/вывода из файла и
обеспечить корректную обработку недопустимых входных данных

1. Создать класс FileProcessor, который обрабатывает операции ввода/вывода данных из файла
2. Реализовать метод readIntegersFromFile для чтения целых чисел из файла и хранения их в векторе
3. Реализовать метод writeSumToFile для вычисления суммы целых чисел из вектора и записи ее в другой файл
4. Обеспечить корректную обработку ошибок с помощью исключений C++:
 - Обработка ошибок открытия файлов
 - Обработка недопустимых данных во входном файле (например, строковые значения)

Подсказки:
File IO: std::ifstream, std::ofstream
Exception: std::invalid_argument, std::runtime_error
Converter: std::stoi
Range-based for loop: for (int val : vec_of_ints) { ... }
*/

#include <iostream>
