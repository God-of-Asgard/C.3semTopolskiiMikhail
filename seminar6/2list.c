#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List init(size_t n) {
    List list = {NULL, NULL, 0};
    for (size_t i = 0; i < n; i++) {
        push_back(&list, 0);
    }
    return list;
}

void print(const List* pl) {
    Node* current = pl->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void push_back(List* pl, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = pl->tail;
    
    if (pl->tail != NULL) {
        pl->tail->next = new_node;
    }
    pl->tail = new_node;
    
    if (pl->head == NULL) {
        pl->head = new_node;
    }
    
    pl->size++;
}

int pop_back(List* pl) {
    if (pl->tail == NULL) {
        return 0;
    }
    
    Node* last = pl->tail;
    int value = last->value;
    
    pl->tail = last->prev;
    if (pl->tail != NULL) {
        pl->tail->next = NULL;
    } else {
        pl->head = NULL;
    }
    
    free(last);
    pl->size--;
    return value;
}

void push_front(List* pl, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = pl->head;
    
    if (pl->head != NULL) {
        pl->head->prev = new_node;
    }
    pl->head = new_node;
    
    if (pl->tail == NULL) {
        pl->tail = new_node;
    }
    
    pl->size++;
}

int pop_front(List* pl) {
    if (pl->head == NULL) {
        return 0;
    }
    
    Node* first = pl->head;
    int value = first->value;
    
    pl->head = first->next;
    if (pl->head != NULL) {
        pl->head->prev = NULL;
    } else {
        pl->tail = NULL;
    }
    
    free(first);
    pl->size--;
    return value;
}

Node* erase(List* pl, Node* p) {
    if (p == NULL) return NULL;
    
    Node* next_node = p->next;
    
    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        pl->head = p->next;
    }
    
    if (p->next != NULL) {
        p->next->prev = p->prev;
    } else {
        pl->tail = p->prev;
    }
    
    free(p);
    pl->size--;
    return next_node;
}

void splice(List* plist, Node* p, List* pother) {
    if (pother->head == NULL) return;
    
    if (p == NULL) {
        if (plist->tail != NULL) {
            plist->tail->next = pother->head;
            pother->head->prev = plist->tail;
        } else {
            plist->head = pother->head;
        }
        plist->tail = pother->tail;
    } else {
        Node* prev_node = p->prev;
        
        if (prev_node != NULL) {
            prev_node->next = pother->head;
            pother->head->prev = prev_node;
        } else {
            plist->head = pother->head;
        }
        
        pother->tail->next = p;
        p->prev = pother->tail;
    }
    
    plist->size += pother->size;
    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl) {
    Node* current = pl->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n) {
    Node* current = *pp;
    for (size_t i = 0; i < n && current != NULL; i++) {
        current = current->next;
    }
    *pp = current;
}
