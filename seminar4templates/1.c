#include <iostream>

template <typename T>
T cube(T value) {
    return value * value * value;
}

int main() {
    auto number_cubed = cube(5);
    std::cout << number_cubed << " " << sizeof(number_cubed) << std::endl;

    auto decimal_cubed = cube(5.0);
    std::cout << decimal_cubed << " " << sizeof(decimal_cubed) << std::endl;

    char small_number = 5;
    auto small_cubed = cube(small_number);
    std::cout << static_cast<int>(small_cubed) << " " << sizeof(small_cubed) << std::endl;

    return 0;
}
