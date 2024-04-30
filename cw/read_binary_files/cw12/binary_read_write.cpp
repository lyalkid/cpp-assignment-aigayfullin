#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

void write_data(const std::string &filename) {
  std::ofstream writer(filename, std::ios::out | std::ios::binary);
  if (writer.is_open()) {
    int val = 5;
    writer.write(reinterpret_cast<char *>(&val), sizeof(val));
    writer.close();
  }
}

void read_data(const std::string &filename) {
  std::ifstream reader(filename, std::ios::in | std::ios::binary);
  if (reader.is_open()) {
    int val{};
    reader.read(reinterpret_cast<char *>(&val), sizeof(val));
    std::cout << "VAL: " << val;
    reader.close();
  }
}

#pragma pack(1)
struct Blob {
  uint16_t version;
  uint32_t data;
};
#pragma pack(0)

void write_blob(const std::string &filename) {
  std::ofstream writer(filename, std::ios::out | std::ios::binary);
  if (writer.is_open()) {
    Blob blob{1, 5};
    writer.write(reinterpret_cast<char *>(&blob), sizeof(blob));
    writer.close();
  }
}

void read_blob(const std::string &filename) {
  std::ifstream reader(filename, std::ios::in | std::ios::binary);
  if (reader.is_open()) {
    Blob blob{};
    reader.read(reinterpret_cast<char *>(&blob), sizeof(blob));
    std::cout << blob.version << std::endl;
    std::cout << blob.data << std::endl;
    reader.close();
  }
}

#pragma pack(1)
struct Blob2 {
  uint8_t version;
  uint32_t size;
  uint8_t *data;
};
#pragma pack(0)

int main() {

  // 2. Write / Read int
  // write_data("mybin");
  // read_data("mybin");

  // 3. Write / Read struct
  // write_blob("mybin");
  // read_blob("mybin");

  read_data("bindata");
  std::ifstream reader("bindata", std::ios::in | std::ios::binary);
  if (reader.is_open()) {
    // get file size
    reader.seekg(0, std::ios_base::end);
    auto file_size = reader.tellg();
    reader.seekg(0, std::ios_base::beg);
    std::vector<uint8_t> bindata(file_size);
    std::cout << file_size << std::endl;
    reader.read(reinterpret_cast<char *>(bindata.data()), bindata.size());
    Blob2 blob{};
    std::memcpy(&blob.version, bindata.data(), sizeof(blob.version));
    std::cout << static_cast<uint32_t>(blob.version) << std::endl;
    std::memcpy(&blob.size, bindata.data() + sizeof(blob.version), sizeof(blob.size));
    std::cout << blob.size << std::endl;
    reader.close();
  }

  return 0;
}