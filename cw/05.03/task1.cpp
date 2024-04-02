/*
Задание 1. Замена подстроки
Напишите функцию, которая принимает три строки в качестве аргументов:
(1) основную строку, (2) подстроку для поиска и (3) подстроку для замены
Функция должна заменить все вхождения подстроки для поиска в основной строке на
подстроку для замены
*/

#include <iostream>
#include <string.h>

std::string find(std::string main_str, std::string target, std::string str);
int main() {
  std::string main_str{"array arrays main line uparrayper down"};
  std::string target{"array"};
  std::string str{"list"};
  main_str = find(main_str, target, str);
  std::cout << main_str << std::endl;
}

std::string find(std::string main_str, std::string target, std::string str) {
  int flag = 1;
  do {
    size_t index = main_str.find(target);
    if (index != std::string::npos) {
      int len = target.length();
      main_str.replace(index, len, str);
    } else {
      flag = 0;
    }

  } while (flag);
  return main_str;
}