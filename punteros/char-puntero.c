#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// Programa para mostrar la diferencia entre punteros y arreglos de caracteres

typedef char *palabra;

int main()
{
    string a = "Holi";
    char *b = "Palabra";
    palabra c = "Esto es el nuevo string";
    char d [] = "Palabra";

    printf("String: %s\n", b);
    printf("Char puntero: %s\n", b);
    printf("Typedef: %s\n", c);
    printf("Arreglo: %s\n", d);

printf("\nTamaño de la string en memoria: %zu\n", sizeof(d));
    return 0;
}