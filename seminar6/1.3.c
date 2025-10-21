#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Dynarray;

// 1.3. Функция shrink_to_fit
void shrink_to_fit(Dynarray* pd) {
    if (pd->size < pd->capacity) {
        if (pd->size == 0) {
            free(pd->data);
            pd->data = NULL;
            pd->capacity = 0;
        } else {
            int* new_data = (int*)realloc(pd->data, pd->size * sizeof(int));
            if (new_data != NULL) {
                pd->data = new_data;
                pd->capacity = pd->size;
            }
        }
    }
}
