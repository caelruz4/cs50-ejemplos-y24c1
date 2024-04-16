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

// definición de la estructura para un nodo de la lista enlazada
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

persona *buscar(HashTable tabla, char *nombre);

int main()
{
    // crear la tabla hash e inicializar todas las celdas a NULL
    HashTable tabla;
    for (int i = 0; i < SIZE; i++)
    {
        tabla.tabla[i] = NULL;
    }

    // Insertar algunos datos
    insertar(&tabla, "Ana", 25);
    insertar(&tabla, "Elo", 25);

    insertar(&tabla, "Mike", 30);
    insertar(&tabla, "Lia", 40);
    insertar(&tabla, "Cristel", 35);

    imprimir_tabla(tabla);

    // Buscar una persona por nombre
    char *nombre_buscar = "Pedro";
    persona *resultado = buscar(tabla, nombre_buscar);
    if (resultado != NULL)
    {
        printf("La persona encontrada es: %s, %d años\n", resultado->nombre, resultado->edad);
    }
    else
    {
        printf("La persona con nombre %s no se encontró.\n", nombre_buscar);
    }

    liberar_memoria(tabla);

    return 0;
}

// insertar una persona en la hash table
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

// imprimir la hash table
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

// Liberar la memoria de la hash table
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

// Buscar una persona por su nombre en la tabla hash
persona *buscar(HashTable tabla, char *nombre)
{
    char inicial = nombre[0];
    int indice = hash(inicial);

    nodo *actual = tabla.tabla[indice];
    while (actual != NULL)
    {
        if (strcmp(actual->persona.nombre, nombre) == 0)
        {
            return &(actual->persona);
        }
        actual = actual->siguiente;
    }
    return NULL; // Si no se encuentra la persona
}
