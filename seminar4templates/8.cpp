#include <iostream>
#include <stdexcept>
#include <utility>

class BadOptionalAccess : public std::exception {
public:
    const char* what() const noexcept override {
        return "BadOptionalAccess: Optional does not contain a value";
    }
};

template<typename T>
class Optional {
private:
    union {
        T value;
    };
    bool has_value_flag;

public:
    Optional() : has_value_flag(false) {}

    Optional(const T& other_value) : has_value_flag(true) {
        new (&value) T(other_value);
    }

    Optional(const Optional& other) : has_value_flag(other.has_value_flag) {
        if (other.has_value_flag) {
            new (&value) T(other.value);
        }
    }

    template<typename U>
    Optional(const Optional<U>& other) : has_value_flag(other.has_value()) {
        if (other.has_value()) {
            new (&value) T(*other);
        }
    }

    ~Optional() {
        reset();
    }

    Optional& operator=(const Optional& other) {
        if (this != &other) {
            reset();
            has_value_flag = other.has_value_flag;
            if (other.has_value_flag) {
                new (&value) T(other.value);
            }
        }
        return *this;
    }

    template<typename U>
    Optional& operator=(const Optional<U>& other) {
        reset();
        has_value_flag = other.has_value();
        if (other.has_value()) {
            new (&value) T(*other);
        }
        return *this;
    }

    bool has_value() const {
        return has_value_flag;
    }

    T& operator*() {
        return value;
    }

    const T& operator*() const {
        return value;
    }

    T& get_value() {
        if (!has_value_flag) {
            throw BadOptionalAccess();
        }
        return value;
    }

    const T& get_value() const {
        if (!has_value_flag) {
            throw BadOptionalAccess();
        }
        return value;
    }

    explicit operator bool() const {
        return has_value_flag;
    }

    void reset() {
        if (has_value_flag) {
            value.~T();
            has_value_flag = false;
        }
    }

    T value_or(const T& default_value) const {
        return has_value_flag ? value : default_value;
    }
};

int main()
{
    Optional<int> empty;
    std::cout << "Empty has value: " << empty.has_value() << std::endl;
    
    Optional<int> number(42);
    std::cout << "Number has value: " << number.has_value() << std::endl;
    std::cout << "Number value: " << *number << std::endl;
    
    Optional<double> decimal(3.14);
    Optional<int> from_decimal(decimal);
    std::cout << "From decimal: " << *from_decimal << std::endl;
    
    if (number) {
        std::cout << "Number exists: " << number.get_value() << std::endl;
    }
    
    try {
        std::cout << empty.get_value() << std::endl;
    } catch (const BadOptionalAccess& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "Default value: " << empty.value_or(100) << std::endl;
    
    number.reset();
    std::cout << "After reset, number has value: " << number.has_value() << std::endl;
    
    return 0;
}
