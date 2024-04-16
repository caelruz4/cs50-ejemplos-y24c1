#include <stdio.h>
int main(void)
{
    // Programa para imprimir los elementos de un arreglo utilizando punteros
    
    int arreglo[5] = {10, 20, 30, 40, 50};
    int *p = arreglo;

    for(int i = 0; i < 5; i++)
    {
        printf("Posicion %d: %d\n", i, *(p + i));
    }
    return 0;
}