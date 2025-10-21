#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Dynarray;

// 1.1. Функция pop_back
int pop_back(Dynarray* pd) {
    if (pd->size == 0) {
        fprintf(stderr, "Error: cannot pop from empty array\n");
        exit(1);
    }
    int last_element = pd->data[pd->size - 1];
    pd->size--;
    return last_element;
}
