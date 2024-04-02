/*
Задание: Обработка строки с использованием указателей
Описание задания:
+Напишите функцию length, которая принимает в качестве аргумента указатель на
C-строку (массив символов) и возвращает длину строки (количество символов в
строке), не используя функции стандартной библиотеки C++
+Напишите функцию copy,
которая принимает два аргумента: указатель на исходную C-строку и указатель на
массив символов, в который должна быть скопирована строка. Функция должна
копировать содержимое исходной строки в массив символов и возвращать указатель
на начало массива
+Напишите функцию concatenate, которая принимает два аргумента:
указатель на первую C-строку и указатель на вторую C-строку. Функция должна
объединить две строки в одну и возвращать указатель на новую объединенную строку
+Напишите функцию reverse, которая принимает в качестве аргумента указатель на
C-строку и изменяет порядок символов в строке на обратный
*/
#include <iostream>
#include <string.h>

int length(const char *str);
char *copy(const char *str1, char *str2);
char *concatenate(const char *str1, const char *str2);
void reverse(char *str);

int main() {

  const char *str = "Hello, World!";
  int len = length(str);
  std::cout << "Length of the string: " << len << std::endl;

  const char *src = "Hello";
  char dest[20];

  // Копирование строки
  char *destPtr = copy(src, dest);
  std::cout << "Copied string: " << destPtr << std::endl;

  // Объединение строк
  const char *str1 = "Hello";
  const char *str2 = "World!";
  char *result = concatenate(str1, str2);
  std::cout << "Concatenated string: " << result << std::endl;

  // Разворот строки
  char rever[] = "String";
  reverse(rever);
  std::cout << "Reversed string: " << rever << std::endl;
}

int length(const char *str) {
  int count = 0;
  const char *p = str;
  while (*p != '\0') {
    p++;
    count++;
  }
  return count;
}

char *copy(const char *str1, char *str2) {
  char *start = str2;
  while (*str1 != '\0') {
    *str2 = *str1;
    str2++;
    str1++;
  }
  *str2 = '\0';
  return start;
}

char *concatenate(const char *str1, const char *str2) {
  int len = length(str1) + length(str2);
  char *new_str = new char[len];
  char *p = new_str;
  while (*str1 != '\0') {
    *p = *str1;
    str1++;
    p++;
  }
  while (*str2 != '\0') {
    *p = *str2;
    str2++;
    p++;
  }
  *p = '\0';
  return new_str;
}

void reverse(char *str) {
  int len = 0;
  char *end = str;
  while (*end != '\0') {
    len++;
    end++;
  }

  end--; // Указываем на последний символ перед нулевым символом
  while (str < end) {
    char temp = *str;
    *str = *end;
    *end = temp;
    str++;
    end--;
  }
}