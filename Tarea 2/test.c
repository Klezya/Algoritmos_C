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
    ArregloBool visitados = crearVisitados(cantNodos);

    /*Resto de funciones:
    
    
    
    
    
    */



    /*Dijkstra en cada nodo:
    imprimirMatriz(grafo, cantNodos);
    for (int i = 0; i < cantNodos; i++) {
        Dijkstra(grafo,cantNodos,i);
        printf("\n");
    }
    */
    
    /* Recorrido de amplitud:
    for (int i = 0; i < cantNodos; i++) {
        printf("\nRecorrido nodo %d :", i);
        imprimirAmplitud(grafo,cantNodos,visitados,i);
        printf("\n");
    }*/

    /* Recorrido profundidad todos los nodos:
    for (int i = 0; i < cantNodos; i++) {
        printf("Recorrido nodo %d:",i);
        imprimirProfundidad(grafo,visitados,cantNodos,i);
        resetearVisitados(visitados,cantNodos);
        printf("\n");
    }*/

    return 0;
}
