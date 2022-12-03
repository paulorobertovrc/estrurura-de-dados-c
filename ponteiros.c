#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main()
{
    int a = 10;
    int* p1 = NULL;
    int* p2 = NULL;

    printf("a = %d, p1 = %p, &p1 = %p, p2 = %p, &p2 = %p\n", a, p1, &p1, p2, &p2);
    
    p1 = &a;
    p2 = p1;
    *p2 = 4;

    printf("a = %d, p1 = %p, *p1 = %d, &p1 = %p, p2 = %p, *p2 = %d, &p2 = %p\n", a, p1, *p1, &p1, p2, *p2, &p2);
}