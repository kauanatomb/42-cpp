#include <iostream>
#include "Serializer.hpp"

int main() {
    Data d;
    d.value = 42;

    Data* ptr = &d;

    unsigned long raw = Serializer::serialize(ptr);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;

    if (ptr == deserialized)
        std::cout << "Success: deserialized pointer equals original pointer." << std::endl;
    else
        std::cout << "Failure." << std::endl;

    return 0;
}
