#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Dynarray;

void resize(Dynarray* pd, size_t new_size) {
    if (new_size > pd->capacity) {
        size_t new_capacity = new_size;
        int* new_data = (int*)realloc(pd->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "Memory allocation failed in resize\n");
            exit(1);
        }
        pd->data = new_data;
        pd->capacity = new_capacity;
    }
    
    if (new_size > pd->size) {
        for (size_t i = pd->size; i < new_size; i++) {
            pd->data[i] = 0;
        }
    }
    pd->size = new_size;
}
