#include <stdio.h>
#include <stdlib.h>

int soma_e_sub(int x, int y, int* sub)
{
    *sub = x - y;
    return x + y;
}

int main()
{
    int a = 10;
    int b = 20;
    int c, d;

    c = soma_e_sub(a, b, &d);
    
    printf("%d %d %d %d\n", a, b, c, d);
}
