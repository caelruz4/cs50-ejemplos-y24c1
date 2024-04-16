#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char *nombre;
    int edad;
    struct nodo* siguiente;
} nodo;

void insertar(nodo** head, char *nombre, int edad) {
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->nombre = nombre;
    nuevo->edad = edad;
    nuevo->siguiente = *head;
    *head = nuevo;
}

void imprimir(nodo* head) {
    nodo* actual = head;
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d -> ", actual->nombre, actual->edad);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    nodo* head = NULL;

    insertar(&head, "Mike", 25);
    insertar(&head, "Omar", 22);
    insertar(&head, "Elo", 19);

    printf("Lista enlazada: ");
    imprimir(head);

    // liberando memoria
    nodo* actual = head;
    while (actual != NULL) {
        nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    return 0;
}
