#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "funtest.h"

int main() {
    char nombreArchivo[50];
    int cantNodos, cantArcos, tipoGrafo; 

    printf("Ingrese el nombre del archivo:  ");
    scanf("%s", &nombreArchivo);
    printf("\n");
    Matriz grafo = leerArchivo(nombreArchivo, &cantNodos, &cantArcos, &tipoGrafo);
    imprimirMatriz(grafo,cantNodos);
    arcoMayorCosto(grafo, cantNodos);
    return 0;
}
