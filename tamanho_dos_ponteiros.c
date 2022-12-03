#include <stdio.h>

int main()
{
    printf("sizeof(char) = %lu byte\n", sizeof(char));
    printf("sizeof(short) = %lu bytes\n", sizeof(short));
    printf("sizeof(int) = %lu bytes\n", sizeof(int));
    printf("sizeof(float) = %lu bytes\n", sizeof(float));
    printf("sizeof(long) = %ld bytes\n", sizeof(long));
    printf("sizeof(unsigned long) = %ld bytes\n", sizeof(unsigned long));
    printf("sizeof(double) = %lu bytes\n\n", sizeof(double));

    printf("sizeof(char *) = %lu bytes\n", sizeof(char*));
    printf("sizeof(void *) = %lu bytes\n", sizeof(void*));
    printf("sizeof(int *) = %lu bytes\n", sizeof(int*));
    printf("sizeof(int **) = %lu bytes\n", sizeof(int**));
    printf("sizeof(int ***) = %lu bytes\n", sizeof(int***));
    printf("sizeof(float *) = %lu bytes\n", sizeof(float*));
}