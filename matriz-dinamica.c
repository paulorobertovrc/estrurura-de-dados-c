#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0;
    
    int n_rows = 2;
    int n_cols = 3;
    int** m = (int**) calloc(n_rows, sizeof(int*));

    for (int i = 0; i < n_rows; i++) {
        m[i] = (int*) calloc(n_cols, sizeof(int));
    }

    printf("&m = %p, m = %p\n\n", &m, m);

    for (int i = 0; i < n_rows; i++) {
        printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);

        for (int j = 0; j < n_cols; j++) {
            m[i][j] = count;
            count++;
            
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }

        puts("");
    }
    
    return 0;
}
