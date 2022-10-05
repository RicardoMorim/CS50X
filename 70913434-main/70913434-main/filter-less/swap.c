#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 2;
    int y = 1;
    swap(&x, &y);
    printf("%i  %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}