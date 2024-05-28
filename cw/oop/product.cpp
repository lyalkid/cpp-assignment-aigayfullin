/*
Задание: Интернет-магазин электроники

Описание задания:
Создайте базовый класс Product для представления товара. Этот класс должен содержать следующие атрибуты:
id: уникальный идентификатор товара,
name: название товара,
price: цена товара.

Отнаследуйте от класса Product следующие классы:
Laptop: для представления ноутбуков. Этот класс должен содержать дополнительные атрибуты, такие как производитель, модель, объем памяти и т.д.
Smartphone: для представления смартфонов. Этот класс также должен содержать дополнительные атрибуты, такие как операционная система, диагональ экрана, объем памяти и т.д.
Accessory: для представления аксессуаров, таких как наушники, зарядные устройства и т.д. Этот класс должен также содержать дополнительные атрибуты, такие как тип аксессуара, совместимость и т.д.

Реализуйте методы для доступа к атрибутам каждого класса, а также методы для установки и получения значений атрибутов.

Создайте класс ElectronicStore, который будет представлять интернет-магазин электроники. Этот класс должен содержать массив (или другую подходящую структуру данных) для хранения объектов Product. Реализуйте методы для добавления новых товаров в магазин, поиска товаров по идентификатору или названию, а также метод для вывода всех товаров в магазине.

Напишите демонстрационную программу, которая создает несколько объектов разных типов (например, ноутбук, смартфон, аксессуар) и добавляет их в магазин. Затем программа должна позволять пользователю выполнять операции поиска товаров по идентификатору или названию, а также выводить все товары в магазине.
*/
#include "product.h"

class Product {
protected:
    int id;
    std::string name;
    double price;

public:
    Product(int id, const std::string& name, double price) 
        : id(id), name(name), price(price) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }

    void setId(int id) { this->id = id; }
    void setName(const std::string& name) { this->name = name; }
    void setPrice(double price) { this->price = price; }

    virtual void printInfo() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Price: " << price << "\n";
    }
};

class Laptop : public Product {
private:
    std::string manufacturer;
    std::string model;
    int memorySize;

public:
    Laptop(int id, const std::string& name, double price, const std::string& manufacturer, const std::string& model, int memorySize)
        : Product(id, name, price), manufacturer(manufacturer), model(model), memorySize(memorySize) {}

    std::string getManufacturer() const { return manufacturer; }
    std::string getModel() const { return model; }
    int getMemorySize() const { return memorySize; }

    void setManufacturer(const std::string& manufacturer) { this->manufacturer = manufacturer; }
    void setModel(const std::string& model) { this->model = model; }
    void setMemorySize(int memorySize) { this->memorySize = memorySize; }

    void printInfo() const override {
        Product::printInfo();
        std::cout << "Manufacturer: " << manufacturer << ", Model: " << model << ", Memory Size: " << memorySize << "GB\n";
    }
};

class Smartphone : public Product {
private:
    std::string operatingSystem;
    double screenSize;
    int memorySize;

public:
    Smartphone(int id, const std::string& name, double price, const std::string& operatingSystem, double screenSize, int memorySize)
        : Product(id, name, price), operatingSystem(operatingSystem), screenSize(screenSize), memorySize(memorySize) {}

    std::string getOperatingSystem() const { return operatingSystem; }
    double getScreenSize() const { return screenSize; }
    int getMemorySize() const { return memorySize; }

    void setOperatingSystem(const std::string& operatingSystem) { this->operatingSystem = operatingSystem; }
    void setScreenSize(double screenSize) { this->screenSize = screenSize; }
    void setMemorySize(int memorySize) { this->memorySize = memorySize; }

    void printInfo() const override {
        Product::printInfo();
        std::cout << "Operating System: " << operatingSystem << ", Screen Size: " << screenSize << "\", Memory Size: " << memorySize << "GB\n";
    }
};

class Accessory : public Product {
private:
    std::string type;
    std::string compatibility;

public:
    Accessory(int id, const std::string& name, double price, const std::string& type, const std::string& compatibility)
        : Product(id, name, price), type(type), compatibility(compatibility) {}

    std::string getType() const { return type; }
    std::string getCompatibility() const { return compatibility; }

    void setType(const std::string& type) { this->type = type; }
    void setCompatibility(const std::string& compatibility) { this->compatibility = compatibility; }

    void printInfo() const override {
        Product::printInfo();
        std::cout << "Type: " << type << ", Compatibility: " << compatibility << "\n";
    }
};

class ElectronicStore {
private:
    std::vector<Product*> products;

public:
    ~ElectronicStore() {
        for (auto product : products) {
            delete product;
        }
    }

    void addProduct(Product* product) {
        products.push_back(product);
    }

    Product* findProductById(int id) const {
        for (auto product : products) {
            if (product->getId() == id) {
                return product;
            }
        }
        return nullptr;
    }

    Product* findProductByName(const std::string& name) const {
        for (auto product : products) {
            if (product->getName() == name) {
                return product;
            }
        }
        return nullptr;
    }

    void listAllProducts() const {
        for (auto product : products) {
            product->printInfo();
        }
    }
};

int main() {
    ElectronicStore store;

    Laptop* laptop = new Laptop(1, "Gaming Laptop", 1500.0, "Dell", "G5 15", 16);
    Smartphone* phone = new Smartphone(2, "Smartphone X", 999.0, "Android", 6.1, 128);
    Accessory* accessory = new Accessory(3, "Wireless Headphones", 199.0, "Headphones", "Universal");

    store.addProduct(laptop);
    store.addProduct(phone);
    store.addProduct(accessory);

    std::cout << "All products in store:\n";
    store.listAllProducts();

    std::cout << "\nFinding product by ID (2):\n";
    Product* foundById = store.findProductById(2);
    if (foundById) {
        foundById->printInfo();
    } else {
        std::cout << "Product not found.\n";
    }

    std::cout << "\nFinding product by name (Wireless Headphones):\n";
    Product* foundByName = store.findProductByName("Wireless Headphones");
    if (foundByName) {
        foundByName->printInfo();
    } else {
        std::cout << "Product not found.\n";
    }

    return 0;
}
