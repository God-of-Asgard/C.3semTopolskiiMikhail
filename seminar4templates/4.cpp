#include <iostream>
#include <vector>
#include <string>
#include <array>

template<typename Container1, typename Container2>
bool hasMoreElements(const Container1& first_container, const Container2& second_container) {
    return first_container.size() > second_container.size();
}

int main()
{
    std::vector<int> numbers {10, 20, 30, 40, 50};
    std::string short_text = "Cat";
    std::string long_text = "Elephant";
    std::array<int, 3> small_array {10, 20, 30};
    
    std::cout << hasMoreElements(numbers, short_text) << std::endl;
    std::cout << hasMoreElements(numbers, long_text) << std::endl;
    std::cout << hasMoreElements(numbers, small_array) << std::endl;

    return 0;
}
