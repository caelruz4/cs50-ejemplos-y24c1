#include <stdio.h>

// intercambiar valores
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;

    printf("Valores antes del intercambio: x = %d, y = %d\n", x, y);

    swap(&x, &y);
    printf("Valores despues del intercambio: x = %d, y = %d\n", x, y);

    return 0;
}
