/*
Задание 2. Поиск слова с наибольшей длиной
Напишите функцию, которая принимает вектор строк (std::vector<std::string>) и
возвращает слово с наибольшей длиной из всех строк Использовать std::algorithm
для поиска этого слова Строки принимать через std::getline(std::cin, input)
*/
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <vector>
void input(std::vector<std::string> &stringsle);
std::string find(std::vector<std::string>);

int main() {
  std::vector<std::string> strings;
  input(strings);
  std::cout << find(strings) << std::endl;
}

void input(std::vector<std::string> &strings) {
  int flag = 1;
  do {
    std::string input;
    std::getline(std::cin, input);
    if (input == "end") {
      flag = 0;
    } else {
      strings.push_back(input);
    }
  } while (flag);
}

std::string find(std::vector<std::string> strings) {
  auto longestWord =
      std::max_element(strings.begin(), strings.end(),
                       [](const std::string &a, const std::string &b) {
                         return a.size() < b.size();
                       });
  return *longestWord;
}
