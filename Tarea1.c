#include <stdio.h>
#include <stdlib.h>
#include "Tarea1Funciones.c"

int main(){
    char nombre_archivo[50];

    printf("Ingrese el nombre del primer archivo (sin extension): ");
    scanf("%s",nombre_archivo);
    Lista lista1 = leerArchivo(nombre_archivo);

    printf("Ingrese el nombre del segundo archivo (sin extension): ");
    scanf("%s",nombre_archivo);
    Lista lista2 = leerArchivo(nombre_archivo);

    printf("\n\nLista 1: ");
    imprimirLista(lista1);
    printf("\nEl largo es: %d", largoLista(lista1));
    printf("\nLa suma es: %d", sumaLista(lista1));
    printf("\nEl menor es: %d", menorLista(lista1));
    printf("\nEl mayor es: %d", mayorLista(lista1));
    printf("\nLista invertida: "); lista1 = invertirLista(lista1); imprimirLista(lista1);
    printf("\nLista ordenada: "); lista1 = ordenarLista(lista1); imprimirLista(lista1);

    printf("\n\nLista 2: ");
    imprimirLista(lista2);
    printf("\nEl largo es: %d", largoLista(lista2));
    printf("\nLa suma es: %d", sumaLista(lista2));
    printf("\nEl menor es: %d", menorLista(lista2));
    printf("\nEl mayor es: %d", mayorLista(lista2));
    printf("\nLista invertida: "); lista2 = invertirLista(lista2); imprimirLista(lista2);
    printf("\nLista ordenada: "); lista2 = ordenarLista(lista2); imprimirLista(lista2);

    Lista listaunida = unionLista(lista1,lista2);
    printf("\n\nInion listas: "); imprimirLista(listaunida);
    printf("\nUnion ordenada: "); listaunida = ordenarLista(listaunida); imprimirLista(listaunida);
    listaunida = interseccionLista(lista1,lista2);
    printf("\n\nInterseccion listas: "); imprimirLista(listaunida);
    printf("\nInterseccion ordenada: "); listaunida = ordenarLista(listaunida); imprimirLista(listaunida);
    listaunida = restaLista(lista1,lista2);
    printf("\n\nResta listas: "); imprimirLista(listaunida);
    printf("\nResta ordenada: "); listaunida = ordenarLista(listaunida); imprimirLista(listaunida);

}