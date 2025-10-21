#include <stdio.h>
#include "list.h"

int main() {
    List a = init(0);
    for (int i = 0; i < 5; ++i)
        push_back(&a, 10 * (i + 1));
    for (int i = 0; i < 5; ++i)
        push_front(&a, 100 * (i + 1));
    print(&a);
    
    printf("%d\n", pop_front(&a));
    printf("%d\n", pop_back(&a));
    print(&a);
    
    Node* p = a.head;
    advance(&p, 3);
    p = erase(&a, p);
    print(&a);
    
    List b = init(0);
    for (int i = 0; i < 3; ++i)
        push_back(&b, 1000 * (i + 1));
    splice(&a, p, &b);
    
    print(&a);
    print(&b);
    
    destroy(&a);
    destroy(&b);
    
    return 0;
}
