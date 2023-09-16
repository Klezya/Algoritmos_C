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
    
    Lista L_intersec = interseccionLista(lista1,lista2);
    printf("\n\nInterseccion listas: "); imprimirLista(L_intersec);
    printf("\nInterseccion ordenada: "); L_intersec = ordenarLista(L_intersec); imprimirLista(L_intersec);
    Lista L_resta = restaLista(lista1,lista2);
    printf("\n\nResta listas1: "); imprimirLista(L_resta);
    printf("\nResta ordenada: "); L_resta = ordenarLista(L_resta); imprimirLista(L_resta);

    printf("\n\nListas borrada:");
    lista1 = borraLista(lista1); lista2 = borraLista(lista2); L_union = borraLista(L_union); L_intersec = borraLista(L_intersec); L_resta = borraLista(L_resta);
    printf("\nLista 1: "); imprimirLista(lista1); printf("\nLista 2: "); imprimirLista(lista2); printf("\nUnion: "); imprimirLista(L_union); 
    printf("\nInterseccion: ");imprimirLista(L_intersec); printf("\nResta: "); imprimirLista(L_resta);
    return 0;
}