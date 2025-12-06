#include <iostream>
#include <string>

template<typename T>
T triple_a(const T& value)
{
    return value + value + value;
}

std::string operator*(int multiplier, const std::string& text) {
    std::string repeated_text;
    for (int count = 0; count < multiplier; ++count) {
        repeated_text += text;
    }
    return repeated_text;
}

template<typename T>
T triple_b(const T& value)
{
    return 3 * value;
}

template<typename T>
T triple_c(const T& value)
{
    return 3 * value;
}

std::string triple_c(const std::string& text)
{
    return text + text + text;
}

template<typename T>
T triple_d(const T& value)
{
    return 3 * value;
}

template<>
std::string triple_d<std::string>(const std::string& text)
{
    return text + text + text;
}

int main()
{
    int number_a = 10;
    std::cout << triple_a(number_a) << std::endl;
    
    std::string word_a = "Cat";
    std::cout << triple_a(word_a) << std::endl << std::endl;

    int number_b = 10;
    std::cout << triple_b(number_b) << std::endl;
    
    std::string word_b = "Cat";
    std::cout << triple_b(word_b) << std::endl << std::endl;

    int number_c = 10;
    std::cout << triple_c(number_c) << std::endl;
    
    std::string word_c = "Cat";
    std::cout << triple_c(word_c) << std::endl << std::endl;

    int number_d = 10;
    std::cout << triple_d(number_d) << std::endl;
    
    std::string word_d = "Cat";
    std::cout << triple_d(word_d) << std::endl;

    return 0;
}
