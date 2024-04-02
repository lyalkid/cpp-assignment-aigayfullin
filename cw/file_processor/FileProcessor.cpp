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
#include <fstream>
#include <vector>
#include <string>
class FileProcessor{
    public:
        std::vector<int> readIntegersFromFile (const std::string filename){
            std::ifstream in(filename);
            if(!in.is_open()){
                throw std::runtime_error("Failed to open file");
            }
            std::vector<int> digits;
            std::string line;
            while (std::getline(in, line))
            {
                try{
                    digits.push_back(std::stoi(line));
                }
                catch(const std::invalid_argument& ex){
                    std::cerr << "Skip invalid input: " << line << std::endl; 
                }
            }
            in.close();
            return digits;
        }

        static int getSum(const std::vector<int> digits){
            size_t size = digits.size();
            int summa = 0;
            for(int i=0; i < size; i++){
                summa += digits[i];
            }
            return summa;
        }

        void writeSumToFile(std::vector<int> digits, const std::string filename){
            std::ofstream out(filename);

            if(!out.is_open()){
                throw std::runtime_error("Failed to open file");
            }
            int summa = getSum(digits);
            out << summa << std::endl;
            out.close();

        }

        
};



int main() {
    FileProcessor processor;
    try {
        std::vector<int> numbers = processor.readIntegersFromFile("digits.txt");
        processor.writeSumToFile(numbers, "summa.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}