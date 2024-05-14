#include <iostream>
#include <fstream>
using namespace std;

typedef struct {
  int year;
  char author[50];
  char title[100];
} Book;

void write_blob(const std::string &filename, Book book) {
  std::ofstream writer(filename, std::ios::out | std::ios::binary);
  if (writer.is_open()) {
    writer.write(reinterpret_cast<char *>(&book), sizeof(book));
    writer.close();
  }
}

void read_blob(const std::string &filename) {
  std::ifstream reader(filename, std::ios::in | std::ios::binary);
  if (reader.is_open()) {
    Book book{};
    reader.read(reinterpret_cast<char *>(&book), sizeof(book));
    std::cout << "Title: " << book.title << std::endl;
    std::cout << "Autor: " << book.author << std::endl;
    std::cout << "Year: " << book.year << std::endl;

    reader.close();
  }
}

int main() {
  Book book = {0};
  cout << "Title:" << endl;
  char c;
  int textSize = 0;
  while (!cin.eof() && textSize < 100) {
    
    cin >> noskipws >> c;
    if(c == 10){
        break;
    }
    else{
        book.title[textSize] = c;
    }
    textSize++;
  }

  cout << "Author:" << endl;

  textSize = 0;
  while (!cin.eof() && textSize < 50) {
     cin >> noskipws >> c;
    if(c == 10){
        break;
    }
    else{
        book.author[textSize] = c;
    }
    textSize++;
  }
  cout << "Year:" << endl;
  cin >> book.year;


  write_blob("book.bin", book);
  read_blob("book.bin");
}
