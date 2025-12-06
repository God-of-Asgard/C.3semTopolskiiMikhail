#include <iostream>
#include <string>
#include <cstdlib>
#include <new>

using namespace std::string_literals;

template<typename T>
class Manager {
private:
    T* memory;

public:
    Manager() : memory(nullptr) {}

    ~Manager() {
        if (memory != nullptr) {
            std::free(memory);
        }
    }

    void allocate() {
        memory = static_cast<T*>(std::malloc(sizeof(T)));
        if (memory == nullptr) {
            throw std::bad_alloc();
        }
    }

    void construct(const T& other) {
        if (memory == nullptr) {
            throw std::runtime_error("Память не выделена");
        }
        new (memory) T(other);
    }

    void destruct() {
        if (memory != nullptr) {
            memory->~T();
        }
    }

    void deallocate() {
        if (memory != nullptr) {
            std::free(memory);
            memory = nullptr;
        }
    }

    T& get() {
        if (memory == nullptr) {
            throw std::runtime_error("Память не выделена");
        }
        return *memory;
    }
};

int main()
{
    Manager<std::string> a;
    a.allocate();
    a.construct("Cats and dogs"s);
    a.get() += " and elephant";
    std::cout << a.get() << std::endl;
    
    a.destruct();
    a.construct("Sapere Aude"s);
    std::cout << a.get() << std::endl;
    
    a.destruct();
    a.deallocate();

    return 0;
}
