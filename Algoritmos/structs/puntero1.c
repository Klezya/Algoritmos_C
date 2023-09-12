#include <stdio.h>

int main()
{
    int a;
    int *p;

    a = 137;
    printf("\nvariable a: %i", a);
    printf("\ndireccion de a: %p", &a);
    p = &a;
    printf("\nvariable p: %p", p);
    *p = 200;
    printf("\nvariable a: %i", a);

    printf("\n\n");
    return 0;
}
