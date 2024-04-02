/*
Создайте класс исключения, который будет наследоваться от std::exception
и переопределять метод what для предоставления подробного описания ошибки
Класс должен реализовывать конструктор, чтобы исключение могло хранить
информацию о произошедшей ошибке:
1. Сообщение об ошибке
2. Имя файла
3. Номер строки
4. Имя функции

Подсказки:
1. __FILE, LINE, func__
2. std::ostringstream (<sstream>)
*/


#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
class CustomException : public std::exception {
    private:
        std::string errorMessage;
        std::string fileName;
        int line_no;
        std::string func_name;
        std::string fullError;
        
    public:
        CustomException(const std::string& message, const std::string& file, int line, const std::string& function)
        : errorMessage{message}, fileName{file}, line_no{line}, func_name{function} {
             std::ostringstream info;
            info << "1)Error: " << errorMessage << '\n'
            << "2)File: " <<fileName << '\n'
            << "3)Line: " << line_no<< '\n'
            << "4)Function: " << func_name<< '\n';
            fullError = info.str();
        }


        const char* what() const noexcept override {
            return fullError.c_str();
        }
};

void foo(int val){
    
    if (val > 0){
        std::cout << "succes!";}
    else{
        throw CustomException("Something went wrong", __FILE__, __LINE__, __func__);
    }
}

int main() {
    try {
        foo(-1);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}