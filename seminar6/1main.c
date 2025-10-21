#include "dynarray.h"
#include <stdio.h>
#include <assert.h>

void test_pop_back() {
    printf("Тестирование pop_back...\n");
    
    Dynarray arr = create_dynarray(5);
    push_back(&arr, 10);
    push_back(&arr, 20);
    push_back(&arr, 30);
    
    assert(arr.size == 3);
    int value = pop_back(&arr);
    assert(value == 30);
    assert(arr.size == 2);
    
    value = pop_back(&arr);
    assert(value == 20);
    assert(arr.size == 1);
    
    value = pop_back(&arr);
    assert(value == 10);
    assert(arr.size == 0);
    
    delete_dynarray(&arr);
    printf("pop_back тесты пройдены!\n\n");
}

void test_resize() {
    printf("Тестирование resize...\n");
    
    Dynarray arr = create_dynarray(3);
    push_back(&arr, 1);
    push_back(&arr, 2);
    push_back(&arr, 3);
    
    resize(&arr, 2);
    assert(arr.size == 2);
    assert(arr.data[0] == 1);
    assert(arr.data[1] == 2);
    
    resize(&arr, 5);
    assert(arr.size == 5);
    assert(arr.data[0] == 1);
    assert(arr.data[1] == 2);
    assert(arr.data[2] == 0);
    assert(arr.data[3] == 0);
    assert(arr.data[4] == 0);
    
    delete_dynarray(&arr);
    printf("resize тесты пройдены!\n\n");
}

void test_shrink_to_fit() {
    printf("Тестирование shrink_to_fit...\n");
    
    Dynarray arr = create_dynarray(10);
    push_back(&arr, 1);
    push_back(&arr, 2);
    push_back(&arr, 3);
    
    assert(arr.capacity == 10);
    assert(arr.size == 3);
    
    shrink_to_fit(&arr);
    assert(arr.capacity == 3);
    assert(arr.size == 3);
    assert(arr.data[0] == 1);
    assert(arr.data[1] == 2);
    assert(arr.data[2] == 3);
    
    Dynarray empty = create_dynarray(5);
    shrink_to_fit(&empty);
    assert(empty.capacity == 0);
    assert(empty.size == 0);
    
    delete_dynarray(&arr);
    delete_dynarray(&empty);
    printf("shrink_to_fit тесты пройдены!\n\n");
}

void test_shallow_copy() {
    printf("Тестирование shallow_copy...\n");
    
    Dynarray arr = create_dynarray(5);
    push_back(&arr, 100);
    push_back(&arr, 200);
    push_back(&arr, 300);
    
    Dynarray shallow = shallow_copy(&arr);
    
    assert(shallow.data == arr.data);
    assert(shallow.size == arr.size);
    assert(shallow.capacity == arr.capacity);
    
    arr.data[0] = 999;
    assert(shallow.data[0] == 999);
    
    delete_dynarray(&arr);
    printf("shallow_copy тесты пройдены!\n\n");
}

void test_deep_copy() {
    printf("Тестирование deep_copy...\n");
    
    Dynarray arr = create_dynarray(5);
    push_back(&arr, 100);
    push_back(&arr, 200);
    push_back(&arr, 300);
    
    Dynarray deep = deep_copy(&arr);
    
    assert(deep.data != arr.data);
    assert(deep.size == arr.size);
    assert(deep.capacity == arr.capacity);
    
    assert(deep.data[0] == 100);
    assert(deep.data[1] == 200);
    assert(deep.data[2] == 300);
    
    arr.data[0] = 999;
    assert(deep.data[0] == 100);
    
    delete_dynarray(&arr);
    delete_dynarray(&deep);
    printf("deep_copy тесты пройдены!\n\n");
}

void test_edge_cases() {
    printf("Тестирование граничных случаев...\n");
    
    Dynarray empty = create_dynarray(0);
    shrink_to_fit(&empty);
    assert(empty.capacity == 0);
    assert(empty.size == 0);
    
    Dynarray arr = create_dynarray(3);
    push_back(&arr, 1);
    push_back(&arr, 2);
    resize(&arr, 2);
    assert(arr.size == 2);
    
    delete_dynarray(&empty);
    delete_dynarray(&arr);
    printf("Граничные случаи тесты пройдены!\n\n");
}

int main() {
    printf("=== Тестирование динамического массива ===\n\n");
    
    test_pop_back();
    test_resize();
    test_shrink_to_fit();
    test_shallow_copy();
    test_deep_copy();
    test_edge_cases();
    
    printf("=== Все тесты пройдены! ===\n");
    return 0;
}
