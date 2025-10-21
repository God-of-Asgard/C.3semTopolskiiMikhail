#include "dynarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dynarray create_dynarray(size_t initial_capacity) {
    Dynarray da;
    da.data = (int*)malloc(initial_capacity * sizeof(int));
    da.size = 0;
    da.capacity = (da.data != NULL) ? initial_capacity : 0;
    return da;
}

void push_back(Dynarray* pd, int value) {
    if (pd->size >= pd->capacity) {
        size_t new_capacity = (pd->capacity == 0) ? 1 : pd->capacity * 2;
        int* new_data = (int*)realloc(pd->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        pd->data = new_data;
        pd->capacity = new_capacity;
    }
    pd->data[pd->size++] = value;
}

void delete_dynarray(Dynarray* pd) {
    free(pd->data);
    pd->data = NULL;
    pd->size = 0;
    pd->capacity = 0;
}

int pop_back(Dynarray* pd) {
    if (pd->size == 0) {
        
        exit(1);
    }
    return pd->data[--pd->size];
}

void resize(Dynarray* pd, size_t new_size) {
    if (new_size > pd->capacity) {

        size_t new_capacity = new_size;
        int* new_data = (int*)realloc(pd->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            
            exit(1);
        }
        pd->data = new_data;
        pd->capacity = new_capacity;
        
        
        for (size_t i = pd->size; i < new_size; i
