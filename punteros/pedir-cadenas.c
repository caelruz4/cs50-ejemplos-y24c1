#include <stdio.h>

int main() {

    // Pidiendo una cadena utilizando un puntero a char (char*)
    char *puntero;
    printf("Ingrese una cadena utilizando un puntero a char (char*): ");
    scanf("%ms", &puntero);
    // %ms es un especificador de formato para scanf que permite asignar memoria dinámica. De esta manera, el puntero apuntara al primer elemento de la cadena
    printf("Cadena ingresada utilizando puntero a char: %s\n", puntero);


    // Pidiendo una cadena utilizando un arreglo de caracteres (char[])
    char arreglo[50];
    printf("Ingrese una cadena utilizando un arreglo de caracteres (char[]): ");
    scanf("%s", arreglo);
    printf("Cadena ingresada utilizando arreglo de caracteres: %s\n", arreglo);

    
    return 0;
}
