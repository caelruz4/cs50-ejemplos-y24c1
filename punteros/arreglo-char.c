#include <stdio.h>
#include <string.h>

// Programa para mostrar la diferencia entre punteros y arreglos de caracteres

int main() {
    char *puntero = "Hola"; // Depende de la arquitectura de la maquina 64 bits en este caso
    char arreglo[] = "Hola";

    // Modificación de la cadena utilizando arreglo de caracteres
    arreglo[0] = 'h'; 
    printf("Cadena usando puntero a char: %s\n", puntero);
    printf("Cadena usando arreglo de caracteres: %s\n", arreglo);

    // Comparación de longitud utilizando strlen
    printf("Longitud de puntero: %zu\n", strlen(puntero)); // Esto funcionará
    printf("Longitud de arreglo: %zu\n", strlen(arreglo)); // Esto funcionará

    // sizeof de puntero y arreglo
    printf("Tamaño de puntero (tamaño del puntero): %zu\n", sizeof(puntero));
    printf("Tamaño de arreglo (tamaño del arreglo): %zu\n", sizeof(arreglo));

    return 0;
}
