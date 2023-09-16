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

    Lista L_union = unionLista(lista1,lista2);
    printf("\n\nInion listas: "); imprimirLista(L_union);
    printf("\nUnion ordenada: "); L_union = ordenarLista(L_union); imprimirLista(L_union);
    
    printf("\n");imprimirLista(lista1);printf("\n"); imprimirLista(lista2);

    Lista L_intersec = interseccionLista(lista1,lista2);
    printf("\n\nInterseccion listas: "); imprimirLista(L_intersec);
    printf("\nInterseccion ordenada: "); L_intersec = ordenarLista(L_intersec); imprimirLista(L_intersec);
    Lista L_resta = restaLista(lista1,lista2);
    printf("\n\nResta listas: "); imprimirLista(L_resta);
    printf("\nResta ordenada: "); L_resta = ordenarLista(L_resta); imprimirLista(L_resta);
    return 0;
}