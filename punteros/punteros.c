#include <stdio.h>

int main(void)
{
    int a = 10;
    int *p = &a;
    printf("Variable a: %d -> %p\n", *p, p);

    // puntero a un puntero
    int **q = &p;
    printf("Dirección de p: %p\n", &p);
    printf("Valor de q (la dirección de p): %p\n", q);
    printf("Valor apuntado por q (*q): %p\n", *q);
    printf("Valor apuntado por *q (**q): %d\n", **q);

    return 0;
}
