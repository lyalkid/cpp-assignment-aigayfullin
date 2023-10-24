#include <hw04.h>
#include <iostream>
using namespace std;

std::size_t hw04(const int* input_array, std::size_t elem_count)
{
    int* out_data = new int[1]; // создаем массив из одного элемента
    out_data[0] = 0; // инициализируем его нулем
    int sum = 0; // инициализируем сумму нулем
    for (std::size_t i = 0; i < elem_count; i++) {
        if (input_array[i] >= 0) { // если элемент больше или равен нулю
            if (i > 0 && input_array[i-1] < 0) { // если предыдущий элемент был отрицательным
                out_data = (int*)realloc(out_data, 2*sizeof(int)); // перевыделяем память для двух элементов
                out_data[1] = input_array[i]; // записываем второй элемент
            } else { // если предыдущий элемент был неотрицательным
                out_data[0] += input_array[i]; // добавляем элемент к первому элементу массива
            }
        } else { // если элемент отрицательный
            break; // прерываем цикл
        }
    }
    sum = out_data[0]; // суммируем первый элемент массива
    delete[] out_data; // освобождаем память
    return sum;
}


