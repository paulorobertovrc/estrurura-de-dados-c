#include "linked_list.h"
#include "mytime.h"

int main() {
    LinkedList* l = LinkedList_create();
    LinkedList* m = LinkedList_create();
    timer t1, t2, t3, t4;

    t1 = tic();
    for (int i = 0; i < 200000; i++) {
        LinkedList_add_last_slow(l, i);
    }
    t2 = tac();
    printf("Performance add_last_slow: %f\n", comptime(t1, t2));
    
    t3 = tic();
    for (int i = 0; i < 200000; i++) {
        LinkedList_add_last(m, i);
    }
    t4 = tac();
    printf("Performance add_last: %f\n", comptime(t3, t4));

    return 0;
}
