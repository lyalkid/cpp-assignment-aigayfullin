#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <cstring>
#pragma pack(1)
struct Blob {
  uint32_t size;
  char* buffer;
};
struct Blob2 {
  uint16_t size;
  char* buffer;
};
#pragma(0)

using namespace std;
int main() {
  std::ifstream file("bindata2", std::ios::binary);

  if (file.is_open()) {
    file.seekg(0, std::ios::end);
    auto fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    std::cout << fileSize << std::endl;
    std::vector<uint8_t> bindata(fileSize);
    file.read(reinterpret_cast<char*>(bindata.data()), bindata.size());
    Blob blob{};
    std::memcpy(&blob.size, bindata.data(), sizeof(blob.size));
    blob.buffer = new char[blob.size + 1];
    std::memcpy(blob.buffer, bindata.data() + sizeof(blob.size), blob.size);

    std::cout << static_cast<uint32_t>(blob.size) << std::endl;
    //file.read(buffer, fileSize);
    for (int i = 0; i < blob.size; i++) {

      std::cout << blob.buffer[i];
    }
    std::cout << std::endl;

    Blob blob2{};
    Blob2 blob3{};
    std::memcpy(&blob2.size, bindata.data() + sizeof(blob.size) + blob.size, sizeof(blob2.size));
    blob2.buffer = new char[blob2.size+1];
    memcpy(blob2.buffer, bindata.data() + 2 * sizeof(blob.size) + blob.size, blob2.size);
    std::cout << static_cast<uint32_t>(blob2.size) << std::endl;

    for (int i = 0; i < blob2.size; i++) {

      std::cout << blob2.buffer[i];
    }
    std::cout << std::endl;

    file.close();
  } else {
    std::cout << "Ошибка открытия файла" << std::endl;
  }

  return 0;
}
