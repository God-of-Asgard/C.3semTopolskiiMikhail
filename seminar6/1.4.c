#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Dynarray;

Dynarray shallow_copy(Dynarray* pd) {
    Dynarray copy;
    copy.data = pd->data;
    copy.size = pd->size;
    copy.capacity = pd->capacity;
    return copy;
}
