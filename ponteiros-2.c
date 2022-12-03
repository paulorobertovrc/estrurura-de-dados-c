#include <stdio.h>
#include <stdlib.h>

void soma(int a, int b, int* soma)
{
    *soma = a + b;
    printf("%p %p %p\n", &a, &b, soma);
}

int main()
{
    int a = 10;
    int b = 20;
    int c;

    printf("%p %p %p\n", &a, &b, &c);
    soma(a, b, &c);
    printf("%p %p %p\n\n", &a, &b, &c);
}