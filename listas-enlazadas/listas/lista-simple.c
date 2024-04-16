#include <stdio.h>
#include <stdlib.h>

// estructura nodo
typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} nodo;

int main() {
    nodo* cabeza = NULL;

    // primer nodo
    nodo* nuevo1 = (nodo*)malloc(sizeof(nodo));
    nuevo1->dato = 3;
    nuevo1->siguiente = cabeza;
    cabeza = nuevo1;

    // segundo nodo
    nodo* nuevo2 = (nodo*)malloc(sizeof(nodo));
    nuevo2->dato = 7;
    nuevo2->siguiente = cabeza;
    cabeza = nuevo2;

    // tercer nodo
    nodo* nuevo3 = (nodo*)malloc(sizeof(nodo));
    nuevo3->dato = 9;
    nuevo3->siguiente = cabeza;
    cabeza = nuevo3;

    // Imprimir la lista
    printf("Lista enlazada: ");
    nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");

    // Liberar memoria
    actual = cabeza;
    while (actual != NULL) {
        nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    return 0;
}
