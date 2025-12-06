#include <iostream>
#include <cstring>
#include <algorithm>

template<typename T>
void swapEndianness(T& value) {
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&value);
    std::reverse(bytes, bytes + sizeof(T));
}

int main()
{
    std::cout << std::hex;
    
    int number = 0x1a2b3c4d;
    std::cout << number << std::endl;
    swapEndianness(number);
    std::cout << number << std::endl;
    swapEndianness(number);
    std::cout << number << std::endl;
    
    short small_number = 0x1a2b;
    std::cout << small_number << std::endl;
    swapEndianness(small_number);
    std::cout << small_number << std::endl;

    return 0;
}
