#include <stdlib.h>
#include <stdio.h>

int main()
{
    float z = 2.5;
    float* fp;

    fp = &z;

    printf("*&z = %.1f\n", *&z);
    printf("*fp = %.1f\n", *fp);
    printf("**&fp = %.1f\n", **&fp);
}