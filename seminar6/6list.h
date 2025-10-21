#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdlib.h>

#define LIST_DEFINE(TYPE) \
\
typedef struct node_##TYPE { \
    TYPE value; \
    struct node_##TYPE* next; \
    struct node_##TYPE* prev; \
} Node_##TYPE; \
\
typedef struct list_##TYPE { \
    Node_##TYPE* head; \
    Node_##TYPE* tail; \
    size_t size; \
} List_##TYPE; \
\
List_##TYPE init_##TYPE(size_t n) { \
    List_##TYPE list = {NULL, NULL, 0}; \
    for (size_t i = 0; i < n; i++) { \
        push_back_##TYPE(&list, (TYPE)0); \
    } \
    return list; \
} \
\
void print_##TYPE(const List_##TYPE* pl, void (*print_func)(TYPE)) { \
    Node_##TYPE* current = pl->head; \
    while (current != NULL) { \
        print_func(current->value); \
        printf(" "); \
        current = current->next; \
    } \
    printf("\n"); \
} \
\
void push_back_##TYPE(List_##TYPE* pl, TYPE value) { \
    Node_##TYPE* new_node = (Node_##TYPE*)malloc(sizeof(Node_##TYPE)); \
    new_node->value = value; \
    new_node->next = NULL; \
    new_node->prev = pl->tail; \
    \
    if (pl->tail != NULL) { \
        pl->tail->next = new_node; \
    } \
    pl->tail = new_node; \
    \
    if (pl->head == NULL) { \
        pl->head = new_node; \
    } \
    \
    pl->size++; \
} \
\
TYPE pop_back_##TYPE(List_##TYPE* pl) { \
    if (pl->tail == NULL) { \
        return (TYPE)0; \
    } \
    \
    Node_##TYPE* last = pl->tail; \
    TYPE value = last->value; \
    \
    pl->tail = last->prev; \
    if (pl->tail != NULL) { \
        pl->tail->next = NULL; \
    } else { \
        pl->head = NULL; \
    } \
    \
    free(last); \
    pl->size--; \
    return value; \
} \
\
void push_front_##TYPE(List_##TYPE* pl, TYPE value) { \
    Node_##TYPE* new_node = (Node_##TYPE*)malloc(sizeof(Node_##TYPE)); \
    new_node->value = value; \
    new_node->prev = NULL; \
    new_node->next = pl->head; \
    \
    if (pl->head != NULL) { \
        pl->head->prev = new_node; \
    } \
    pl->head = new_node; \
    \
    if (pl->tail == NULL) { \
        pl->tail = new_node; \
    } \
    \
    pl->size++; \
} \
\
TYPE pop_front_##TYPE(List_##TYPE* pl) { \
    if (pl->head == NULL) { \
        return (TYPE)0; \
    } \
    \
    Node_##TYPE* first = pl->head; \
    TYPE value = first->value; \
    \
    pl->head = first->next; \
    if (pl->head != NULL) { \
        pl->head->prev = NULL; \
    } else { \
        pl->tail = NULL; \
    } \
    \
    free(first); \
    pl->size--; \
    return value; \
} \
\
Node_##TYPE* erase_##TYPE(List_##TYPE* pl, Node_##TYPE* p) { \
    if (p == NULL) return NULL; \
    \
    Node_##TYPE* next_node = p->next; \
    \
    if (p->prev != NULL) { \
        p->prev->next = p->next; \
    } else { \
        pl->head = p->next; \
    } \
    \
    if (p->next != NULL) { \
        p->next->prev = p->prev; \
    } else { \
        pl->tail = p->prev; \
    } \
    \
    free(p); \
    pl->size--; \
    return next_node; \
} \
\
void splice_##TYPE(List_##TYPE* plist, Node_##TYPE* p, List_##TYPE* pother) { \
    if (pother->head == NULL) return; \
    \
    if (p == NULL) { \
        if (plist->tail != NULL) { \
            plist->tail->next = pother->head; \
            pother->head->prev = plist->tail; \
        } else { \
            plist->head = pother->head; \
        } \
        plist->tail = pother->tail; \
    } else { \
        Node_##TYPE* prev_node = p->prev; \
        \
        if (prev_node != NULL) { \
            prev_node->next = pother->head; \
            pother->head->prev = prev_node; \
        } else { \
            plist->head = pother->head; \
        } \
        \
        pother->tail->next = p; \
        p->prev = pother->tail; \
    } \
    \
    plist->size += pother->size; \
    pother->head = NULL; \
    pother->tail = NULL; \
    pother->size = 0; \
} \
\
void destroy_##TYPE(List_##TYPE* pl) { \
    Node_##TYPE* current = pl->head; \
    while (current != NULL) { \
        Node_##TYPE* next = current->next; \
        free(current); \
        current = next; \
    } \
    pl->head = NULL; \
    pl->tail = NULL; \
    pl->size = 0; \
} \
\
void advance_##TYPE(Node_##TYPE** pp, size_t n) { \
    Node_##TYPE* current = *pp; \
    for (size_t i = 0; i < n && current != NULL; i++) { \
        current = current->next; \
    } \
    *pp = current; \
}

#endif
