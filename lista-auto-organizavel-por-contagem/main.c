#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _product {
    int serial;
    char name[64];
    float price;
} Product;

typedef struct _node {
    struct _node* previous;
    struct _node* next;
    int count;
    Product* product;
} Node;

typedef struct _list {
    Node* begin;
    Node* end;
    size_t size;
    int total_cost;
} List;


Product* product_create(int serial, const char* name, float price) {
    Product* product = (Product*) calloc(1, sizeof(Product));

    product->serial = serial;
    strcpy(product->name, name);
    product->price = price;

    return product;
}

void product_destroy(Product** product_ref) {
    free(*product_ref);
    *product_ref = NULL;
}

Node* node_create(int serial, const char* name, float price) {
    Node* node = (Node*) calloc(1, sizeof(Node));
    node->previous = NULL;
    node->next = NULL;
    node->count = 0;
    node->product = product_create(serial, name, price);

    return node;
}

void node_destroy(Node** node_ref) {
    Node* node = *node_ref;
    product_destroy(&node->product);
    free(node);
    *node_ref = NULL;
}

List* list_create() {
    List* l = (List*) calloc(1, sizeof(List));
    l->begin = l->end = NULL;
    l->size = 0;
    l->total_cost = 0;

    return l;
}

void list_destroy(List** l_ref) {
    List* l = *l_ref;

    Node* p = l->begin;
    Node* aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        node_destroy(&aux);
    }
    
    free(l);
    *l_ref = NULL;
}

bool list_is_empty(List* l) {
    return l->size == 0;
}

void list_add_last(List* l, int serial, char* name, float price) {
    Node* p = node_create(serial, name, price);
    p->previous = l->end;

    if (list_is_empty(l)) {
        l->begin = p;
    } else {
        l->end->next = p;
    }

    l->end = p;
    l->size++;
}

void list_print(const List* l) {
    Node* p = l->begin;
    
    printf("l -> ");

    while (p != NULL) {
        printf("%d (%d) | ", p->product->serial, p->count);
        p = p->next;
    }
    printf("NULL\n");

    if (l->end == NULL) {
        printf("l->end = NULL\n");
    } else {
        printf("l->end = %d (%d)\n", l->end->product->serial, l->end->count);
    }

    printf("Size: %lu\n", l->size);
    printf("\n");
}

const Product* access(List* l, int serial) {
    Product* product = NULL;
    Node* p = l->begin;
    int cost = 0;

    while (p != NULL) {
        l->total_cost++;
        
        if (p->product->serial == serial) {
            l->total_cost += cost;
            p->count++;

            if (l->begin != p) {
                Node* q = p->previous;

                while (q != NULL && q->count <= p->count) {
                    p->previous = q->previous;
                    q->previous = p;
                    q->next = p->next;
                    p->next = q;
                    
                    if (p->previous == NULL) {
                        l->begin = p;
                    } else {
                        p->previous->next = p;
                    }

                    if (q->next == NULL) {
                        l->end = q;
                    } else {
                        q->next->previous = q;
                    }

                    q = p->previous;
                }
            }

            break;    
        } else {
            p = p->next;
        }

        product = p->product;
    } 

    return product;
}

void list_print_serial(const List* l) {
    Node* p = l->begin;
    
    printf("l = (");

    while (p != NULL) {
        printf("%d", p->product->serial);

        if (p != l->end) {
            printf(", ");
        }

        p = p->next;
    }
    

    printf(")\n");
    printf("Custo total = %d\n", l->total_cost);
}


int main() {
    List* l = list_create();
    char command[12];

    scanf("%s", command);

    // A função STRCOMP retorna 0 se as strings forem iguais; caso contrário,
    // retorna um número diferente de zero
    while (strcmp(command, "stop") != 0) {
        if (strcmp(command, "add") == 0) {
            int serial;
            char name[64];
            float price;

            scanf("%d %s %f", &serial, name, &price);
            list_add_last(l, serial, name, price);
            
        } else if (strcmp(command, "access") == 0) {
            int serial;
            scanf("%d", &serial);

            const Product* product = access(l, serial);

            if (product == NULL) {
                printf("Produto %d inexistente\n", serial);
            } else {
                printf("%d, %s, %.2f\n", product->serial, product->name, product->price);
            }
        }

        scanf("%s", command);
    }

    printf("\n");
    list_print_serial(l);

    list_destroy(&l);    

    return 0;
}
