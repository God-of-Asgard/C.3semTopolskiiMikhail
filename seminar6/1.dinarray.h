#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Dynarray;

Dynarray create_dynarray(size_t initial_capacity);
void push_back(Dynarray* pd, int value);
void delete_dynarray(Dynarray* pd);

int pop_back(Dynarray* pd);
void resize(Dynarray* pd, size_t new_size);
void shrink_to_fit(Dynarray* pd);
Dynarray shallow_copy(Dynarray* pd);
Dynarray deep_copy(const Dynarray* pd);

#endif
