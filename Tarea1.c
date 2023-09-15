#include <stdio.h>
#include <stdlib.h>
#include "Tarea1Funciones.c"

int main(){
    char nombre_archivo[50];

    printf("Ingrese el nombre del archivo (sin extension): ");
    scanf("%s",nombre_archivo);
    Lista lista1 = leerArchivo(nombre_archivo);

    imprimirLista(lista1);
    printf("\nEl largo de la lista es: %d\n", largoLista(lista1));
    printf("La suma de la lista es: %d\n", sumaLista(lista1));
    printf("El menor de la lista es: %d\n", menorLista(lista1));
    printf("El mayor de la lista es: %d\n", mayorLista(lista1));
    Lista lista2 = invertirLista(lista1);
    imprimirLista(lista2);
    return 0;
}