#include <iostream>
#include "Array.hpp"

int main() {
    std::cout << "=== Test empty array ===\n";
    Array<int> empty;
    std::cout << "Size empty: " << empty.sizeArr() << "\n";
    try {
        empty[0] = 10;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n=== Test Array with size 5 ===\n";
    Array<int> arr(5);
    for (size_t i = 0; i < arr.sizeArr(); ++i)
        arr[i] = static_cast<int>(i + 1);

    std::cout << "Content arr: ";
    for (size_t i = 0; i < arr.sizeArr(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    std::cout << "\n=== Test copy constructor ===\n";
    Array<int> copyArr(arr);
    copyArr[0] = 100;
    std::cout << "Original arr[0]: " << arr[0] << ", copyArr[0]: " << copyArr[0] << "\n";

    std::cout << "\n=== Test assignment operator ===\n";
    Array<int> assignArr;
    assignArr = arr;
    assignArr[1] = 200;
    std::cout << "Original arr[1]: " << arr[1] << ", assignArr[1]: " << assignArr[1] << "\n";

    std::cout << "\n=== Test acess const ===\n";
    const Array<int> constArr(arr);
    std::cout << "constArr[2]: " << constArr[2] << "\n";
    try {
        std::cout << constArr[10];
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n=== Test Array std::string ===\n";
    Array<std::string> strArr(3);
    strArr[0] = "test1";
    strArr[1] = "test2";
    strArr[2] = "test3";

    std::cout << "strArr: ";
    for (size_t i = 0; i < strArr.sizeArr(); ++i)
        std::cout << strArr[i] << " ";
    std::cout << "\n";

    std::cout << "\n=== Test edge cases ===\n";
    try {
        strArr[3] = "Fail";
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}
