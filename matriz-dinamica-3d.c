#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("ERRO\n%s n_slices n_rows n_cols\n", argv[0]);
        exit(-1);
    }

    int n_slices = atoi(argv[1]);
    int n_rows = atoi(argv[2]);
    int n_cols = atoi(argv[3]);

    /***** ALOCAÇÃO *****/
    int*** m = (int***) calloc(n_slices, sizeof(int**));
    
    // Para cada fatia
    for (int k = 0; k < n_slices; k++) {
        m[k] = (int**) calloc(n_rows, sizeof(int*));

        // Para cada linha
        for (int i = 0; i < n_rows; i++) {
            m[k][i] = (int*) calloc(n_cols, sizeof(int));
        }
    }
    /********************/

    int count = 0;

    printf("\n&m = %p, m = %p\n\n", &m, m);

    // Para cada fatia
    for (int k = 0; k < n_slices; k++) {
        printf("&m[%d] = %p, m[%d] = %p\n", k, &m[k], k, m[k]);

        // Para cada linha
        for (int i = 0; i < n_rows; i++) {
            printf("&m[%d][%d] = %p, m[%d][%d] = %p\n", k, i, &m[k][i], k, i, m[k][i]);

            // Para cada coluna
            for (int j = 0; j < n_cols; j++) {
                m[k][i][j] = count++;
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
            }

            puts("");
        }

        puts("");
    }

    /***** DESALOCAÇÃO *****/
    // Para cada fatia
    for (int k = 0; k < n_slices; k++) {
        // Para cada linha
        for (int i = 0; i < n_rows; i++) {
            free(m[k][i]);
        }

        free(m[k]);
    }

    free(m);
    m = NULL;   
    
    return 0;
}
