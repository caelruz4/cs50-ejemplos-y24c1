#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26 // 26 letras del abecedario

// struct persona
typedef struct
{
    char *nombre;
    int edad;
} persona;

// Definición de la estructura para un nodo de la lista enlazada
typedef struct nodo
{
    persona persona;
    struct nodo *siguiente;
} nodo;

// arreglo de listas enlazadas
typedef struct
{
    nodo *tabla[SIZE];
} HashTable;

int hash(char inicial)
{
    return tolower(inicial) - 'a';
}

void insertar(HashTable *tabla, char *nombre, int edad);

void imprimir_tabla(HashTable tabla);

void liberar_memoria(HashTable tabla);

int main()
{
    // Crear la tabla hash e inicializar todas las celdas a NULL
    HashTable tabla;
    for (int i = 0; i < SIZE; i++)
    {
        tabla.tabla[i] = NULL;
    }

    // Insertar algunos datos
    insertar(&tabla, "Ana", 25);
    insertar(&tabla, "Angie", 25);

    insertar(&tabla, "Pedro", 30);
    insertar(&tabla, "Beto", 40);
    insertar(&tabla, "Bernarda", 35);

    imprimir_tabla(tabla);

    liberar_memoria(tabla);

    return 0;
}


// Función para insertar una persona en la tabla hash
void insertar(HashTable *tabla, char *nombre, int edad)
{
    char inicial = nombre[0];
    int indice = hash(inicial);

    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->persona.nombre = nombre;
    nuevoNodo->persona.edad = edad;
    nuevoNodo->siguiente = tabla->tabla[indice];
    tabla->tabla[indice] = nuevoNodo;
}

// Función para imprimir toda la tabla hash
void imprimir_tabla(HashTable tabla)
{
    // Imprimir toda la tabla hash
    printf("Tabla Hash:\n");
    for (int i = 0; i < SIZE; i++)
    {
        nodo *temp = tabla.tabla[i];
        printf("[%c]: ", 'a' + i);
        while (temp != NULL)
        {
            printf("(%s, %d) ", temp->persona.nombre, temp->persona.edad);
            temp = temp->siguiente;
        }
        printf("\n");
    }
}

// Función para liberar la memoria de la tabla hash
void liberar_memoria(HashTable tabla)
{
    for (int i = 0; i < SIZE; i++)
    {
        nodo *actual = tabla.tabla[i];
        while (actual != NULL)
        {
            nodo *temp = actual;
            actual = actual->siguiente;
            free(temp);
        }
    }
}
