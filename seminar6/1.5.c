#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Dynarray;
Dynarray deep_copy(const Dynarray* pd) {
    Dynarray copy;
    copy.size = pd->size;
    copy.capacity = pd->capacity;
    copy.data = (int*)malloc(copy.capacity * sizeof(int));
    if (copy.data == NULL) {
        fprintf(stderr, "Memory allocation failed in deep_copy\n");
        exit(1);
    }
    memcpy(copy.data, pd->data, pd->size * sizeof(int));
    return copy;
}
