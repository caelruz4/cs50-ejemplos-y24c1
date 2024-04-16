#include <stdio.h>
#include <stdlib.h>

// estructura nodo
typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} nodo;

// insertar al inicio
void insertar(nodo** cabeza, int dato) {
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// imprimo mi lista
void imprimir(nodo* cabeza) {
    nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    nodo* cabeza = NULL;

    insertar(&cabeza, 3);
    insertar(&cabeza, 7);
    insertar(&cabeza, 9);

    // imprimo la lista
    printf("Lista enlazada: ");
    imprimir(cabeza);

    return 0;
}
