#include <stdio.h>
#include <string.h>

struct fecha{
    int dia;
    int mes;
    int anno;
    char mesTexto[10];
};
typedef struct fecha tFecha;

int main()
{
    tFecha hoy;

    hoy.dia = 18;
    hoy.mes = 10;
    hoy.anno = 2019;
    strcpy(hoy.mesTexto, "Octube");

    printf("\nHoy: %i de %s de %i", hoy.dia, hoy.mesTexto, hoy.anno);

    hoy.mesTexto[5] = 'r';
    hoy.mesTexto[6] = 'e';
    hoy.mesTexto[7] = '\0';

    printf("\nHoy: %i de %s de %i", hoy.dia, hoy.mesTexto, hoy.anno);

    printf("\n\n");
    return 0;
}
