#include "linked_list.h"
#include "mytime.h"

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        printf("%s <n_elementos>\n", argv[0]);
        exit(-1);
    }

    int n_elementos = atoi(argv[1]);
    
    LinkedList* l = LinkedList_create();
    timer t1, t2;

    printf("n,time\n");

    for (int n = 0; n < n_elementos; n++) {
        t1 = tic();
        LinkedList_add_last_slow(l, n);
        t2 = tac();

        printf("%d, %f\n", n, comptime(t1, t2));
    }
    
    return 0;
}
