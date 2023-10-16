#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funciones.h"

int main()
{
    char nombreArchivo[50];
    Matriz Grafo;
    int n; //Cantidad de nodos
    int m; //Cantidad de arcos
    int tipo; //tipo de Grafo: 1 dirigido, 2 no dirigido.

    printf("Ingresa el nombre del primer archivo: ");
    scanf("%s", &nombreArchivo);
    Grafo = leeArchivo(nombreArchivo, &n, &m, &tipo);
    printf("\nMATRIZ DEL GRAFO: \n");
    imprimeMatrizGrafo(Grafo, n);

    printf("\n\n");
    return 0;
}
