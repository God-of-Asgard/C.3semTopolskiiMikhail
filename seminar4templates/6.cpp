#include <iostream>

template<typename T, T MOD>
class Modular {
private:
    T value;

public:
    Modular(T initial_value = 0) : value(((initial_value % MOD) + MOD) % MOD) {}

    Modular(const Modular& other) : value(other.value) {}

    Modular& operator=(const Modular& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    Modular operator+(const Modular& other) const {
        return Modular((value + other.value) % MOD);
    }

    Modular operator+(T number) const {
        return Modular((value + number) % MOD);
    }

    Modular operator-(const Modular& other) const {
        return Modular((value - other.value + MOD) % MOD);
    }

    Modular operator-(T number) const {
        return Modular((value - number + MOD) % MOD);
    }

    Modular operator*(const Modular& other) const {
        return Modular((value * other.value) % MOD);
    }

    Modular operator*(T number) const {
        return Modular((value * number) % MOD);
    }

    Modular operator-() const {
        return Modular((MOD - value) % MOD);
    }

    template<typename U, U OTHER_MOD>
    Modular(const Modular<U, OTHER_MOD>& other) : value(other.getValue() % MOD) {}

    friend std::ostream& operator<<(std::ostream& stream, const Modular& modular) {
        stream << modular.value;
        return stream;
    }

    T getValue() const {
        return value;
    }
};

int main()
{
    Modular<int, 7> number_a(10);
    std::cout << number_a << std::endl;
    
    number_a = (number_a + 8) * 4;
    std::cout << number_a << std::endl;
    
    Modular<int, 7> number_b(number_a);
    number_b = number_b + 2;
    number_a = number_a - number_b;
    std::cout << number_a << std::endl;
    
    Modular<short, 3> number_c(number_a);
    std::cout << number_c << std::endl;

    return 0;
}
