#include "linked_list.h"
#include <stdio.h>

int main() {
    List* l = List_create();
    List_print(l);
    
    List_remove(l, 99);
    List_print(l);
    List_inverted_print(l);

    List_add_last(l, 10);
    List_add_last(l, 7);
    List_add_last(l, 2);
    List_add_last(l, 4);
    List_add_last(l, 7);
    List_print(l);
    List_inverted_print(l);

    List_remove(l, 99);
    List_print(l);
    List_inverted_print(l);
    
    List_remove(l, 7);
    List_print(l);
    List_inverted_print(l);
    
    List_remove(l, 10);
    List_print(l);
    List_inverted_print(l);
    
    List_remove(l, 4);
    List_print(l);
    List_inverted_print(l);
    
    List_remove(l, 7);
    List_print(l);
    List_inverted_print(l);
    
    List_remove(l, 2);
    List_print(l);
    List_inverted_print(l);

    List_destroy(&l);

    return 0;
}
