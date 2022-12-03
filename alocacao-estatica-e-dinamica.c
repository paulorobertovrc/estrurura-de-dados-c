#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void somar_vetor_com_escalar(int v[], int n, int escalar)
{
    for (int i = 0; i < n; i++) {
        v[i] += escalar;
    }
}

void imprimir_vetor(const int* v, int n)
{
    for (int i = 0; i < n; i++) {
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
    }
}

void desalocar_vetor(int** v)
{
    free(*v);
    *v = NULL;
}

int main()
{
    int vs[5] = {0, 10, 20, 30, 40};

    /*
    
    // alocação estática
    puts("\n### VETOR ESTÁTICO ###");
    printf("&v = %p, v = %p\n", &vs, vs);
    imprimir_vetor(vs, 5);
    puts("\n");

    // alocação dinâmica usando malloc
    int* vh_mal = (int*) malloc(5 * sizeof(int)); // elementos possuem lixo de memória
    
    puts("### VETOR DINÂMICO COM MALLOC ###");
    printf("&vh_mal = %p, vh_mal = %p\n", &vh_mal, vh_mal);
    imprimir_vetor(vh_mal, 5);
    puts("\n");
    
    */
    
    // alocação dinâmica usando calloc
    int* vh_cal = (int*) calloc(5, sizeof(int)); // elementos possuem valor 0
    
    puts("### VETOR DINÂMICO COM CALLOC ###");
    printf("&vh_cal = %p, vh_cal = %p\n", &vh_cal, vh_cal);
    imprimir_vetor(vh_cal, 5);
    somar_vetor_com_escalar(vh_cal, 5, 9);
    imprimir_vetor(vh_cal, 5);
    puts("\n");
    desalocar_vetor(&vh_cal);
    
    return 0;
}
