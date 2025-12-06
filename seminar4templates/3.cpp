#include <iostream>
#include <vector>
#include <utility>
#include <string>

template<typename T>
std::pair<T, T> minmax(const std::vector<T>& elements) {
    if (elements.empty()) {
        throw std::invalid_argument("Вектор не должен быть пустым");
    }

    T min_element = elements[0];
    T max_element = elements[0];

    for (const T& element : elements) {
        if (element < min_element) {
            min_element = element;
        }
        if (element > max_element) {
            max_element = element;
        }
    }

    return {min_element, max_element};
}

int main()
{
    std::vector<int> numbers {60, 10, 40, 80, 30};
    auto numbers_minmax = minmax(numbers);
    std::cout << numbers_minmax.first << " " << numbers_minmax.second << std::endl;

    std::vector<std::string> animals {"Cat", "Dog", "Mouse", "Camel", "Wolf"};
    auto animals_minmax = minmax(animals);
    std::cout << animals_minmax.first << " " << animals_minmax.second << std::endl;

    std::vector<std::pair<int, int>> pairs {{10, 90}, {30, 10}, {20, 40}, {10, 50}};
    auto pairs_minmax = minmax(pairs);
    std::cout << pairs_minmax.first.first << " " << pairs_minmax.first.second << std::endl;
    std::cout << pairs_minmax.second.first << " " << pairs_minmax.second.second << std::endl;

    return 0;
}
