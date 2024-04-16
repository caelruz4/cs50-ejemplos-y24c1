#include <stdio.h>

int main() {
    int arreglo[] = {10, 20, 30, 40, 50};
    int *p = arreglo; // p apunta al primer elemento del arreglo

    // Acceso al primer elemento del arreglo
    printf("Valor en la posición 0: %d\n", *p);

    p++;
    printf("Valor en la posición 1: %d\n", *p);

    p--;
    printf("Valor en la posición 0 nuevamente: %d\n", *p);

    // acceder a posición específica
    p = &arreglo[3];
    printf("Valor en la posición 3: %d\n", *p);

    return 0;
}
